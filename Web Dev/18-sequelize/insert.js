const { db, Professor } = require('./model');

const task = async () => {
    try{
        await db.sync({alter: true});
        await Professor.create({
            firstName: 'Haseeb',
            age: 24
        })
    }
    catch(err){
        console.log(err);
    }
}
task();
