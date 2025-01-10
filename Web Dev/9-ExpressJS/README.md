app.get('/greet', (req, res) => {
    let person = 'Guest';
    // http://localhost:4444/greet?person=Haseeb
    if(req.query.person)   
        person = req.query.person
    res.send("Hi " + person);
});

In Express.js, req (request) and res (response) are two key objects used to handle HTTP requests and send responses back to the client.

## Understanding req (Request) and res (Response)

### req (Request): Represents the incoming HTTP request.
Contains information about the request, such as:
Query Parameters: Data sent in the URL after the ? (e.g., /greet?person=Haseeb).
Route Parameters: Data embedded in the URL path (e.g., /greet/:id).
Body: Data sent in the request body (e.g., POST requests).
Headers: Metadata about the request.
Method: The HTTP method used (GET, POST, etc.).

### res (Response): Represents the HTTP response that the server sends back to the client.
Contains methods to:
Send Data: Use res.send() or res.json() to send a response.
Set Headers: Use res.set() to set custom headers.
Set Status Codes: Use res.status() to set HTTP status codes.