<html>
<head>
    <title>Test Results</title>
</head>
<body>
<script>
function renderResults(data) {
    let html = "";
    html += "<table border='1'><tr><th>Test</th><th>Status</th><th>Time</th><th>Input</th></tr>";
    data.details.forEach(test => {
        html += `<tr class="${test.status}">
            <td>${test.test}</td>
            <td>${test.status}</td>
            <td>${test.time !== undefined ? test.time + 's' : ''}</td>
            <td><pre>${test.test_input !== undefined ? test.test_input : ''}</pre></td>
        </tr>`;
    });
    html += "</table>";
    document.getElementById("results").innerHTML = html;
}
</script>
<div id="results"></div>
</body>
</html>
