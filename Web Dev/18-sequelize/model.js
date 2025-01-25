const { Sequelize, DataTypes } = require('sequelize');

const db = new Sequelize('testDB', 'haseeb', 'haseeb123', {
    host: 'localhost',
    dialect: 'mysql'
});

const Professor = db.define('Professors',{
      firstName: {
        type: DataTypes.STRING,
        allowNull: false,
      },
      age: {
        type: DataTypes.INTEGER,
        allowNull: false,
        default: 25
      },
});

console.log(Professor === db.models.Professors);

db.sync({alter: true})
    .then(() => {console.log("DB Synchronized!")})
    .catch((err) => {console.log("Error: ", err)});

// The sync() method is primarily used to ensure that the database schema matches the model definitions in your code.
// Once your schema is set up and synchronized, you can directly perform operations like create, findOne, update, or destroy without calling sync() again.

module.exports = {
  db, Professor
}
