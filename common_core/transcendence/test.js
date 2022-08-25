const { Pool } = require('pg');
const credentials = {
	user: "postgres",
	host: "localhost",
	database: "chat",
	password: "",
	port: 5432,
	max: 1000
  };
const pool = new Pool(credentials);
pool.connect();


async function get_time() {
	tmp = await pool.query(`SELECT timestamp FROM message WHERE id=2`);
	psql = tmp.rows[0].timestamp;
	date = new Date();
	console.log("DATE = " + date.getTime());
	console.log("DATE = " + date.getTime() / 1000);
	// tmp = await pool.query(`SELECT id, timestamp FROM message WHERE timestamp > to_timestamp(${date.getTime() / 1000})`);
	// for (i = 0; i < tmp.rowCount; i++)
	// 	console.log(tmp.rows[i]);
}

get_time();