<?php
session_start();
$usuario = $_SESSION['username'];

if(!isset($usuario)){
  header("location:login.php");
}else{
  echo "<h1>Bienvenido $usuario </h1>";

  echo "<a href='salir.php'>Salir</a>";
}
?>
