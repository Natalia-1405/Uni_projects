<?php

include_once 'connectGembase.php';

if(isset($_POST['id'])){

    $del = $_POST['id'];

    $delete = "delete
            from 
            gems
            where id = '$del'
            "
            ;

    $wykonaj = mysqli_query($connect_gembase,$delete);

    mysqli_close($connect_gembase);

   $time = date("Y-m-d H:i:s");
    $log_file = '...\logs\insert_log.txt';
    $log_entry = "Deleted gem at $time" . PHP_EOL;
    file_put_contents($log_file, $log_entry, FILE_APPEND);

}

?>