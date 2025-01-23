const express = require('express');
const app = express();
const todoRoute = require('./routes/todos');

app.set('view engine', 'hbs');
app.set('views', __dirname + '/views');

app.use(express.json());
app.use(express.urlencoded({extended: true}));
app.use('/public', express.static(__dirname + '/public'));
app.use('/todos', todoRoute);

app.get('/', (req, res) => {
    res.send("Hi!");
});

app.listen(4441, () => {
    console.log("Server started at http://localhost:4441");
});

/*
    - Frontend contains the todos.html file
    - task added on frontend
    - task sent to server with task name
    - task added in array of tasks on server side
    - whole tasks array is sent back
    - On frontend again through the whole tasks array the list is rendered
    
    Frontend and backend is seperate here.
*/
