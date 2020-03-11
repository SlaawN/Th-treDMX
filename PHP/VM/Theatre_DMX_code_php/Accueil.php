<?php
    session_start();
?>
<html>
<head>
<meta charset="utf-8">
<!-- importer le fichier de style -->
<link rel="stylesheet" href="style/menu.css" media="screen" type="text/css" />
<link rel="icon" href="Images/dmx.png" type="image/png">
<link rel="manifest" href="%PUBLIC_URL%/manifest.json" />
<link rel="shortcut icon" href="%PUBLIC_URL%/favicon.ico" />
<script src="https://unpkg.com/react@16/umd/react.production.min.js"></script>
<script src="https://unpkg.com/react-dom@16/umd/react-dom.production.min.js"></script>
<script src="https://unpkg.com/babel-standalone@6.15.0/babel.min.js"></script>
</head>
<body>
<?php   
        if (isset($_POST['connexion'])) //Condition pour vérifier les utilisateurs 
        {
            include'BDD.php';
            $user2= new Bdd("","","","");
            $champLogin=$_POST["username"];
            $champMdp=$_POST["password"];              
            $user2->Connexion_BDD("192.168.65.221","THEATRE_DMX","dmx","dmx");                        
            $_SESSION['User']=$user2->Autorisation("User",$champLogin,$champMdp);         
            $_SESSION['username']=$champLogin;
            $_SESSION['password']=$champMDP;
        }
        
        if (!isset($_SESSION['username']))
        {
            print("<script type=\"text/javascript\">  setTimeout('location=(\"http://192.168.65.66/Theatre_DMX/Accueil.php\")' ,10); </script>");
        }
           
    if ($_SESSION['User']==true)  //Condition si l'utilisateur est bien connecté 
        {  
            
            if($_SESSION['username'] !== ""){
                $user = $_SESSION['username'];
                // affiche un message de bienvenue
                //echo "<center style='color:black;'>Bonjour $user</center>"; 
                //echo "<center style='color:#1E90FF;'><u>Bienvenue sur le Projet GPS/DMX</u></center>";
            }
?>


<div class="bouton">
	<div class="row">
	<div class="wrapper">
    <a href='Accueil.php'><div class="example-2">Accueil</div>
    </div></a>
    <a href='https://jo1b4.csb.app/'><div class="example-2">Pilotage</div>
    </div></a>
    <a href='admin.php'><div class="example-2">Administration</div>
    </div></a>
    <a href='aide.php'><div class="example-2">Documents</div>
    </div></a>
    <a href='deco.php'><div class="example-1">Déconnexion</div>
    </div></a>
    <div style="clear: both;"></div>	
	</div>
</div>

        <?php
        } else 
            {
                print("<script type=\"text/javascript\">  setTimeout('location=(\"http://192.168.65.66/Theatre_DMX/index.php\")' ,10); </script>");
        ?>
        
        
            
        <?php
            }
        ?>

</body>
</html>

