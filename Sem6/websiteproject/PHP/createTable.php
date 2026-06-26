<?php
    $connect_gembase = mysqli_connect('localhost', 'root', '', 'gembase');

    if (!$connect_gembase) 
    {
        die("Could not connect: " . mysqli_error($connect_gembase));
    }

    $create_table = "CREATE TABLE IF NOT EXISTS gems (
        id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
        Name VARCHAR(50) NOT NULL,
        Color VARCHAR(20) NOT NULL,
        Location VARCHAR(100) NOT NULL,
        Scale DECIMAL(10, 2) NOT NULL,
        CHECK (Scale BETWEEN 1 AND 10))";

    if (mysqli_query($connect_gembase, $create_table))
    {
        echo "Table created successfully";
    } 
    else 
    {
        echo "Error creating table: " . mysqli_error($connect_gembase);
    }

    mysqli_close($connect_gembase);
?>