const { query } = require("express");
const express = require("express");
const app = express();
const port = 3000;
const PARTICIPANT = 0;
const ADMIN = 1;
const OWNER = 2;

app.use(express.json());
app.use(express.static(__dirname + '/public'));

app.get("/", (req, res) => {
	res.sendFile("/Users/davidszklarzewski/Desktop/Transcendence/index.html");
});

app.post("/select", async (req, res) => {
	await on_select(me, req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/block", async (req, res) => {
	await block(me, req.body.value);
	console.log('blocked ' + req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/unblock", async (req, res) => {
	await unblock(me, req.body.value);
	console.log('unblocked ' + req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/message", async (req, res) => {
	await send_dm(me, req.body.value);
	console.log("new message= " + req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/add_friend", async (req, res) => {
	console.log(req.body.value);
	await add_friend(me, req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/rm_friend", async (req, res) => {
	console.log(req.body.value);
	await rm_friend(me, req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/create_group", async (req, res) => {
	let group = new Group(req.body);
	group.owner = me.id;
	group.participants = me.id;
	console.log(group);
	await create_group(me, group);
	me.show();
	res.status(200).send();
})

app.post("/add_user_group", async (req, res) => {
	await add_user_group(me, me.selected_room, req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/group_message", async (req, res) => {
	await send_group_msg(me, req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/mute_user_group", async (req, res) => {
	await mute_user(me, me.selected_room, req.body.value, 2);
	me.show();
	res.status(200).send();
})

app.post("/unmute_user_group", async (req, res) => {
	await unmute_user(me, me.selected_room, req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/rm_user_group", async (req, res) => {
	await rm_user_group(me, me.selected_room, req.body.value, 2);
	me.show();
	res.status(200).send();
})

app.post("/promote_user_group", async (req, res) => {
	await add_admin_group(me, me.selected_room, req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/demote_user_group", async (req, res) => {
	await rm_admin_group(me, me.selected_room, req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/rm_group", async (req, res) => {
	console.log(req.body);
	await rm_group(me, req.body.value);
	me.show();
	res.status(200).send();
})

app.post("/test", async (req, res) => {
	console.log(req.body.value);
	await test();
	console.log('test done');
	res.send(me.conversations);
})

app.listen(port, () => {
	console.log("listening on port 3000");
});

//POSTGRES
const pg = require('pg');
const { Pool } = require('pg')

const credentials = {
  user: "postgres",
  host: "localhost",
  database: "chat",
  password: "",
  port: 5432,
  max: 1000
};

const pool = new Pool(credentials);
pool.on('error', (err, client) => {
    console.error('Error:', err);
});
pool.connect();

//SESSION
class Session {
	constructor() {
		this.id = 1;
		this.username = "dszklarz";
		this.conversations = [];
		this.blocked = [];
		this.selected_room = 0;
		this.messages = [];
	}
	show() {
		console.log("CONVERSATIONS======");
		console.log(this.conversations);
		console.log("BLOCKED============");
		console.log(this.blocked);
		console.log("MESSAGES===========");
		console.log(this.messages);
		console.log("SELECTED===========");
		console.log(this.selected_room);
		console.log("END================");
	}
}

class Conversation {
	constructor() {
		this.id = 0;
		this.name = "";
		this.participants = [];
		this.status = false;
	}
}

class Group {
	constructor(obj) {
		this.name = obj.name;
		this.owner = obj.owner;
		this.private = obj.private == "on" ? true : false;
		this.password = obj.password;
		this.participants = obj.participants;
	}
}

const me = new Session();

//FUNCTIONS

async function test(me) {
	on_select(me, 14);
	console.log("select 1 "+ me.selected_room);
	me.show();
	console.log("select 2 "+ me.selected_room);
	await pool.query(`INSERT INTO message (user_id, room_id, message, timestamp) VALUES(1, 14, 'coucou', NOW()::timestamptz(3))`);
	console.log("select 3 "+ me.selected_room);
	await refresh(me);
	console.log("select 4 "+ me.selected_room);
	me.show();
}

async function on_select(me, id) {
	me.selected_room = id;
	me.messages = [];
	await get_message(me);
}

async function get_convs(me) {
	room_query = await pool.query(`SELECT id, name, owner FROM room WHERE id in (SELECT room_id FROM participants WHERE user_id = ${me.id}) ORDER BY activity DESC`);
	me.conversations = [];
	for (i = 0; i < room_query.rowCount; i++) //for every conversation
	{
		room_row = room_query.rows[i];
		room_id = room_row.id;
		part_q = await pool.query(`SELECT user_id FROM participants WHERE room_id = ${room_row.id}`);
		if (!my_query.owner && !part_q.rowCount)
			continue;
		my_status = await pool.query(`SELECT status FROM chat_user WHERE id= ${part_q.rows[0].user_id}`);
		tmp = new Conversation();
		tmp.id		= room_id;
		tmp.name	= room_row.name;
		tmp.status	= my_status.rows[0].status;
		for (n = 0; n < part_q.rowCount; n++)				//get all participants of a given conversation
			tmp.participants.push(part_q.rows[n].user_id);
		me.conversations.push(tmp);
		//console.log('participants in room ' + my_query.rows[i]["id"] + " " + tmp.participants);
	}
}

async function get_blocked(me) {
	my_query = await pool.query(`SELECT blocked_id FROM blocked WHERE user_id=${me.id} UNION SELECT user_id FROM blocked WHERE blocked_id=${me.id}`);
	me.blocked = [];
	for (i = 0; i < my_query.rowCount; i++)
		me.blocked.push(my_query.rows[i].blocked_id);
}

async function get_message(me) {
	let last_time;
	if (me.messages.length > 0)
	{
		last_time = new Date(me.messages[0].timestamp).getTime() / 1000;
		console.log("last_time = " + last_time);
		my_query = await pool.query(`SELECT id, user_id, message, timestamp FROM message WHERE room_id = ${me.selected_room} AND timestamp > to_timestamp(${last_time}) AND user_id NOT IN (SELECT blocked_id FROM blocked WHERE user_id= ${me.id}) ORDER BY timestamp DESC`);
		for ( i = 0; i < my_query.rowCount; i++)
			console.log(my_query.rows[i]);
	}
	else
		my_query = await pool.query(`SELECT id, user_id, message, timestamp FROM message WHERE room_id = ${me.selected_room} AND user_id NOT IN (SELECT blocked_id FROM blocked WHERE user_id= ${me.id}) ORDER BY timestamp DESC`);
	for (i = 0; i < my_query.rowCount; i++)
		me.messages.push(my_query.rows[i]);
}

async function on_connect(me) {
	my_query = await pool.query(`SELECT id from chat_user WHERE name='${me.username}'`);
	if (my_query.rowCount === 1)
		me.id = my_query.rows[0].id;
	pool.query(`UPDATE chat_user SET status=true WHERE id=${me.id}`);
	await get_blocked(me);
	await get_convs(me);
	if (me.conversations.length)
		me.selected_room = me.conversations[0].id;
	await get_message(me);
	//await test(me);
}

async function refresh(me) {
	//console.log('blocked');
	await get_blocked(me);
	//console.log('convs');
	await get_convs(me);
	//console.log('message');
	await get_message(me);
}

async function send_dm(me, message) {
	await pool.query(`INSERT INTO message(user_id, timestamp, message, room_id) VALUES(${me.id}, NOW(), '${message}', ${me.selected_room})`)
	await get_message(me);
}

async function send_group_msg(me, message) {
	tmp = await pool.query(`SELECT banned_id, unban FROM banned WHERE room_id= ${me.selected_room} AND mute=true AND banned_id=${me.id}`);
	now = await pool.query(`SELECT NOW()`);
	if (tmp.rowCount)
	{
		if (tmp.rows[0].unban < now.rows[0].now)
			await pool.query(`DELETE FROM banned WHERE banned_id=${me.id} AND mute=true AND room_id=${me.selected_room}`);
		else
			return console.log("you are still muted");
	}
	await pool.query(`INSERT INTO message(user_id, timestamp, message, room_id) VALUES(${me.id}, NOW(), '${message}', ${me.selected_room})`);
	await pool.query(`UPDATE room SET activity=NOW() WHERE id=${me.selected_room}`);
	await refresh(me);
}

async function block(me, block_id) {
	await pool.query(`INSERT INTO blocked(user_id, blocked_id) VALUES(${me.id}, ${block_id})`);
	await refresh(me);
	await on_select(me, me.conversations.length ? me.conversations[0].id : 0); //if you have any conversation left after you block current conversation go to first one, else show no conv
	await refresh(me);
}

async function unblock(me, block_id) {
	await pool.query(`DELETE FROM blocked WHERE blocked_id=${block_id} and user_id=${me.id}`);
	await refresh(me);
}

async function available_friends(me) {
	my_query = await pool.query(`SELECT id from chat_user where id not in (select user_id from participants where room_id in (select room_id from participants where user_id =${me.id} AND room_id not in (select id from room where not owner=0))) AND NOT id IN (SELECT blocked_id FROM blocked WHERE user_id=${me.id} ) AND NOT id=${me.id}`);
	available = [];
	for (i = 0; i < my_query.rowCount; i++)
		available.push(my_query.rows[0].id);
	return available;
}

async function available_groups(me) {
	my_query = await pool.query(`SELECT id FROM room WHERE owner > 0 AND id NOT IN (SELECT room_id FROM participants WHERE user_id= ${me.id}) AND private=false`);
	available = [];
	for (i = 0; i < my_query.rowCount; i++)
		available.push(my_query.rows[0].id);
	return available;
}

async function add_friend(me, friend_id) {
	if (me.blocked.includes(friend_id))
		return await unblock(me, friend_id);
	tmp = await pool.query(`SELECT name FROM chat_user WHERE id= ${friend_id}`);
	username = tmp.rows[0].name;
			
	await pool.query(`INSERT INTO room(name) VALUES('${me.username}-${username}');`);
	new_room	= await pool.query(`SELECT id from room WHERE name = '${me.username}-${username}'`);
	new_room_id	= new_room.rows[0].id;
	await pool.query(`INSERT INTO participants (user_id, room_id) VALUES(${me.id}, ${new_room_id})`);
	await pool.query(`INSERT INTO participants (user_id, room_id) VALUES(${friend_id}, ${new_room_id})`);
	await on_select(me, new_room_id)
	//refresh is in the calling function ( add_conv() )
}

async function rm_friend(me, friend_id) {
	tmp = await pool.query(`SELECT room_id FROM participants WHERE room_id in (SELECT room_id FROM participants WHERE user_id = ${friend_id}) AND user_id =${me.id} AND room_id NOT IN (SELECT id FROM room WHERE NOT owner=0)`)
	friend_room = tmp.rows[0].room_id;
	if (!tmp.rowCount)
		return console.log(`no conversation between ${me.id} and ${friend_id} in rm_friend`);
	await pool.query(`DELETE FROM message WHERE room_id= ${friend_room}`);
	await pool.query(`DELETE FROM participants WHERE room_id = ${friend_room}`);
	await pool.query(`DELETE FROM room WHERE id= ${friend_room}`);
	await on_select(me, me.conversations.length ? me.conversations[0].id : 0);
	await refresh(me);
}

async function create_group(me, group) {
	try {
		await pool.query(`INSERT INTO room (name, owner, private, password, activity) VALUES('${group.name}', ${me.id}, ${group.private}, crypt('${group.password}', gen_salt('bf')), NOW())`);
	}
	catch {
		return console.log('group name already exists');
	}
	tmp = await pool.query(`SELECT id FROM room WHERE name='${group.name}'`);
	room_id = tmp.rows[0].id;
	for (i = 0; i < group.participants.length; i++)
		await pool.query(`INSERT INTO participants(user_id, room_id) VALUES(${group.participants[i]}, ${room_id})`);
	await refresh(me);
}

async function set_password(me, room_id, password) {
	if (await get_role(me.id, room_id) == OWNER)
		await pool.query(`UPDATE room SET password=crypt('${password}', gen_salt('bf')) WHERE id=${room_id}`);
	await refresh(me);
}

async function set_private(me, room_id, cond) { //condition true = private false = public
	if (await get_role(me.id, room_id) == OWNER)
		await pool.query(`UPDATE room SET private=${cond} WHERE id=${room_id}`);
	await refresh(me);
}

async function rm_group(me, room_id) {
	if (await get_role(me.id, room_id) != OWNER)
		return;
	await pool.query(`DELETE FROM message WHERE id=${room_id}`);
	await pool.query(`DELETE FROM participants WHERE room_id=${room_id}`);
	await pool.query(`DELETE FROM admins WHERE room_id=${room_id}`);
	await pool.query(`DELETE FROM room WHERE id=${room_id}`);
	await refresh(me);
}

async function add_user_group(me, room_id, user_id) {
	tmp = await pool.query(`SELECT role, banned_id FROM banned WHERE room_id=${room_id} AND banned_id=${user_id}`);
	if (!tmp.rowCount)
	{
		await pool.query(`INSERT INTO participants(user_id, room_id) VALUES(${user_id}, ${room_id})`);
		return await refresh(me);
	}
	role1 = await get_role(me.id, room_id);
	role2 = tmp.rows[0].role;
	if (role1 >= role2 /* && role1 >= ADMIN */)  //option for who can invite into group
		await pool.query(`INSERT INTO participants(user_id, room_id) VALUES(${user_id}, ${room_id})`);
	await refresh(me);
}

//needs a drop-down menu to chose length of ban, either fixed or input but then check for negatives, 0 means just kick from group
async function rm_user_group(me, room_id, user_id, unban_hours) {
	role1 = await get_role(me.id, room_id);
	role2 = await get_role(user_id, room_id);
	if (role1 < ADMIN || role1 <= role2)
		return;

	let unban_date = new Date;
	if (unban_hours)
		unban_date.setHours(unban_date.getHours() + unban_hours);
	else
		unban_date = "NOW()";

	await pool.query(`DELETE FROM message WHERE user_id=${user_id} AND room_id=${room_id}`);	//delete messages (option)
	await pool.query(`DELETE FROM participants WHERE user_id=${user_id} AND room_id=${room_id}`);
	await pool.query(`DELETE FROM banned WHERE banned_id=${user_id} AND room_id=${room_id} AND mute=true`);
	await pool.query(`INSERT INTO banned (user_id, banned_id, room_id, unban, mute, role) VALUES(${me.id}, ${user_id}, ${room_id}, to_timestamp(${unban_date.getTime() / 1000}), false, ${role1})`);
	await refresh(me);
}

async function add_admin_group(me, room_id, user_id) {
	if (await get_role(me.id, room_id) == OWNER)
		await pool.query(`INSERT INTO admins(user_id, room_id) VALUES(${user_id}, ${room_id})`);
	await refresh(me);
}

async function rm_admin_group(me, room_id, user_id) {
	if (await get_role(me.id, room_id) == OWNER)
		await pool.query(`DELETE FROM admins WHERE user_id=${user_id} AND room_id=${room_id}`);
	await refresh(me);
}

async function mute_user(me, room_id, user_id, unban_hours) {
	role1 = await get_role(me.id, room_id);
	role2 = await get_role(user_id, room_id);
	if (role1 < ADMIN || role1 <= role2)
		return;
	
	unban_date = new Date;
	unban_date.setHours(unban_date.getHours() + unban_hours);

	await pool.query(`INSERT INTO banned (user_id, banned_id, room_id, unban, mute, role) VALUES(${me.id}, ${user_id}, ${room_id}, to_timestamp(${unban_date.getTime() / 1000}), true, ${role1})`);
	await refresh(me);
}

async function unmute_user(me, room_id, user_id) {
	role1 = await get_role(me.id, room_id);
	role2 = await get_role(user_id, room_id);
	if (role1 < ADMIN || role1 <= role2)
		return;
	await pool.query(`DELETE FROM banned WHERE banned_id= ${user_id} AND room_id= ${room_id}`);
	await refresh(me);
}

async function get_role(id, room_id) {
	tmp = await pool.query(`SELECT owner FROM room WHERE id=${room_id}`);
	if (tmp.rows[0].owner == id)
		return OWNER;
	tmp = await pool.query(`SELECT user_id FROM admins WHERE room_id=${room_id}`);
	if (tmp.rows.includes(id))
		return ADMIN;
	tmp = await pool.query(`SELECT user_id FROM participants WHERE room_id=${room_id}`);
	if (tmp.rows.includes(id))
		return PARTICIPANT;
	return -1;
}

async function join_group(me, name) {
	tmp = await pool.query(`SELECT id, password FROM room WHERE name=${name} AND private=false`);
	if (!tmp.rowCount)
		return console.log('cant join private group');
	room = tmp.rows[0];
	if (room.password.length)
		//provide password and compare SELECT crypt('provided_password', 'bf') with SELECT password FROM room WHERE id=${room.id};
	await pool.query(`INSERT INTO participants(user_id, room_id) VALUES(${me.id}, ${room.id})`);
	on_select(me, room.id);
}

on_connect(me);
//TO CHECK WITH THE OTHER DAVID
//1. what to do with private groups
//2. display 0 conversations

//OPTIONS
//1. Keep or Erase messages of a banned person in group (in rm_user_group)
//2. Who can invite into group ? (in add_user_group)1