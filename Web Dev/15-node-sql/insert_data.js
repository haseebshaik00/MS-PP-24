const mysql = require('mysql2');

const con = mysql.createConnection({
  host: "localhost",
  database: "testDB",
  user: "haseeb",
  password: "haseeb123"
});


con.query(`INSERT INTO students values(4, "Adam", 25, "Man")`, (err, result) => {
    if(err)
        console.log(err);
    else{
        console.log("Row Added!");
        con.close();
    }
});