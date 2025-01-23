const mysql2 = require('mysql2');

const con = mysql2.createConnection({
  host: "localhost",
  database: "testDB",
  user: "haseeb",
  password: "haseeb123"
});

const showData = () => {
    return new Promise((resolve, reject) => {
        con.query(`SELECT * FROM students`, (err, rows, cols) => {
            if(err)
                reject(err);
            else
                resolve(rows);
        });
    });
}

const addData = (id, name, age, notes) => {
    return new Promise((resolve, reject) => {
        con.query(`INSERT INTO students VALUES(?,?,?,?)`, [id, name, age, notes], (err, rows) => {
            if(err)
                reject(err);
            else
                resolve();
        });
    });
}

exports = module.exports = {
    addData, showData
};