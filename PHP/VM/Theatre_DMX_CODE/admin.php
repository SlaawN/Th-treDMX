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
    include'BDD.php';
            $user2= new Bdd("","","","");
            $champLogin=$_SESSION["username"];
            $champMdp=$_SESSION["password"];              
            $user2->Connexion_BDD("192.168.65.221","THEATRE_DMX","dmx","dmx");                        
            $_SESSION['admin']=$user2->Admin("User",$champLogin,$champMdp);         
?>
<?php
    if(($_SESSION['admin'])==true) //Si la personne est admin alors le code s'execute sinon il est renvoyer à la page principale
    {
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
        try
        {
            $bdd = new PDO('mysql:host=192.168.65.221;dbname=THEATRE_DMX;charset=utf8', 'dmx', 'dmx'); //connection à la BDD
            //$bdd->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        } 
        catch(Exception $e)
        {
            // En cas d'erreur, on affiche un message et on arrête tout
            die('Erreur : '.$e->getMessage()); 
        }
?>
            <div id="tab">
                <center>
                    <table> <!-- Affichage tableau compte BaseDeDonnée -->
                        <td><b>Nom d'utilisateur</b></td>      
                        <td><b>Mot de passe</b></td>
                        <td><b>N° d'utilisateur</b></td>
                        <td><b>Admin</b></td>

                        <?php
                            $mdp="*****";
                            $result = $bdd->query("SELECT * FROM User "); //affichage en fonction du numéro de machine
                            while ($donnee = $result->fetch()) 
                            {
                                echo "</tr>";
                                echo "<td> ".$donnee['username']."</td> ";
                                echo "<td> ".$mdp."</td> ";
                                echo "<td> ".$donnee['ID_User']."</td> ";
                                echo "<td>".$donnee['admin']."</td>";
                                echo"</tr>";
                            }
                        ?>
                    </table>
                </center>
            </div>

            <div id="admin">
            <center>
			    <form method="POST" action="admin.php">
                
                    <div class=separation></div>
                <p>
                    <label for="ID_User">Numéro de l'Utilisateur à Supprimer : (ex:2)</label> 
                    <input type="number" name="ID_User"/>  
                </p>	
                
                    <input class=bouton type="submit" value="Supprimer">   	
                </form>  
            </center>
            <!-- Vérification avec le user index -->
                <?php
                    if(empty($_POST))
                    {
                        $_POST["ID_User"]=0;
                    }
                    $ID_User = $_POST["ID_User"];
                ?>
                    
                <?php
                    if (!empty($_POST["ID_User"]))
                    {
                        $result = $bdd->query("DELETE FROM User WHERE ID_User='$ID_User'");
            
                        print("<script type=\"text/javascript\">  setTimeout('location=(\"http://192.168.65.66/Theatre_DMX/admin.php\")' ,10); </script>");

                    }   
                ?>
        </div>

        
        <div id="modif">
            <center>
                <form method="GET" action="admin.php">
                    <p>
                        <div class="Modif">Modification</div>
                        <input type="number" name="ID_User" placeholder="Index"><br>
                        <input type="text" name="username" placeholder="Nouveau nom d'utilisateur">
                        <input type="password" name="password" placeholder="Nouveau Mot de Passe">
                    </p>
                    <input class=button type="submit" value="Valider">
                </form>
            </center>

            <?php //
                if(empty($_GET))
                    {
                        $_GET["username"]=0;
                        $_GET["password"]=0;
                        $_GET["ID_User"]=0;
                    }
                $username = $_GET["username"];
                $password = $_GET["password"];
                $user_index = $_GET["ID_User"];
            ?>
                    
            <?php //Verification si on est inscrit dans la BDD
                if (!empty($_GET["username"]) && (!empty($_GET["password"])) && (!empty($_GET["ID_User"])))
                    {
                        $result = $bdd->query("UPDATE User SET username = '$username',
                          Motdepasse = '$password' WHERE ID_User = '$ID_User'");
                          //header('Location: http://192.168.65.249/admin.php');
                        print("<script type=\"text/javascript\">  setTimeout('location=(\"http://192.168.65.66/Theatre_DMX/admin.php\")' ,10); </script>");

                    }
    }
    else 
    {   
        echo'<div id="erreur404" style="width : 100%;position: absolute;top: 50%;transform: translateY(-50%);text-align: center;color:#343434;font-family: "montserrat", sans-serif;">';
        echo'<h2>Sorry</h2>';
        echo'<h1 style="font-size: 160px; margin: 10; font-weight: 900; letter-spacing: 5px; background: url(/Theatre_DMX/Images/fond1.jpg)center no-repeat; 
        -webkit-text-fill-color: transparent; -webkit-background-clip: text;">Only Admin</h1>';
        echo"<p>You don't have the permission</p>";
        echo'<a href="/Theatre_DMX/Accueil.php" style="text-decoration: none; background: rgba(30, 144, 255, 0.6); color: white; padding: 12px 24px;
        display: inline-block; border-radius: 25px; font-size: 14px; text-transform: uppercase;">Retour Accueil</a>';
        echo'</div>';

    } 
    ?>

</body>
</html>