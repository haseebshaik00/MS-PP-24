const express = require('express');
const app = express();

app.use(express.json()); // to parse json
app.use(express.urlencoded({extended : true}));
app.set('view engine', 'hbs'); // setting view engine as hbs
app.set('views', __dirname + '/views'); // setting the views directory
app.use("/public", express.static(__dirname + "/public")); // setting the public folder
// app.use("/todo", todoRoute); // for routing purpose

// Middlewares
function m1(req, res, next){
    console.log("Running Middleware M1");
    next();
}

function m2(req, res, next){
    console.log("Running Middleware M2");
    next();
}

app.get('/', m1, m2, (req, res) => {
    res.send("Home Page");
});

app.listen('4445', (req, res) => {
    console.log("Server running at http://localhost:4445");
});