<?php

if(isset($_POST['name']) && isset($_POST['color']) && isset($_POST['location']) && isset($_POST['scale']))
{
    include_once 'connectGembase.php';

    $name = trim($_POST['name']);
    $color = trim($_POST['color']);
    $location = trim($_POST['location']);
    $scale = trim($_POST['scale']);

    if(strlen($name) < 3 || strlen($location) < 2 || !is_numeric($scale) || $scale < 1 || $scale > 10)
    {
        $time = date("Y-m-d H:i:s");
        $log_file = '...\logs\insert_log.txt';
        $log_entry = "Failed to insert gem, check the field lengths and scale value" . PHP_EOL;
        file_put_contents($log_file, $log_entry, FILE_APPEND);
        mysqli_close($connect_gembase);
        exit();
    }

    $insert = "INSERT INTO gems (Name, Color, Location, Scale) VALUES ('$name', '$color', '$location', '$scale')";

    if(mysqli_query($connect_gembase, $insert))
    {
        $time = date("Y-m-d H:i:s");
        $log_file = '...\logs\insert_log.txt';
        $log_entry = "Inserted gem: Name: $name, Color: $color, Location: $location, Scale: $scale at $time" . PHP_EOL;
        file_put_contents($log_file, $log_entry, FILE_APPEND);
    }
    else
    {
        echo "Error adding gem: " . mysqli_error($connect_gembase);
    }

    mysqli_close($connect_gembase);
}