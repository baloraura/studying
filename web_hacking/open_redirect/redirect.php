<!-- redirect.php -->
<?php
if (isset($_GET['url'])) {
    $url = $_GET['url'];
    header("Location: " . $url);
    exit();
} else {
    echo "No URL provided.";
}
?>