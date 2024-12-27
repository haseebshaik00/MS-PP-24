// https://javascript.info/script-async-defer
// async - js script parallel download with the html file and executes as soon as it's downloaded.
// defer - script run/executes after the html file has been parsed.

/** JS Concepts
 * Basics (Datatypes, Functions, HOF, Hoisting)
 * Closure
 * this
 * Objects n Classes
 * Prototype based inheritance
 * Promises
 * IIFE
 */

console.log("External Script");

// let x = 1
// -> undefined
// x
// -> 1

// 1) datatypes.js
function a(){ //function declaration
    return 1;
}

let b = function () { //function expression
    return 1;
}

let c=1;
console.log(13313, typeof 13313);
console.log(234234.5356, typeof 234234.5356);
console.log('a', typeof 'a');
console.log('asdasfasfa', typeof "asdasfasfa");
console.log(true, typeof true);
console.log(null, typeof null);
console.log(undefined, typeof undefined);
console.log(a(), typeof a());
console.log(a, typeof a);

// 2) functions.js
function a1(){ //function declaration
    return 1;
}

let b1 = function () { //function expression
    return 1;
}

console.log(beta()); //hoisting

function alpha () {
    return "A";
}

console.log(beta());
// console.log(gamma()) // ReferenceError

function beta() {
    return "B";
}

let gamma = function () { // not hoisted
    return "C";
}

console.log(gamma());
console.log(beta());

// null - 0 - false - undefined - '' all act as false hence can be used in if  
function area(height, width) { // just change logic to make a function act as polymorphism
    if (!width) {
        return Math.PI * height * height;
    }
    return height * width;
}

console.log('area 3,4 ', area(3,4));
console.log('area 4 ', area(4));

// def add(a, b):  # 'a' and 'b' are parameters
//     return a + b

// result = add(5, 3)  # 5 and 3 are arguments
// print(result)  # Output: 8


function hello () {
    let arguments = 'asdasd'; //dont take the variable name arguments
    console.log('hello world ' + arguments[0] + arguments[1]);
}

function hello1 () {
    let argument = 'asdasd'; //dont take the variable name arguments
    console.log('hello world ' + arguments[0] + arguments[1]); // arguments store all the arguments paraments in an array
    console.log('hello world ' + argument[0] + argument[1]);
}

hello(1, 2);
hello('Arnav', 'Gupta');

hello1(1, 2);
hello1('Arnav', 'Gupta');

// 3) higher_order_functions.js
//https://github.com/haseebshaik00/FullStack_NodeJS_Live_March2020/tree/master/Lecture05/js-basics
// first order func- defined by global scope and can be directly called
// HOF - if a prog lang allows you to pass function as a argument and/or return function through a function
// a) returning a function
function createGreeter(greet_msg)
{
    function greet(name)
    {
        console.log(greet_msg,name);
    }
    return greet;
}

let g1 = createGreeter('Hi');
console.log(typeof g1); // fuction
console.log(g1('haseeb')); // undefined

function getName() {
    return document.getElementById('namebox').value;
}

//b) passing a function as an argument
// g1(getName) - in this we are passing a function

/*
// 2 types - for printing name
a) 
    <!-- here we are passing the function itself -->
    <button onclick="g1(getName)">GM</button>
    //***** here the getName function is fetched and sent as an argument
    function createGreeter(greeting) {
        function greet(name) { // here as the name is also a function hence here greet is 
            also an hof and createGreeter is already a hof
            // here we treat as if name is function
            console.log(greeting, name()) // hence we are calling it here
        }
        return greet
    }

b) <!-- here we are calling the function and passing the value (string) -->
    <button onclick="g1(getName())">GM</button>
    //***** here the name is fetched and send in the form of string 
    function createGreeter(greeting) {
    function greet(name) {
        // here we treat name as if it is string
        console.log(greeting, name)
    }
    return greet
    }
*/

// 4) basics.js
let p = 10;
console.log(p);
//alert("yo");
let q = [1,2,3,4,5];
console.log(q);

r = 20; //global scope
var s = 30; //function scope
let t = 40; //block scope

let u1 = [1,2,3];
console.log(u1.length);
console.log("length", u1["length"]);

