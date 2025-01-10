// ******** OOPS *********

// 1) function with new keyword - function acts as a class now
//    here this keyword points to the object not to the window or global scope
//    if we didnt use the new keyword then it would have pointed to the window/global scope --
// -- and hence name and age variables would have been implicitly defined and assigned in the window scope
function Person(name, age){
    this.name = name;
    this.age = age;
}

let p1 = new Person("haseeb", 21);
console.log("p1 = " + JSON.stringify(p1));
console.log(p1);

// 2) object inheritance
let a = {p:10, q:"haseeb1", r: false};
// we cant inherit objects directly without class
let b = Object.create(a);
let c = Object.create(b);

console.log(a);
console.log(b);
console.log(b.q);
console.log(c.q);
b.q = "navbar";
console.log(b);
console.log(b.q);
console.log(c.q);
// reading data = if not available parent objects are checked
// writing data = happens in the current object

// 3) prototype - proto chain
let x1 = 'haseeb';
console.log(x1.__proto__);
console.log(x1.__proto__.__proto__);
console.log(x1.__proto__.__proto__.__proto__);
console.log(x1.__proto__ == String.prototype);
console.log(x1.__proto__.__proto__ == Object.prototype);
console.log(x1.__proto__.__proto__.__proto__ == null);

console.log(a.isPrototypeOf(b)); 
console.log(Object.prototype.isPrototypeOf(String.prototype));
console.log(Object.prototype.isPrototypeOf(undefined));
// everything in js is inherited from Object.prototype = base/root class

// 4) prototype functions
console.log("\nprototype functions")
function Person1(name, age){
    this.name = name;
    this.age = age;
    // we dont add new functions or data here as for diff objects new memory and data will be created, hence they are declared 
    // outside scope using .prototype
}
// so both p and p2 are inheriting from the object person1.prototype
Person1.prototype.isAdult = function(){
    return this.age >= 18;
}
Person1.prototype.city = "delhi";
let p = new Person1("haseeb", 21);
let p2 = new Person1("kunal", 20);
console.log(p.isAdult == p2.isAdult);
// .sort all these kinds of functions are present in Array.prototype not in Array

// 5) es6 classes : just the syntax, internally prototypes are used
// Person() and new Person() can be called when Person is a function
class Person2{
    constructor(name, age){
        this.name = name;
        this.age = age;
    }
}

let p3 = new Person2("lakshit", 21);
console.log(p3);
// only new Person() can be called when Person is a class and not Person(); 
// as this is suppose to be treated just like a class
// both the typeof of class and function is function as class is internally using prototype of function 
// who is obviously inheriting from object prototype

class Student extends Person2{
    constructor(name, age, school){
        super(name, age);
        this.school = school;
        // this should be used only after super is super is given anywhere in the code, also anything can be present 
        // before super except this 
    }
}

let s1 = new Student("ab", 20, "vit");
console.log(s1);
console.log(Student.prototype.isPrototypeOf(s1));
console.log(Student.prototype.isPrototypeOf(p2));
console.log(Person2.prototype.isPrototypeOf(p3));


// **************** Concurrency *****************
// JS Multitasking
/* Concurrency - concurrency in js is done through time slicing, this happens by distributing time so that it looks like they 
are happening parallely but they are not -- as in if there are 2 queues then no queue is idle but at one point of time only 1 task
is being executed
concurrency can still occur without parallelization - through time slicing (or) running more tasks in the same given time

/// Concurrency in JavaScript revolves around its single-threaded, event-driven architecture. 
This means JavaScript executes code on a single thread but can handle multiple 
tasks concurrently by leveraging the event loop and asynchronous programming features.

// Callback - A callback is a function passed as an argument to another function
This technique allows a function to call another function
A callback function can run after older function has finished
callback can only be used in async funcs

// A promise is used to handle the asynchronous result of an operation. JavaScript is designed to not wait for an 
asynchronous block of code to completely execute before other synchronous parts of the code can run. With Promises, 
we can defer the execution of a code block until an async request is completed.

// normally in js the fucntions runs in sequential order but if there are asynchronous functions it's not necessary that 
// .. they run in a seq order hence to make them in seq order we use promises and we can also use async await with promises

// They keyword async is used to make a function asynchronous. The await keyword will ask the execution to wait until 
the defined task gets executed. It allows the use of await Keyword inside the functions with async keyword. 
Using await in any other way will cause a syntax error.
*/

// 1) Concurrency on single thread
function sayHello(times, name){
    let c=0;
    let loopId = setInterval(() => {
        c++;
        console.log("Hello " + name);
        if(c === times)
            clearInterval(loopId);
    }, 100);
}


// concurrent
sayHello(3, "haseeb1");
sayHello(2, "kunal1");
// both haseeb and kunal execute parallely; to run sequentially we can use asynchronous callback functions

