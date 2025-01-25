import Sequelize from 'sequelize';

const db = new Sequelize('testDB', 'haseeb', 'haseeb123', {
    host: 'localhost',
    dialect: 'mysql'
});

db.authenticate()
    .then(() => {console.log("Connection has been established!")})
    .catch((err) => {console.log("Unable to connect!", err)});