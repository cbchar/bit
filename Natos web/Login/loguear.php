<?php

session_start();
require 'conexion.php';

$remem= $_POST['remember'];
$usuario = $_POST['usuario'];
$clave = $_POST['clave'];

setcookie("recordaru", $usuario, time()+60*60*24*365);
$_COOKIE[recordaru];

$query = "SELECT COUNT(*) as contar from us where usuario='$usuario' and contraseña='$clave'";
$consulta = mysqli_query($conectar, $query);
$array = mysqli_fetch_array($consulta);

if($array['contar']>0){
  $_SESSION['username'] = $usuario;
  header ("location: carrito2.php");
}else{
  echo "<h1>Datos incorrectos</h1>";
}

if($remem){
  set_cookie('recordaru', $usuario, time()+60*60*24*365);
  }
  if(isset($_COOKIE['recordaru'])){
    $_SESSION['usuario']=$_COOKIE['recordaru'];
  }


?>