// 2) Async Function
function sayHello1(times, name, doneSaying){
    let c=0;
    let loopId = setInterval(() => {
        c++;
        console.log("Hello " + name);
        if(c === times)
        {
            clearInterval(loopId);
            doneSaying(); // called at the end of the current callback - here doneSaying is sayhello1(kunal) then for kunal's
            // execution donesaying will be lakshit
        }
    }, 100);
}

// sequential
sayHello1(3, "haseeb2", () => {
    sayHello1(2, "kunal2", () => {
        sayHello1(10, "lakshit2", () => {

        })
    })
})
// the main problem here is we will face shadowing of variables, outer variables cant be used if the inner variable has the same name
// like err, which can be ruled out by using diff names of the variable (or)
// we can also use promises introduced in es6

// 3) Promises
function sayHello2(times, name){
    return new Promise((resolve, reject) => {
        let c=0;
        let loopId = setInterval(() => {
            c++;
            console.log("Hello " + name);
            if(c === times)
            {
                clearInterval(loopId);
                resolve(); // this is used to call function written in then
            }
        }, 100);
    })
}

// sequential - callback has function
sayHello2(3, "haseeb3").then(() => {
    sayHello2(2,"KUNAL3").then(() => {
        sayHello2(3,"lakshit3")
    })
})

sayHello2(3, "haseeb5")
    .then(() => sayHello2(2, "kunal5"))
    .then(() => sayHello2(3, "lakshit5"));

// concurrent - callback doesn't have function
sayHello2(3, "haseeb4")
    .then(sayHello2(2,"KUNAL4").then(sayHello2(3,"lakshit4")));

sayHello2(3, "haseeb3")
    .then(sayHello2(2,"KUNAL3"))
    .then(sayHello2(3,"lakshit3"));

// Promises structure doesnt looks like its being executed sequentially check haseeb5 line 192 - while we want
// our to tasks to look like its being executed sequentially - as it is being executed synchronously

// 4) async-await - accepts promises resolve func - makes easier to write promises
// The async and await keywords in JavaScript simplify handling asynchronous operations by allowing you to write 
// asynchronous code that looks and behaves like synchronous code.
// async is used to declare a function that returns a promise.
// await is used inside an async function to pause execution until a promise is resolved.

async function task(){
    await sayHello2(3, "haseeb"); // sequential
    await sayHello2(2, "kunal"); // sequential
    sayHello2(1, "spike"); // parallel
    await sayHello2(2, "lakshit"); // sequential
}

task();
// await makes the task execute sequentially and it can be written only inside async function 
// .. if a normal sayHello is written within task(); the sayHello runs parallely with the async func 
// here the function with no await will run parallely
// the function with await runs sequentially - the execution will stops till the promise is resolved 
// -- and then the next line is executed

// 5) Promise.all is used wheh we want some functions to run in batch, here haseeb and kunal will complete their process and then 
// ... only spike and lakshit will start executing
async function task1(){
    await Promise.all([ 
        sayHello2(3, "haseeb"),
        sayHello2(2, "kunal")
    ]);
    console.log("--- first batch over ---");
    console.log("--- second batch starting ---");
    await Promise.all([ 
        sayHello2(1, "spike"),
        sayHello2(2, "lakshit")
    ]);
    console.log("--- second batch over ---");
}


// **************** Networks, Protocols and Hardware ************************
// gothrough the README.md file for this
// read behrouz fehrouzan book for IP Addresses
// also watch gate smashers playlist  


// aysnc func and promises 

// async func and promises blueprint
/*
asyncFunc = function(done){
    ....
    ....
    done(); // here done is a callback function
} 

downloadPromise.then( function(){ 

})
// here downloadPromise returns a promise object and the then object is executed
// .. the then is same as done here

*/

// promises advantage is it doesnt cause shadowing of variables and provides us deferred resolve which 
// .. normal async callback doesnt do
// https://online.codingblocks.com/app/player/220561/content/215180/6506/lecture
// .. refer this link for overall explainaition of promises

// Promise.all takes array of promises and returns result of the array of promises 
/*
    Promise.all([
        download(""),
        download(""),
        download("")
    ]).then(function(values){
        return Promise.all(values.map(resize))
    })
    
    //.. instead of writing  we can directly write 
    //.. instead of writing values.map(function(item){ return resize(item)}) we can directly write values.map(resize)
*/

// if any one of the then stops it goes to catch
// the then runs only when all three downloads are finished, this is the feature of then 


// shorthand for calling then()
/* 

function download(url){
    resolve(filename)
}

function resize(){
    resolve(resizedFilename)
}

download("someurl.com")
    .then(function(filename){
        resize(filename).then(function (resizedFilename){
            console.log("resized file is at : " + resizedFilename);
        })
    })

// .. this can also be written as .. here as the function the function(filename) is same as resize(filename)
// .. hence we can omit the function(filename) part and directly write resize

download("someurl.com")
    .then(resize)
    .then(function(resizedFilename){
            console.log("resized file is at : " + resizedFilename);
    })
*/