for(let i of u1){ //forof loop
    console.log(i);
}
for(let index in u1){ //indexin loop
    console.log(u1[index]);
}

// Array Functions
u1.push("g");
u1.push("3");
console.log(u1);
u1.pop();
console.log(u1);
console.log(u1.indexOf('g'));
u1.shift();
console.log(u1);
u1.unshift("apple");
console.log(u1);

// oops in javascript - allows us to create objects without a class 
// example of an object in js - js object ~ json object~ (js object notation) object 

// ************* Object Creation *************
// a) object creation normal
var bird = {
    x:100,y:200,arrayBird:[1,2,3],
    f: function(){
        console.log(this.x); 
    }
}; // all keys are strings

console.log(bird['x']); // numeric literals can also be accessed with this or any other literals
console.log(bird.x); //bird's object attributes can be accessed in these 2 ways

//foreach loop - can be used only with array, sets and maps
bird.arrayBird.forEach(function(i,j){
    console.log(i,j);
});

// b) object creation with function declaration
function student(id,name){
    this.id = id;
    this.name = name
}

let haseeb = new student(1,"haseeb");

// c) object creation with class declaration - class keyword(ECMAScript 2015) - ES
class Studentregd{
    constructor(id,name){
        this.id = id;
        this.name = name;
    }
};

// class expression
let Studentregd2 = class{
    constructor(id,name){
        this.id = id;
        this.name = name;
    }
};

let kunal = new Studentregd(1,"kunal");
let lakshit = new Studentregd2(1,"lakshit");

// 5) strings.js

let str = "hello world"
console.log(str);
let str1 = 'haseeb s\'s';
console.log(str1);

let str2 = "haseeb"; // ECMAScript 2016
// with backticks we can have template.
console.log(`hi ${str2}`);

// if the string is too long it can be written with forward slash
let str5 = "rfer \
ecr\
ect";

// no need of \ in backticks
let str5 = `rfer  
ecr
ect`;

//string functions
s = "haseeb is a good boy";
console.log(s.length);
console.log(s.indexOf("is")); // position to start search from can also be given
console.log(s.lastIndexOf("is")); // position to start search from can also be given
console.log(s.slice(2,5)); // 2 to 5-1 ; negative indexes can also be included
console.log(s.slice(-5,-2)); // 2 to 5-1 ; negative indexes can also be included
console.log(s.substring(2,7)); //  2 to 7-1 ; negative indexes cannot be included
console.log(s.substr(2,7)); // 7 characters from 2 ; negative indexes can also be included

//arrays
let u = [1,2,3,4,5,6,7,8,9,10];
console.log(u);
console.log(u.length);
for(let i of u){ 
    console.log(i); 
} 
for(let index in u){ 
    console.log(u[index]); 
}
// push, pop, shift, unshift
// we can unshift and push more than 1 element in an array directly;
// u.unshift("kiwi", "banana");
console.log(u.slice(6));
console.log(u.slice(4,6));
console.log(u.slice(-4,-2));
console.log(u);
let v = u.splice(2,6);  // mutates the array
console.log(v);
console.log(u);
u.splice(1,3,"x","x"); // update data
console.log(u);
console.log(v.concat(1, 2, 3)); // doesnt mutate the original array; we can concat arrays with arrays also
console.log(v.concat(1));
console.log(v.concat([1, 2, 3]));

// 6) closure.js
// at the time when function is created, all the scope that were present will captured by the function and will 
// persist until the scope of a function ends  
function outer(arg1) {
    let var1 = 10 // line 2
    let x = 10
    
    function inner(arg2) {
      let var2 = 20
      let x = 20
      console.log(arg1, var1, arg2, var2, x)
      console.log(arguments[0])
    }
  
    return inner
    // return 10
  }
  
let x = outer('param1', 11)  
// typeof x == 'function'
// x == inner
// scope of arg1 and var1 are from lines 2 to 10
x('param2');

