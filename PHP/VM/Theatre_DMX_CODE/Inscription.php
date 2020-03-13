<!DOCTYPE html>
<html lang="fr">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <meta http-equiv="X-UA-Compatible" content="ie=edge" />
    <title>Theatre_DMX</title>
    <link rel="icon" href="Images/dmx.png" type="image/png">
    <link rel="stylesheet" href="style/form.css" />
    <script
      src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"
      charset="utf-8"
    ></script>
  </head>

  <body>
    <form action="Inscription_BDD.php" class="login-form" method="POST">
      <h1>Inscription</h1>

      <div class="txtb">
        <input type="text" name="Nom" required/>
        <span data-placeholder="Nom"></span>
      </div>

      <div class="txtb">
        <input type="text" name="Prenom" required/>
        <span data-placeholder="Prenom"></span>
      </div>

      <div class="txtb">
        <input type="text" name="username" required/>
        <span data-placeholder="Identifiant"></span>
      </div>

      <div class="txtb">
        <input type="password" name="password" required/>
        <span data-placeholder="Mot de passe"></span>
      </div>

      <input type="submit" class="logbtn" value="S'enregistrer" />

      <div class="bottom-text">
        Vous avez déjà un compte -> <a href="index.php">Connexion</a>
      </div>
    </form>

    <script type="text/javascript">
      $(".txtb input").on("focus", function() {
        $(this).addClass("focus");
      });

      $(".txtb input").on("blur", function() {
        if ($(this).val() == "") $(this).removeClass("focus");
      });
    </script>
  </body>
</html>
