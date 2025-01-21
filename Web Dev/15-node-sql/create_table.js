const mysql = require('mysql2');

const con = mysql.createConnection({
  host: "localhost",
  database: "testDB",
  user: "haseeb",
  password: "haseeb123"
});


con.query(`CREATE TABLE IF NOT EXISTS Graduates
    (ID INTEGER PRIMARY KEY, NAME VARCHAR(50), AGE INTEGER NOT NULL, Notes VARCHAR(50))`,(err, result) => {
    if(err)
        console.log(err);
    else{
        console.log("Table Created!"); // DB can only be created when the user has right access
        con.close();
    }
});