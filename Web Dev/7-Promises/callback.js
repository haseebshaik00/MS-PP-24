// General Async Function Format
function asyncTask(callback){
    console.log("Async Task executing!");
    setTimeout(() => {
        console.log("Async Task executed!");
        callback();
    }, 1000); // this setTimeout function represent an async function as there is some delay in this
}

asyncTask(() => {
    console.log("Callback Task executed!"); // need to write callback when calling this, for promises its not required
    // this function is the callback function in the upper code block
});