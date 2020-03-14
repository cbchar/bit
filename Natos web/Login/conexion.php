<?php
//Declaramos el nombre del servidor
$srvn = "127.0.0.1";
//Declaramos nombre de usuario y password de MYSQL
$username = "root";
$password = "";
//declaramos nombre de DB
$dtb = "login";

//Creamos la conexión
$conectar = mysqli_connect($srvn, $username, $password, $dtb);

/* //checamos la conexión
 if (!$conectar){
   die("Conexión Fallida: ".mysqli_connect_error());
 }
 echo "Conexión exitosa";
 mysqli_close($conectar);*/
?>
