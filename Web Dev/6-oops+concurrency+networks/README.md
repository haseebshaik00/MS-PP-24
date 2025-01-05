# Multitasking in JS

JavaScript is single-threaded by nature, meaning it executes code sequentially within a single thread. However, it has mechanisms like asynchronous programming and a non-blocking event loop that allow it to handle tasks concurrently, giving the appearance of multitasking.

## JavaScript uses the event loop to manage asynchronous tasks.
JavaScript is primarily sequential in its execution model but can handle concurrent-like behavior through its event-driven architecture.

The event loop is a core mechanism in JavaScript that allows it to handle asynchronous operations and execute code in a non-blocking way, even though JavaScript itself is single-threaded. It ensures that the program can continue executing other code while waiting for asynchronous tasks like timers, network requests, or file operations to complete.

1. Sequential Nature of JavaScript
JavaScript is inherently single-threaded, meaning it has a single execution context and processes tasks one at a time on the call stack. This means that synchronous code executes in the exact order it appears.

console.log("Task 1");
console.log("Task 2");
console.log("Task 3");
- output 
Task 1
Task 2
Task 3

2. The Problem with Long-Running Tasks
If you introduce a long-running task (like an intensive computation or I/O operation) in synchronous code, it can block the thread and prevent subsequent tasks from executing.

console.log("Start");

function longTask() {
  const end = Date.now() + 5000; // 5 seconds
  while (Date.now() < end) {}
}

longTask(); // Blocks the thread
console.log("End");

- output
Start
End (after 5 seconds)
During the 5 seconds that longTask runs, the thread is blocked, and no other code executes.

3. Asynchronous Nature and Event Loop
To handle tasks like I/O or timers without blocking the thread, JavaScript relies on asynchronous programming and the event loop.

Components:
Call Stack: Executes code sequentially.
Web APIs / Background Threads: Handles asynchronous tasks (e.g., timers, HTTP requests).
Task Queue (Macro Task Queue): Stores callbacks for tasks like setTimeout.
Microtask Queue: Prioritized queue for Promise resolutions and process.nextTick.
How the Event Loop Works:
Executes tasks from the call stack.
When the call stack is empty, the event loop dequeues tasks from the microtask queue first, then from the task queue, and pushes them onto the call stack.

4. Examples of Asynchronous Behavior
Example with setTimeout:
javascript
Copy code
console.log("Start");

setTimeout(() => {
  console.log("Timeout");
}, 1000);

console.log("End");
Output:

sql
Copy code
Start
End
Timeout
Explanation:

"Start" and "End" are logged immediately because they are synchronous.
setTimeout schedules the callback for later and doesn’t block the thread.
After 1 second, the callback is added to the task queue and executed once the call stack is clear.
Example with Promise:
javascript
Copy code
console.log("Start");

Promise.resolve().then(() => {
  console.log("Promise Resolved");
});

console.log("End");
Output:

sql
Copy code
Start
End
Promise Resolved
Explanation:

"Start" and "End" are logged sequentially.
The .then callback is added to the microtask queue, which is executed before tasks in the task queue.
5. Combining Synchronous and Asynchronous Code
Let’s combine all concepts to observe the sequential and concurrent behavior:

javascript
Copy code
console.log("Start");

setTimeout(() => {
  console.log("Timeout 1");
}, 0);

Promise.resolve().then(() => {
  console.log("Promise 1");
});

setTimeout(() => {
  console.log("Timeout 2");
}, 0);

Promise.resolve().then(() => {
  console.log("Promise 2");
});

console.log("End");
Output:

javascript
Copy code
Start
End
Promise 1
Promise 2
Timeout 1
Timeout 2
Explanation:

"Start" and "End" are synchronous and execute first.
Promises (Promise 1 and Promise 2) are added to the microtask queue and executed before any setTimeout callbacks.
setTimeout callbacks (Timeout 1 and Timeout 2) are added to the task queue and executed after the microtasks are completed.

6. Key Takeaways
Sequential execution: JavaScript executes synchronous tasks one at a time in the order they appear.
Concurrency: JavaScript uses the event loop to handle asynchronous tasks without blocking the main thread.
Priority: Microtasks (Promises) always execute before tasks in the task queue (e.g., setTimeout).
Non-blocking: Asynchronous programming ensures JavaScript can handle multiple tasks efficiently, even though it’s single-threaded.

Multi-threading
While the core JavaScript thread is single-threaded, environments like browsers and Node.js can leverage multiple threads for specific tasks (e.g., Web Workers or Worker Threads) to achieve true concurrency.