// outer function arguments are not available in inner func, but inner arguments are surely available in inner func
//In JavaScript, closures are a powerful feature that allows functions to access variables from their outer (enclosing) scope, 
// even after that scope has exited. Closures are created whenever a function is defined inside another function and gains 
// access to the outer function's variables.
/*
Data Privacy and Encapsulation
Closures can create private variables that are not accessible from the outside, 
mimicking encapsulation in object-oriented programming.
function counter() {
    let count = 0; // Private variable
    return function() {
        count++;
        return count;
    };
}
const increment = counter();
console.log(increment()); // 1
console.log(increment()); // 2
*/


// 7) this.js

// Answer in context of C++/Java
// What does the keyword "this" mean, what does it refer to ?
// In which places in code can we NOT use "this" ?

// in java cpp, this is written in class, although java everyone has class
// in cpp, this can not be written in static methods
// this points to an object

// this in JS
// In non–strict mode, this is always a reference to an object. In strict mode, it can be any value.
// The value of this depends on in which context it appears: function, class, or global.
function checkThis() {
    console.log(this)
  }
  let obj = {
    "a": 10,
    b: 'asdsa',
    c: true,
    d: function () {
      console.log(this)
    },
    10: 32246,
    true: 'asdasd',
    e: {
      l: 234,
      m: 'sdgsdg',
      n: function () {
        console.log(this)
      },
    },
  }

// in console
// obj.d() then output is object as this points to the object
// let z = obj.d; 
// z() is called then this points to window
// - bounded on runtime

let newObject = {
    10: 11111
}
 
// access 10 as newObject["10"] 
// not like newObject.10 because js doenst allow numeric literal as key 
// but we are converting numeric to string in (line-2) line 368

// 8) stringliteral.js
// He said, "This is is awesome!"

let s1 = 'He said, "This is is awesome!"'

let s2 = "He said, \"This is is awesome!\""

let s3 = "He said, 'This is is awesome!'"

let s4 = `He said, 'This is is awesome!'`

let s5 = "This string is \n in multiple lines"

let s6 = `
    This string
    is in multiple lines
`

let name = 'John'

let g12 = 'Good Morning ' + name

let g2 = `Good Morning ${name}`

let s7 = `10 + 2 = ${10 + 2}` // inside ${} we can write any valid js ******* IMPPPP ****** ${} work only with backticks

// 9) equality and sameness and prototype based inheritance
console.log(1 == '1') // true - Abstract Equality
console.log(1 === '1') // false - Strict Equality

// peculiar cases 
// the conversions for this (different datatypes on both ends) kind of comparisions are done through chart - check docs
console.log(0 == '') // true, because Number('') == 0

console.log('false' == false) // false

console.log('' == false) // true, both typecast to 0
// \n and \t both will give 0, even spaces will give zero, but both wont be equal \n!=\t
// this doesn't hold good for abstract equality 
// a = b,  b = c  ... implies that .. a = c

console.log([1,2] == [1,2]) // false - because they are non primitive and their pointers are being checked

let obj1 = {
    a: 10,
    b: 20, 
    c: 30
}

let obj2 = Object.create(obj1) // prototype based inheritence
// OOPS - exists in js but internally everthing is handled through prototype(__proto__)
obj2.p = 'adg'
obj2.q = 'dgn'
obj2.r = 'dfn'

let obj3 = Object.create(obj2)

/*
obj3.__proto__ - {p: 'adg', q: 'dgn', r: 'dfn'}
obj3.__proto__.__proto__ - {a: 10, b: 20, c: 30}
obj3.__proto__.__proto__.__proto__ -{constructor: ƒ, __defineGetter__: ƒ, __defineSetter__: ƒ, 
    hasOwnProperty: ƒ, __lookupGetter__: ƒ, …} // default prototype
obj3.__proto__.__proto__.__proto__.__proto__ - null
dont use proto in production level, use only for debugging
*/

// obj3.__proto__ == obj2
// obj3.__proto__.__proto__ == obj1

/* 
    obj2.a -> it will try to find a in obj2
        -> if not found, 
        -> it will try to find it in obj2.__proto__
        -> if not found,
        -> it will try to find it in obj2.__proto__.__proto__
        -> ... and so on... 
        -> till .__proto__ becomes null
        ~~this logic is followed only while reading but while writing a new variable is created in the current class and 
        writing is done in it - shadowing: What is shadowing in JS?
        ~~Shadowing: Now, when a variable is declared in a certain scope having the same name defined on its outer scope and 
        when we call the variable from the inner scope, the value assigned to the variable in the inner scope is the value 
        that will be stored in the variable in the memory space.
        ~~suppose ob1 has a as 10 and ob2 is inheriting ob1, then ob2.a++ will give ob2 a 
        new a with value 11 but ob1.a will remain same that is 10 and if ob3 is inherting 
        ob2 then ob3 will get a with 11
*/

