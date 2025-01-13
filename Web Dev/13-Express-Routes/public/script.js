$(() => {
    let inpTask = $('#inpTask');
    let btnAddTask = $('#btnAddTask');
    let listTasks = $('#listTasks');

    btnAddTask.click(() => {
        $.post('/todos', inpTask, (data) => {
            console.log(data);
            listTasks.empty();
            data.forEach(t => {
                listTasks.append('<li>' + t.task + '</li>');
            });
        });
    });
});