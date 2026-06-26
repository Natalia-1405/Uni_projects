<?php
    $connect_gembase = mysqli_connect('localhost', 'root', '');
    
    if (!$connect_gembase) 
    {
        die("Could not connect: " . mysqli_error($connect_gembase));
    }
    
    $create_gembase = "CREATE DATABASE IF NOT EXISTS gembase";
    
    if (mysqli_query($connect_gembase, $create_gembase)) 
    {
        echo "Gembase created successfully";
    } 
    else 
    {
        echo "Error creating gembase: " . mysqli_error($connect_gembase);
    }
    
    mysqli_close($connect_gembase);
?>