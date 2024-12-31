// ------ DOM ----------
// 1) select
console.log(document);     // document object - entire page
console.log(document.body); //just the body
console.log(document.getElementsByTagName('p'));
console.log(document.getElementsByClassName('details'));
console.log(document.getElementById('school'));

// 2) content
var p2 = document.getElementById('school');
console.log(p2);
console.log(p2.innerText); // content inside
console.log(p2.innerHTML); // content with all the elements inside
console.log(p2.outerText); // whole p content
console.log(p2.outerHTML); // whole p element + content

// 3) attribute
p2.innerText="w";
p2.innerHTML="<b> avd </b>";
p2.getAttribute('class');
p2.getAttribute('id');
p2.setAttribute('contentEditable', true);
p2.setAttribute('spellcheck',false);
console.log(p2.outerHTML);
// for input boxes, use p2.value for fetching p2.innerText; see more attributes by - p2.validity

// 4) traverse, replace and remove
/* can be used to traverse in stuff like list where you have parent and child basically
let m = temp0; // a list element basically which is selected from console
m.parentElement;
m.children;
m.previousElementSibling;
m.nextElementSibling;
m.children[0].children;

m1 = temp0
m1.parentElement.remove();
m1.parentElement - // exists but isnt available on the page 
dee.appendChild(m1.parentElement)

m1.remove()
dee.previousElementSibling.previousElementSibling.children[0].appendChild(m1)
// li parent element gives li tag 
*/

// 5) innerHTML performance // always reduce number of times you are calling innerHTML - as it takes a lot of time in processing
var i1 = document.getElementsByTagName('p')[1];
window.onload = function () // take action when the dom is loaded
{
    i1.innerHTML = "a";
    i1.onclick = function(){
        i1.innerHTML = "b";
    }
}

// 6) createElement - instead of innerHTML try to use a combination of createElement and appendChild - also the
// combination differs from case to case
let item = document.createElement('li');
item.innerText = i;

// 7) remove button on click
let xBtn = document.createElement('button');
xBtn.innerText = 'x';
xBtn.onclick = function(event){
    event.target.parentElement.remove();
}

// 8) move the todo up
let xBtn1 = document.createElement('button');
xBtn1.innerText = 'Up';
xBtn1.onclick = function(event){
    event.target.parentElement.parentElement.insertBefore(
        event.target.parentElement, event.target.parentElement.previousSibling
    );
}

// ---------------------------------------------------------------------------------------------------------//
// --------------------------------------------- jQuery ----------------------------------------------------//
// jQuery - helps in DOM manipulation; event handling; hiding, showing stuff;                               //
// toggling stuff; animation; form validation and manipulation                                              //
// jQuery also helps in AJAX - without changing the page, req to backend and fetch data from API and stuff  //
// ---------------------------------------------------------------------------------------------------------//
// ---------------------------------------------------------------------------------------------------------//

$; // 1) jQuery object - can also be written as jQuery;
// $ == jQuery : true

// 2) selectors
$('p'); //here the selectors works same as css attribute selector
$('.class1');
$('#school'); //returns object(array with all the required tags given) -- returns an object which is wrapped inside a jQuery prototype
// whereas getElementById('school') returns tags with contents inside it. the object's first element is equal to getElementById('school')
// $('#one') == document.getElementById('one'); -- false
// $('#one')[0] == document.getElementById('one'); -- true
// No, the result of $('p') in jQuery is not an array. It is a jQuery object, which is a specialized object that behaves somewhat like an array 
// but has additional methods and properties provided by jQuery.

// 3) changing attributes and style
let x = $('#school');
x.text(); // returns text
x.text('bob'); // changes text
x.html(); // returns html
x.html("<b> bob </b>"); // changes html .. we can also include html tags in this
x.attr('height'); // returns height
x.attr('height', '800'); // sets height
x.attr('style', 'color:red');
x.css('color');
x.css('color', 'blue');
x.css('font-size', '20pt').attr('width', '200');

// 4) appending and prepending
// $(() => {}) if your script tag and jquery is inlcuded in head, then use this as this works when the whole window is loaded/ready
// anything you want to do with DOM, you can directly start writing the script file or jquery commands if your 
// jquery and script tag is mentioned in the body 

// 5) appending and prepending
/*
    <input id="item" type="text">
    <button id="prepend"></button>
    <button id="append"></button>
    <ul id="list"></ul>
*/
$(() => {
    // we can write functions in two ways func() or () => {} func expression
    $('#prepend').click(function() { // HOF
        let text1 = $('#item').val(); //val() returns the value and val("adfa") sets the value
        //$('#list').prepend($('<li> ${text1} </li>')); // element creater not a selector as jquery can detect the starting <
        $('#list').prepend($('<li>').text(text1));
    })
    $('#append').click(() => {
        let text1 = $('#item').val();
        $('#list').append($('<li>').text(text1));
    })
})


// --------- AJAX ---------
// makes xhr(xml http req) call
$(() => {
    $('#fetch').click(() =>{
        //asynchronous get req .. this is an asynchronous func hence we will recieve the result in the callback
        $.get("https://newsapi.org/v2/everything?q=tesla&from=2021-12-29&sortBy=publishedAt&apiKey=09aa6966a0724e0697d17efa3ddb62a9", 
        (data) => {
            console.log(data);
            data.articles.forEach(function(i){
                $('#list1').append($('<li>').text(i.title));
            });
        })
    })
})


// traverse in a list
// let x = document.getElementById("oneTwo"); // one two

// // imagine your DOM as a tree and hence decide your path
// console.log(x.previousElementSibling); // one one
// console.log(x.nextElementSibling); // one three
// console.log(x.previousSibling); // space between one two and one three
// console.log(x.parentElement); // ul element
// console.log(x.parentElement.parentElement); // li of one

// console.log(x.parentElement.parentElement.nextElementSibling); // li of two
// console.log(x.parentElement.parentElement.nextElementSibling.children[0]); // ul of two
// console.log(x.parentElement.parentElement.nextElementSibling.children[0].chilren); // array of two children