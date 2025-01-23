const route = require('express').Router();
const db = require('../controllers/db');

route.get('/students', (req, res) => {
    db.showData()
        .then((students) => res.send(students))
        .catch((err) => res.send(err))
});

route.post('/students', (req, res) => {
    db.addData(req.body.id, req.body.name, req.body.age, req.body.notes)
        .then(res.redirect('/api/students'))
        .catch((err) => res.send(err));
});

exports = module.exports = {
    route
}