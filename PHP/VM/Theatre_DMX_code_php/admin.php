<html>
<head>
</head>
<body>
<?php
    session_start();
    include'BDD.php';
            $user2= new Bdd("","","","");
            $champLogin=$_POST["username"];
            $champMdp=$_POST["password"];              
            $user2->Connexion_BDD("192.168.65.221","THEATRE_DMX","dmx","dmx");                        
            $_SESSION['admin']=$user2->Autorisation("User",$champLogin,$champMdp);         
?>
</body>
</html>