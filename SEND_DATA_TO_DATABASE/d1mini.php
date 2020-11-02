<?php
/* Attempt MySQL server connection. Assuming you are running MySQL
server with default setting (user 'root' with no password) */
$link = mysqli_connect("localhost", "root", "", "boot");

// Check connection
if($link === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}



// Escape user inputs for security
$boot_value = mysqli_real_escape_string($link, $_POST['boot_value']);
$boot_value1 = mysqli_real_escape_string($link, $_POST['boot_value1']);


// attempt insert query execution
$sql = "INSERT INTO bootc (boot_value, boot_value1) VALUES ('$boot_value', '$boot_value1')";
if(mysqli_query($link, $sql)){
    echo "Records added successfully.";
} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}

// close connection
mysqli_close($link);
?>