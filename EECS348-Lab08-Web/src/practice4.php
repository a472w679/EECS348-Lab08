<html>
    <head>
        <title>EECS 348 Lab 07 - Practice 04</title>
        <link href="../style/style.css" type="text/css" rel="stylesheet">    
    </head>
    <body>
        <?php
        $size = $_POST["size"] + 1;
        echo "<table id=\"multi\" border=\"1\">";

                // Column Heads
                echo '<tr>';
                echo '<td></td>';
                for ($i = 1; $i < $size; $i++)
                    echo '<td>' . $i . '</td>';
                echo '</tr>';

                for ($i = 1; $i < $size; $i++){
                    echo '<tr>';
                    echo '<td>' . $i . '</td>'; // Row Heads
                    for ($j = 1; $j < $size; $j++) {
                        $isSquare = $i == $j ? "class=\"mid\"" : "";
                        echo "<td ${isSquare}>" . $j * $i . "</td>";
                    }
                    echo '</tr>';
                }
           
        echo"</table>";
        ?>
    </body>
  </html>