// npm init : a command used in Node.js to initialize a new Node.js project by creating a package.json file. 
// package.json - This file is essential for managing the project’s metadata, dependencies, scripts, and configurations.
// npm i express
// main file - app.js

const express = require('express');
const app = express(); // we get an instance of server
app.use(express.urlencoded({ extended: true })); // Middleware provided by Express.js to parse incoming requests with URL-encoded payloads

// console.log(express);
// console.log(typeof(express));

app.get('/', (req, res) => { // here the callback is called the middleware
    res.send("Hi!");
});

app.get('/greet', (req, res) => { // server listens for GET requests sent to /greet
    // req n res - req (request) and res (response) are two key objects used to handle HTTP requests 
    // and send responses back to the client
    // req - Represents the incoming HTTP request
    // res - Represents the HTTP response that the server sends back to the client
    let person = 'Guest';
    // http://localhost:4444/greet?person=Haseeb
    if(req.query.person)   
        person = req.query.person
    res.send("GET - Hi " + person); // Sends a response back to the client.
});

app.post('/greet', (req, res) => {
    let person = 'Guest';
    if(req.body.person)
        person = req.body.person;
    res.send("POST - Good Morning " + person);
}); 

// render HTML File
app.get('/form', (req, res) => {
    res.sendFile(__dirname + '/form.html');
});

// URL Path parameters - can get overwritten so use carefully
app.get('/:city/:state', (req, res) => {
    res.send("Welcome to " + req.params.city + ', ' + req.params.state + '!');
})

app.listen(4444, () => { 
    // starts server on a certain port 
    console.log('Server Started at http://localhost:4444');
});
