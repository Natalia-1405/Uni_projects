<?php
    $connect_gembase = mysqli_connect('localhost', 'root', '', 'gembase');

    if (!$connect_gembase) 
    {
        die("Could not connect: " . mysqli_error($connect_gembase));
    }
?>