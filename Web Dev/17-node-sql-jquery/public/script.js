$(() => {
    let inpId = $('#inpId');
    let inpName = $('#inpName');
    let inpAge = $('#inpAge');
    let inpNotes = $('#inpNotes');
    let tableStudents = $('#tableStudents');
    let btnSubmit = $('#btnSubmit');

    function refreshStudentsTable(persons) {
        tableStudents.empty();
        tableStudents.append(
            `<tr>
            <th>ID</th>
            <th>Name</th>
            <th>Age</th>
            <th>Notes</th>
            </tr>`
        );
        console.log(persons);
        for (p of persons) {
            tableStudents.append(
                `<tr>
                    <td>${p.ID}</td>
                    <td>${p.NAME}</td>
                    <td>${p.AGE}</td>
                    <td>${p.NOTES}</td>
                </tr>`
            )
        }
    }

    $.get('/api/students', (data) => {
        refreshStudentsTable(data);
    });

    btnSubmit.click((e) => {
        e.preventDefault();
        $.post('/api/students', {
                id: inpId.val(), 
                name: inpName.val(),
                age: inpAge.val(),
                notes: inpNotes.val()
            }, function (data) {
                refreshStudentsTable(data)
            })
    });
});