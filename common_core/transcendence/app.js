class Conversation {
	constructor() {
		this.id = 0;
		this.name = "";
		this.participants = [];
	}
}

async function get_convs(me) {
	my_query = await client.query(`SELECT id,name,owner FROM room WHERE id in (SELECT room_id FROM participants WHERE user_id = ${me.id}) ORDER BY activity DESC`);
	me.conversations = [];
	for (i = 0; i < my_query.rowCount; i++)
	{
		tmp = await client.query(`SELECT user_id FROM participants WHERE room_id =${my_query.rows[i]["id"]} and not user_id=${me.id}`)
		if (tmp.rowCount && !my_query.rows[i].owner && me.blocked.includes(tmp.rows[0].user_id))
			continue;
		tmp = new Conversation();
		tmp.id	 = my_query.rows[i]["id"];
		tmp.name = my_query.rows[i]["name"];
		my_query2 = await client.query(`SELECT user_id FROM participants WHERE room_id = ${my_query.rows[i]["id"]} and not user_id= ${me.id}`);
		for (n = 0; n < my_query2.rowCount; n++)
			tmp.participants.push(my_query2.rows[n]["user_id"]);
		console.log('participants in room ' + my_query.rows[i]["id"] + " " + tmp.participants);
		me.conversations.push(tmp);
	}
}

async function get_blocked(me) {
	my_query = await client.query(`SELECT blocked_id FROM blocked WHERE user_id=${me.id} UNION SELECT user_id FROM blocked WHERE blocked_id=${me.id}`);
	me.blocked = [];
	for (i = 0; i < my_query.rowCount; i++)
		me.blocked.push(my_query.rows[i]["blocked_id"]);
}

async function get_message(me) {
	// console.log(messages);
	// if (messages.length)
	// {
	// 	last_time = messages[messages.length - 1]["timestamp"];
	// 	my_query = await client.query(`SELECT NOW()`);
	// 	console.log(my_query.rows[0]);
	// 	my_query = await client.query(`SELECT message, timestamp FROM message WHERE room_id = ${selected_room} AND timestamp > to_timestamp(${last_time}) ORDER BY timestamp DESC`);
	// }
	// else
	my_query = await client.query(`SELECT id, message, timestamp FROM message WHERE room_id = ${me.selected_room} ORDER BY timestamp DESC`);
	me.messages = [];
	for (i = 0; i < my_query.rowCount; i++)
		me.messages.push(my_query.rows[i]);
}

async function on_connect(me) {
	my_query = await client.query(`SELECT id from chat_user WHERE name='${me.username}'`);
	if (my_query.rowCount === 1)
		me.id = my_query.rows[0]["id"];
	client.query(`UPDATE chat_user SET status=true WHERE id=${me.id}`);
	await get_blocked(me);
	await get_convs(me);
	if (me.conversations.length)
		me.selected_room = me.conversations[0].id;
	await get_message(me);
}

async function refresh(me) {
	tmp = await get_blocked(me);
	blocked = tmp;
	tmp = await get_convs(me);
	conversations = tmp;
	tmp = await get_message(me);
	messages = tmp;
}

async function on_dm_click(room_id) {
	selected_room = room_id;
	refresh(me);
}

async function send_dm(me, message) {
	if (me.blocked.includes(me.selected_room))
		throw "my_id blocked from this conversation";
	await client.query(`INSERT INTO message(user_id, timestamp, message, room_id) VALUES(${me.id}, NOW(), '${message}', ${me.selected_room})`)
	get_messages(me);
}

async function erase_dm(me, message_id) {
	if (me.blocked.includes(me.selected_room))
		throw "my_id blocked from this conversation";
	await client.query(`DELETE FROM message WHERE id=${message_id}`)
	get_message(me);
}

async function block(me, block_id) {
	await client.query(`INSERT INTO blocked(user_id, blocked_id) VALUES(${me.id}, ${block_id})`);
	await refresh(me);
	if (me.conversations.length)
		selected_room = me.conversations[0].id;
	else
		selected_room = 0;
}

async function unblock(me, block_id) {
	await client.query(`DELETE FROM blocked WHERE blocked_id=${block_id} and user_id=${me.id}`);
	await refresh(me);
}

async function add_friend(username, me) {
	tmp = await client.query(`SELECT id FROM chat_user WHERE name= '${username}'`);
	if (!tmp.rowCount)
		console.log("user not found");
	my_query = await client.query(`SELECT id FROM chat_user WHERE id NOT IN (SELECT user_id FROM participants WHERE room_id IN (SELECT room_id FROM participants WHERE user_id = ${me.id}))`);
	available = [];
	for (i = 0; i < my_query.rowCount; i++)
		if (!blocked.includes(my_query.rows[0].id))
			available.push(my_query.rows[0].id);
			
	tmp2 = await client.query(`INSERT INTO room(name) VALUES('${my_username}-${username}');`);
	new_room = await client.query(`SELECT id from room WHERE name = '${my_username}-${username}'`);
	new_room_id = new_room_id.rows[0]["id"];
	tmp2 = await client.query(`INSERT INTO participants (user_id, room_id) VALUES(${my_id}, ${new_room_id})`);
	tmp2 = await client.query(`INSERT INTO participants (user_id, room_id) VALUES(${tmp.rows[0]["id"]}, ${new_room_id})`);
	await refresh(me);
}

async function remove_friend(username, me) {
	await client.query(`DELETE FROM message WHERE room_id= ${me.room_id}`);
	await client.query(`DELETE FROM participants WHERE room_id = ${me.room_id}`);
	await client.query(`DELETE FROM room WHERE id= ${me.room_id}`);
	refresh(me);
}

function disconnect(me)
{
	client.query(`UPDATE chat_user SET status=false WHERE id=${me.id}`)
}


const sleep = (milliseconds) => {
	return new Promise(resolve => setTimeout(resolve, milliseconds))
  }

async function run() {
	await on_connect(me);
	me.show();
	await add_friend('rcammaro');
	//me.show();
	// await block(me, 2);
	// me.show();
	// await unblock(me, 2);
	// me.show();
}

// async function test() {
// 	query1 = await client.query(`SELECT timestamp FROM message WHERE id = 1`);
// 	stamp_in_js = query1.rows[0]['timestamp'];
// 	console.log(stamp_in_js);
// 	query2 = await client.query(`SELECT message FROM message WHERE timestamp= to_timestamp('${stamp_in_js}')`);
// }
//test();
//run();