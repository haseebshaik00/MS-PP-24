const { db, Professor } = require('./model');

const task = async () => {
    try{
        await db.sync({alter: true});
        // sql queries are written in the findAll() function
        // https://sequelize.org/docs/v6/core-concepts/model-querying-basics/
        const professors = await Professor.findAll();
        console.log(professors[0].dataValues);
    }
    catch(err){
        console.log(err);
    }
}

task();