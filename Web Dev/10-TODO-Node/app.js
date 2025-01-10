const express = require('express');
const app = express();
app.use(express.urlencoded({ extended: true }));

let tasks = [
    'first task'
];

app.post('/', (req, res) => {
    tasks.push(req.body.person);
    res.redirect('/'); // redirects to the given path - get request
});

app.get('/', (req, res) => {
    tasksList = tasks.map((task) => `<li>${task}</li>`).join('\n');
    res.send(
        `
        <html>
            <body>
                <form action="/" method="post">
                    <input type="text" name="person" />
                    <button type="submit">SUBMIT</button>
                    ${tasksList}
                </form>
            </body>
        </html>
        `
    );
});

app.listen('4444', (req, res) => {
    console.log("Server Started!");
})