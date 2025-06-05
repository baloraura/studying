<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "mysql";

$conn = new mysqli($servername, $username, $password, $dbname);

if (isset($_GET['id'])) {
    $id = $_GET['id'];
    $sql = "SELECT * FROM users WHERE id = '$id'";
    echo "<pre>SQL Query: $sql</pre>";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        while($row = $result->fetch_assoc()) {
            echo "User: " . $row["username"] . " | Password: " . $row["password"] . "<br>";
        }
    } else {
        echo "No user found.";
    }
}
?>

<form method="GET">
    Enter User ID: <input type="text" name="id">
    <input type="submit" value="Search">
</form>