<?php


$delete = 'border: 1px solid #e94560; background-color: #0f3460; color: white; height: 35px; width: 75px;';

$inputName = 'border: 1px solid #e94560; background-color: #0f3460; color: white; height: 35px; width: 200px;';
$inputSearch = 'border: 1px solid #e94560; background-color: #0f3460; color: white; height: 35px; width: 75px;';
$inputReset = 'border: 1px solid #e94560; background-color: #0f3460; color: white; height: 35px; width: 75px;'; 
$checkbox = 'transform: scale(1.5);';

echo "
<head>
    <script type='text/javascript' src='../JS/delete.js'></script>
    <script type='text/javascript' src='../JS/search.js'></script>

    <style>
        body
        {
            background-color: #1a1a2e;
            color: white;
        }
        
        .cards-grid
        {
            display: flex;
            flex-wrap: wrap;
            gap: 20px;
            justify-content: center;
            margin-top: 20px;
        }

        .card
        {
            width: 200px;
            padding: 15px;
            border: 1px solid #e94560;
            background-color: #0f3460;
            border-radius: 5px;
        }

        .card h3
        {
            margin-top: 0;
        }

        .card p
        {
            margin-bottom: 0;
        }
    </style>
</head>

<form action='' method='POST' id='formSearch'>
    <input type='text' id='searchName' name='name' required placeholder='Name' style='$inputName'>
    <input type='submit' id='inputSearch' value='Search' style='$inputSearch'/>
    <input type='reset' id='inputReset' value='Reset' style='$inputReset'/>
</form>
";

include_once 'connectGembase.php';

$read = "select ROW_NUMBER() OVER (order by id) as row_num, id, name, location, scale, color from gems";
$query = mysqli_query($connect_gembase, $read);

if ($query == false) 
{
    die("Error executing query: " . mysqli_error($connect_gembase));
}

echo "<div class='cards-grid'>";

while ($row = mysqli_fetch_array($query)) 
{

    echo "
        <div class='card'>
            <h3>" . $row['name'] . "</h3>
            <p><b>Location:</b> " . $row['location'] . "</p>
            <p><b>Hardness (Mohs):</b> " . floatval($row['scale']) . "</p>
            <p><b>Color:</b> " . $row['color']. "</p>
            <form action='' method='POST' class='formDelete' style='margin-top: 10px;'>
                <input type='hidden' name='id' value='" . $row['id'] . "' />
                <input type='submit' value='Delete' style='$delete' />
            </form>
        </div>
    ";
}

echo "</div>";

?>