// 10) prototypes.js

let str3 = "Asdasd"  ;                            // 3 levels from null
let num = 233                                   // 3 levels from null
let bool = true                                 // 3 levels from null
let arr = [246,436,6,346]                       // 3 levels from null
let obj6 = {a: 10, b: 'asdasd'}                  // 2 levels from null
let fun = function () { console.log ('yay!') }  // 3 levels from null

// if x and y are not primitive 
// x == y : true <- what does this mean ? 
// this means they are reference to the same object in memory 

console.log('======= types =======') 
// all the below items are function which create items of their respective datatypes
console.log('typeof String', typeof String)
console.log('typeof Boolean', typeof Boolean)
console.log('typeof Number', typeof Number)
console.log('typeof Array', typeof Array)
console.log('typeof Object', typeof Object)
console.log('typeof Function', typeof Function)

console.log('======= proto chain =======')
console.log(str3.__proto__.__proto__ == obj6.__proto__)
console.log(num.__proto__.__proto__ == obj6.__proto__)
console.log(bool.__proto__.__proto__ == obj6.__proto__)
console.log(arr.__proto__.__proto__ == obj6.__proto__)
console.log(fun.__proto__.__proto__ == obj6.__proto__)

// Everything indirectly inherits from the same thing
// that obj is inherited from 
// i.e. in Javascript, everything(number, string, boolean) is essentially an Object

console.log('======= prototypes ======= ')
console.log(obj6.__proto__ == Object.prototype)
console.log(str3.__proto__ == String.prototype)
console.log(num.__proto__ == Number.prototype)
console.log(bool.__proto__ == Boolean.prototype)
console.log(arr.__proto__ == Array.prototype)
console.log(fun.__proto__ == Function.prototype)

/*
s="a"
'a'
s.__proto__
String {'', constructor: ƒ, anchor: ƒ, big: ƒ, blink: ƒ, …}
String.prototype
String {'', constructor: ƒ, anchor: ƒ, big: ƒ, blink: ƒ, …}
s.__proto__.__proto__
{constructor: ƒ, __defineGetter__: ƒ, __defineSetter__: ƒ, hasOwnProperty: ƒ, __lookupGetter__: ƒ, …}
s.__proto__.__proto__.__proto__
null
*/

/*
ob1 = Object.create(Object.prototype);
*/

// String.prototype inherits from Object.prototype
// typeof Object.create(Boolean.prototype) -> ?? object
// let x = Object.create(Boolean.prototype)
// but typeof bool -> boolean and typeof x -> object
// 2 items can have the same proto but their typeof should be same is not necessary

/*
You cannot access prototype on a string literal (or any primitive value like s = "a") because primitives do not 
have a prototype property. The prototype property is specific to constructor functions and is used to define properties 
and methods that are inherited by objects created by that constructor.
*/

console.log(str3.charAt(4))
console.log(typeof str3.charAt) // ? 
let str4 = "dgndgn"
console.log(str3.charAt == str4.charAt) // true

str3.charAt = function () { return 'X' } // does not make a difference - cause js doesnt allow this

String.prototype.charAt = function () { return 'X' }
console.log(str3.charAt(1))

// String.prototype contains all default string functions
// like charAt, indexOf, substring, slice etc 


// here join reference is copied into joinoriginal
Array.prototype.joinOriginal = Array.prototype.join

Array.prototype.join = function () {
    console.log('join called on', this)
    return this.joinOriginal(...arguments)
}
/**
 * Array.prototype 
 * {
 *  .... 
 *  joinOriginal: function () {},
 *  join: function () { our fun },
 *  ....
 * }
 */

// 11) classes.js

// Classes are a template for creating objects. They encapsulate data with code to work on that data. 
// Classes in JS are built on prototypes but also have some syntax and semantics that are unique to classes.

