// NodeJS API - File System

const fs = require('fs');
// import { writeFile, readFile } from 'fs';

fs.writeFile(__dirname + "/myFile.txt", "Random Data", (err) => {
    if(err) throw err;
    console.log("Written in File!");
});

fs.readFile(__dirname + "/myFile.txt", (err, data) => {
    if(err) throw err;
    console.log(data.toString());
});