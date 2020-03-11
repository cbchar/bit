<?php

// *****************  conexion  *******************
class BDatos
{
  var $dbd;
  var $baseDat;
  var $sql;
  var $consulta;

  function BDatos()
  {
     $dbd = "";
     $baseDat = "";  
     $sql = "";
     $consulta = "";
  }

  function conectar()
  {
     $this->dbd = mysqli_connect("localhost", "root", "");

     if (!$this->dbd)
       die ("<h3>*** ERROR al conectar... :(-{ </h3>");

  }

  function escoger_BD($baseDat)
  {
    $this->baseDat = mysqli_select_db($this->dbd, $baseDat);
 
    if(!$this->baseDat)
       die("<h3>ERROR: al seleccionar</h3>".mysqli_errno());   
 
  }

  function contRegistro($tabla)
  {
     $this->sql = mysqli_query($this->dbd, "SELECT COUNT(*) from $tabla");
     $total=mysqli_fetch_array($this->sql);

     return $total;
  } 


  function insertarAlum($alumno)
  {   
     $this->sql = "insert into alumnos values('".$alumno->getCod()."',
                                             '".$alumno->getNom()."',
                                             '".$alumno->getSex()."'); ";
   
    
     $consulta = mysqli_query($this->dbd, $this->sql); 

     return $consulta;
  }  


  function buscarBD($tabla,$abuscar)
  {
   
     $this->sql="SELECT * from $tabla";

     if ($abuscar)
         $this->sql .= " WHERE nombre='$abuscar'";


     $consulta = mysqli_query($this->dbd, $this->sql);
    
     if(!$consulta)
     {
       die ("Error en la busqueda".mysqli_error());
     }

     return $consulta;  
  }


  function listarBD($consulta)
  {

       $colores_filas=array('#cccccc', 'lightblue');
       $ind_colores=0;
       $cont_lineas=1;

       echo " <table border=1 align='center'>";    
       echo " <tr>
                <td>No</td>
                <td>CODIGO</td>
         	<td>NOMBRE</td>
		<td>SEXO</td>  
		<td> Acciones </td>
              </tr>
            ";  

       while ($reg = mysqli_fetch_array($consulta, MYSQLI_ASSOC))
       {
          $ind_colores++;
          $ind_colores %= 2;
		  $dato=$reg{'nombre'};
          echo "<tr bgcolor=${colores_filas[$ind_colores]}>";
          
             echo "<td bgcolor='white'>$cont_lineas</td>";
             echo "<td>".$reg{'codigo'}."</td>";
   	     echo "<td>".$reg{'nombre'}."</td>";
	     echo "<td>".$reg{'sexo'}."</td>";
		 echo "<td> <a href='eliminar.php?dato=$dato'> Eliminar</a></td>";
          echo "</tr>";
          $cont_lineas++;
        }
 
        echo "</table>";

        if($cont_lineas==1) return false;
        return true;
     }


  function llenaAlumno($consulta, $alumno)
  { 
   
      $reg = mysqli_fetch_array($consulta);
   
      $alumno->setCod($reg{'codigo'});
      $alumno->setNom($reg{'nombre'});
      $alumno->setSex($reg{'sexo'});

      return $alumno;
  }


  function modificaAlum($tabla, $alumno)
  {


    echo $alumno->getCod()."<br>";
    echo $alumno->getNom()."<br>";
    echo $alumno->getSex()."<br>";
    echo $tabla."<br>";
 
    
     $this->sql = "UPDATE $tabla SET ";
     $this->sql.= "codigo='".$alumno->getCod()."', sexo='".$alumno->getSex()."'";
     $this->sql.= " WHERE nombre='".$alumno->getNom()."'";

     $res=mysqli_query($this->dbd, $this->sql);

      if (!$res) {
        echo "*** ERROR al actualizar ";//, mysqli_error();
        exit;
       }
      //echo "Modificado <u>", mysqli_affected_rows(), "</u> registro<br>";
         

  }

  function borrarReg($tabla, $abuscar)
  {
    $this->sql="DELETE FROM $tabla WHERE nombre='$abuscar'";
    $res = mysqli_query($this->dbd, $this->sql);
    
    return $res;
  }


  function cerrarBD()
  {
     mysqli_close($this->dbd);

  }

}







// *****************  ALUMNO  *******************

class Alumno{

  var $codigo;
  var $nombre;
  var $sexo;

  function Alumno()
  {
     $this->codigo = null;
     $this->nombre = "";
     $this->sexo = "";
  }

  function setCod($codigo)
  {
     $this->codigo = $codigo;  
  }

  function setNom($nombre)
  {
     $this->nombre = $nombre;
  }

  function setSex($sexo)
  {
     $this->sexo = $sexo;
  }

  function getCod()
  {
     return $this->codigo;
  }

  function getNom()
  {
     return $this->nombre;
  }

  function getSex()
  {
     return $this->sexo;
  }

}



// ***********  Funciones Fuera de objetos ***********

  function menu()
  { 
    echo " <font color='blue'> <h3> <center>
     <a href='menu.html'> 
            Regresar al menu 
     </center></h3></font></a> 

    ";
  }


  function pagina_anterior()
  {
    echo "<font color='blue'> <h3> <center>";
    echo "<a href='javascript:history.go(-1)'>&lt;&lt;volver atras</a><br>";
    echo "</center></h3></font>";
  }


?>