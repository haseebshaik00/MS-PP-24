const express = require('express');
const app = express();

app.set('view engine', 'hbs');
app.set('views', __dirname + '../public/views');

app.use(express.json());
app.use(express.urlencoded({ extended : true}));
app.use("/xyz", express.static(__dirname + "/public"));
// app.use("/todo", todoRoute);

app.get('/', (req, res) => {
    res.send("Hi!");
});

app.listen('4444', () => console.log("Server started on http://localhost:4444"));