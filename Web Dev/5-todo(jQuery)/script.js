$(() => {

    let btnAdd = $('#btnAdd');
    let btnClear = $('#btnClear');
    let btnReset = $('#btnReset');
    let btnSort = $('#btnSort');
    let inputTask = $('#inputTask');
    let taskList = $('#taskList');

    itemAdd = () => {
        let listItem = $('<li>', {'class': 'list-group-item'}).text(inputTask.val());
        taskList.append(listItem);
        listItem.click(() => listItem.toggleClass('done'));
        inputTask.val('');
        buttonToggle();
    }

    inputTask.keypress((event) => {
        if(event.which == 13){
            event.preventDefault();
            itemAdd();
        }
        buttonToggle();
    });

    buttonToggle = () => {
        btnAdd.prop('disabled', inputTask.val() == '');
        btnReset.prop('disabled', inputTask.val() == '');
        btnSort.prop('disabled', taskList.children().length < 1);
        btnClear.prop('disabled', taskList.children().length < 1);
        console.log(taskList.children().length);
    };

    inputTask.on('input', () => {
        buttonToggle();
    });

    btnAdd.click(() => {
        if(inputTask.val() == '') alert('Enter Task Name')
        else itemAdd()
    });
    btnAdd.click(() => {});
    btnReset.click(() => {
        inputTask.val('');
        buttonToggle();
    });
    btnClear.click(() => {
        $('#taskList li.done').remove();
        buttonToggle();
    });
    btnSort.click(() => {
        taskList.append($('#taskList li.done'));
    });

});