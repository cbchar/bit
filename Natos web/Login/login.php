<?php
  $dato = $_COOKIE['recordaru'];
 ?>

<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>L O G I N</title>
  </head>
  <body>


    <form action="loguear.php" method="post">
      <center>
      <label>Usuario</label></br>
      <input type="text" name="usuario" value="<?=$dato?>" placeholder="Contraseña" required>
      <br><label>Contraseña</label>
      <br><input type="password" name="clave" placeholder="Contraseña" required></br>
      <input type="checkbox" name="remember" values="">
      <label>Recordar usuario</label>
      <br><input type="submit" name="enviar" placeholder="Iniciar sesión">
    </form>
  </body>
</html>
