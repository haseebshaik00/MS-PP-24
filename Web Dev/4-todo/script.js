window.onload = () => {
    let input = document.getElementById('vanillaInput');
    let btnAppend = document.getElementById('vanillaAppend');
    let btnPrepend = document.getElementById('vanillaPrepend');
    let list = document.getElementById('vanillaList');

    btnAppend.onclick = () => {
        let up = document.createElement('button');
        let down = document.createElement('button');
        let deleteItem = document.createElement('button');
        up.innerText = '🔼';
        down.innerText = '🔽';
        deleteItem.innerText = '❌';

        // 2 options to handle clicks
        // deleteItem.addEventListener(click, () => {})
        // deleteItem.onclick = () => {}

        deleteItem.onclick = (event) => {
            console.log(event);
            event.target.parentElement.remove();
        }

        up.onclick = (event) => {
            const listItem = event.target.parentElement; // Current list item
            const parent = listItem.parentElement; // Parent list (e.g., <ul> or <ol>)
            const previousSibling = listItem.previousElementSibling; // Previous list item
            if (previousSibling)
                parent.insertBefore(listItem, previousSibling); // Move up
        }

        down.onclick = (event) => {
            const listItem = event.target.parentElement; // Current list item
            const parent = listItem.parentElement; // Parent list (e.g., <ul> or <ol>)
            const nextSibling = listItem.nextElementSibling; // Next list item
            if (nextSibling)
                parent.insertBefore(nextSibling, listItem); // Move down
        }
        
        let listItem = document.createElement('li');
        let inputNode = document.createElement('span');
        inputNode.innerText = input.value;
        listItem.appendChild(deleteItem);
        listItem.appendChild(up);
        listItem.appendChild(down);
        listItem.appendChild(inputNode);

        list.appendChild(listItem);
    }
};

// jQuery TODO
$(() => {
    let input = $('#jInput');
    let append = $('#jAppend');
    let prepend = $('#jPrepend');
    let list = $('#jList');

    append.click(() => {
        list.append($('<li>').text(input.val()));
    });
    prepend.click(() => {
        list.prepend($('<li>').text(input.val()));
    })
});