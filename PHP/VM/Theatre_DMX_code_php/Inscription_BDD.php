<?php
try
{
    $bdd = new PDO('mysql:host=192.168.65.221; dbname=THEATRE_DMX;charset=utf8','dmx','dmx');
}
catch(Exception $e)
{
    die('Erreur : '.$e->getMessage());
}

$req = $bdd->prepare('INSERT INTO User(Nom,Prenom,username,password) VALUES (?,?,?,?)');
$req->execute(array($_POST['Nom'],$_POST['Prenom'],$_POST['username'],$_POST['password']));

print("<script type=\"text/javascript\">  setTimeout('location=(\"http://192.168.65.66/Theatre_DMX/index.php\")' ,10); </script>");
?>