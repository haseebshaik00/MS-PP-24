const mysql = require('mysql2');

const con = mysql.createConnection({
  host: "localhost",
  database: "testDB",
  user: "haseeb",
  password: "haseeb123"
});


con.query(`SELECT * FROM STUDENTS`,(err, rows, fields) => {
    if(err)
        console.log(err);
    else{
        console.log(rows);
        console.log(fields);
        con.close();
    }
});