## JavaScript is Concurrent.
It is not sequential in the traditional sense because it uses an event-driven, non-blocking concurrency model. While JavaScript executes code on a single thread (making it seem sequential), it can handle multiple tasks concurrently through asynchronous programming and the event loop.

Key Explanation:
Single-Threaded Execution:

JavaScript runs on a single thread, executing one piece of code at a time.
This is why it’s often misunderstood as purely sequential.
Concurrency Through Asynchronous Operations:

JavaScript can handle multiple tasks simultaneously, even with its single-threaded nature. For example:
Handling network requests.
Responding to user input while waiting for a file to load.
Event Loop Mechanism:

The event loop manages concurrency by:
Executing synchronous code in order.
Delegating asynchronous tasks (e.g., I/O operations, timers) to the browser or Node.js environment.
Returning results (via callbacks, promises, etc.) to the call stack for processing once ready.
Not Parallelism:
JavaScript does not perform multiple tasks simultaneously on a single thread.
True parallelism requires multiple threads, which JavaScript supports through Web Workers.
How to Phrase It:
"JavaScript is single-threaded but concurrent. It uses the event loop to manage asynchronous tasks, enabling concurrency despite executing code sequentially within the thread."
You can add, "JavaScript achieves this by offloading tasks like I/O operations to the environment (browser or Node.js) and processing the results asynchronously."


## Callback 
A JavaScript callback is a function that is passed as an argument to another function and is executed after the completion of that function's task. Callbacks are essential for handling asynchronous operations, such as reading files, fetching data from APIs, or waiting for user interactions. They help ensure that certain actions are performed only once other tasks are completed. This pattern is commonly used in event handling, promises, and async functions to maintain efficient, non-blocking behavior in JavaScript applications.

function fetchData(callback) {
  setTimeout(() => {
    const data = "Data fetched!";
    callback(data); // calling the callback with the fetched data
  }, 2000); // simulate a 2-second delay
}

function displayData(data) {
  console.log(data); // display the fetched data
}

// Calling the fetchData function and passing displayData as the callback
fetchData(displayData);

In this example, fetchData simulates an asynchronous operation (e.g., fetching data) and calls displayData when the operation is complete.

## Promises
A Promise in JavaScript represents an operation that is not completed yet, but will be at some point in the future. It allows you to handle asynchronous code in a cleaner and more manageable way.

let myPromise = new Promise((resolve, reject) => {
  let success = true;
  if(success) {
    resolve("Operation was successful!");
  } else {
    reject("Something went wrong.");
  }
});

myPromise.then(response => {
  console.log(response);  // Operation was successful!
}).catch(error => {
  console.log(error);  // Something went wrong.
});
Here, resolve handles success, and reject handles errors.

## Async await

The async and await keywords in JavaScript simplify handling asynchronous operations by allowing you to write asynchronous code that looks and behaves like synchronous code.

async is used to declare a function that returns a promise.
await is used inside an async function to pause execution until a promise is resolved.

async function fetchData() {
  let data = await fetch('https://api.example.com');
  let json = await data.json();
  console.log(json);
}

fetchData();

## Difference between promise and async await
The key difference between Promises and async/await in JavaScript is:
Promises provide a way to handle asynchronous operations through chaining .then() and .catch() for success and error handling.
async/await is syntactic sugar over Promises, making asynchronous code easier to read and write by using await to pause execution until a Promise resolves, inside an async function.
async/await is more readable, while Promises offer more control over chaining multiple operations. Both are used to handle asynchronous code.

Correlating Callbacks, Promises, and Async/Await with JavaScript's Nature
Concurrency Handling:

Callbacks are the earliest method to handle asynchronous tasks and introduce concurrency by delegating work to background threads or APIs.
Promises provide a cleaner and more structured way to handle concurrency and make chaining asynchronous tasks easier.
Async/Await makes asynchronous code appear synchronous, simplifying concurrent task management and debugging.
Sequential and Concurrent Execution:

Sequential: JavaScript executes synchronous code in order. Even with async tasks, the main thread processes tasks sequentially in the event loop.
Concurrent: Callbacks, Promises, and Async/Await enable non-blocking behavior, where JavaScript can handle multiple operations concurrently while waiting for asynchronous tasks to resolve.
By evolving from callbacks to Promises and then to Async/Await, JavaScript improves its ability to handle concurrent tasks while maintaining readability and simplicity.