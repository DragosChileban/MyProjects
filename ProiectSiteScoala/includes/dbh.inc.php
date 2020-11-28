<?php
	
$servername = "localhost";
$dBUsername = "root";
$dBPassword = "";
$dBName = "ProiectSiteScoala";

$conn = mysqli_connect($servername, $dBUsername, $dBPassword, $dBName);

if (!$conn) {
	die("Conexiune pierduta: ".mysqli_connect_error());
}