const express = require('express');
const app = express();
const db = require('./db');

app.set('view engine', 'hbs');
app.set('views', __dirname + '/views');

app.use(express.json());
app.use(express.urlencoded({extended : true}));
app.use("/public", express.static(__dirname + "/public"));

app.get('/add', (req, res) => {
    res.render('students_add');
});

app.post('/add', (req, res) => {
    db.addData(req.body.id, req.body.name, req.body.age, req.body.notes)
        .then(res.redirect('/'))
        .catch((err) => res.send(err));
});

app.get('/', (req, res) => {
    db.showData()
        .then((students) => res.render('students', {students}))
        .catch((err) => res.send(err))
});

app.listen(4442, () => {
    console.log("Server started at http://localhost:4442");
})