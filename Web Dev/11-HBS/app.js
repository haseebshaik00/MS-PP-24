const express = require('express');
const app = express();

app.use(express.urlencoded({ extended: true }));
app.set('view engine', 'hbs');

let tasks = [
    'first task'
];

app.post('/', (req, res) => {
    tasks.push(req.body.person);
    res.redirect('/'); // redirects to the given path - get request
});

app.get('/', (req, res) => {
    res.render(__dirname + '/views/home', {
        title: 'TODO List', 
        tasks
    });
});

app.listen('4444', (req, res) => {
    console.log("Server Started!");
})