class Person {
    constructor(name, age) {
      this.name = name
      this.age = age
    }
  
    isAdult() {
      return this.age >= 18
    }
  }
  
  let p1 = new Person('John Doe', 22)
  let p2 = new Person('Jane Doe', 15)
  
  console.log(typeof Person) // function; there is NO new datatype called 'class'
  console.log(p1.__proto__ == Person.prototype) // true
  console.log(p1.__proto__.__proto__ == Object.prototype) // true
  
  class Student extends Person {
    constructor(name, age, grade) {
      super(name, age)
      this.grade = grade
    }
  }
  
  let s11 = new Student('Harry Potter', 13, 5)
  let s22 = new Student('Hermoine Granger', 14, 6)
  
  console.log(s11.__proto__ == Student.prototype)
  console.log(s11.__proto__.__proto__ == Person.prototype)
  console.log(s11.__proto__.__proto__.__proto__ == Object.prototype)
  
  // inheritance chain 
  // Object.prototype -> Person.prototype -> Student.prototype
  
  // no inheritance between the classes (actually they are functions)
  // Object -x-> Person -x-> Student

  function Person2 (name, age) {
    this.name = name 
    this.age = age
    }

function Student2 () { // no need to inherit using funcs - use classes directly

}

let p11 = new Person2('John Doe', 22)
// new keyword is not required to call the function but in classes it is

// 12) promises.js
function fakedownload (done){
    setTimeout(function(){
        let downloadedData1 =  "file.txt";
        done(downloadedData1);
    }, 1000)
}

fakedownload(function (data){
    console.log("download this file --->> ");
    console.log(data);
});

function fakePromise(correct){
    return new Promise( function(resolve, reject){
        setTimeout(function(){
            let downloadedData1 =  "file.txt";
            if(correct) 
                resolve(downloadedData1);
            else 
                reject(new Error("Couldn't download file"));
        }, 1000);
    })          
}

fakePromise(true).then( function (data){
    console.log("download this file --->> ");
    console.log(data);
}).catch(function(err){
    console.log(err);
});

// here inside then = resolve and inside catch = reject 
// then(function(data){}) = then(resolve(downloadedData1))
// catch(function(err){}) = then(reject(err){})
// if you dont want to write the then function you can use setTimeout outside scope
// and use it as a then func

function fakePromise(correct){
    return new Promise( function(resolve, reject){
        setTimeout(function(){
            let downloadedData1 =  "file.txt";
            if(correct) 
                resolve(downloadedData1);
            else 
                reject(new Error("Couldn't download file"));
        }, 1000);
    })          
}

let d1 = fakePromise(true);

// catch defined
d1.catch(function(err){
    console.log(err);
})


// the promise is already reolved and this then can be executed afterwards also whenever we want
// .. this is called as deferred resolve
setTimeout(function(){
    d1.then( function (data){
        console.log("download this file --->> ");
        console.log(data);
    });
}, 3000);


// 13) iife.js
// immediately invoked function expression - helps create a local scope without polluting the global scope

//a
(function sayHello(){
    console.log("hello");
})();

(function (){
    console.log("hello");
})();

//b
if(true){
    (function(){
        var a = 10;
    })();
}
console.log(a);

//c
(function (l,p,r,s){
    l("3^4 =  " + p(3,4));
})(console.log, Math.pow, Math.sin, Math.sqrt);

//d
for(var i=0; i<10; i++){
    setTimeout(function(){
        console.log(i);
    }, 100);
} // print 10 - 10 times can be avoided using let or the below method

for(var i=0; i<10; i++){
    (function(j){
        setTimeout(function(){
        console.log(j);
    }, 100);})(i);
} 

for(var i=0; i<10; i++){
    setTimeout(console.log, 100, i);
}

// 14) setTimeout and setInterval
setTimeout(function(){
    console.log("hello");
}, 100);

var id = setInterval(function(){
    console.log("hi");
}, 100);
clearInterval(id);


var id1;
var count1 = 0;
function sayHi(){
    count1++;
    if(count1 > 5)
        clearInterval(id2);
    console.log("hi");
}

var id2 = setInterval(sayHi, 100);

