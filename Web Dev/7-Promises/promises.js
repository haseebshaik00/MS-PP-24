// Promises
download = (url) => {
    return new Promise((resolve, reject) => {
        if(!url.startsWith("http")){
            reject(new Error("URL doesn't starts with HTTP"));
        }
        else{
            console.log("Downloading File ...");
            setTimeout(() => { // fake 3 second download
                let fileName = url.split("/").pop();
                resolve(fileName);
            }, 1000);
        }
    });
}

resize = (filename) => {
    return new Promise ((resolve, reject) => {
        if(!filename.endsWith("png")){
            reject(new Error("Image Format is not PNG"));
        }
        else{
            console.log("Resizing File ...");
            setTimeout(() => { // fake 3 second resize
                let resizedFile = filename.split('.')[0] + "-resized.png";
                resolve(resizedFile);
            }, 2000);
        }
    });
}

upload = (uploadFile) => {
    return new Promise((resolve, reject) => {
        console.log("Uploading File...");
        setTimeout(() => {
            let uploadURL = "https://imgur.com/" + uploadFile;
            resolve(uploadURL);
        }, 3000);
    });
}

// 1 - Download File
// let downloadPromise = download("http://image1.png");
// downloadPromise.then((fileName) => {
//     console.log("Downloaded", fileName);
// });

// 2 - Download n Resize
// downloadPromise.then((fileName) => {
//     resize(fileName).then((resizedFile) => {
//         console.log("Resized " + resizedFile);
//     })
// });

// 3 - simpler format of 2
// downloadPromise.then(resize).then((resizedFile) => {
//     console.log("Resized " + resizedFile);
// });

// downloadPromise
//     .then(resize)
//     .then(upload)
//     .then((uploadURL) => {
//         console.log("Uploaded at " + uploadURL);
//     }).catch((err) => {
//         console.log(err);
//     })

// returns array of outputs
Promise.all([download('https://image2.png'), download('https://image3.png'), download('https://image4.png')])
        .then((downloadValues) => {return Promise.all(downloadValues.map(resize))})
        .then((resizedValues) => {return Promise.all(resizedValues.map(upload))})
        .then((uploadValues) => {console.log(uploadValues)})
        .catch((err) => console.log(err));





