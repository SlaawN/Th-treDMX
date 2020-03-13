
<?php 

session_start();
session_unset();
session_destroy();

print("<script type=\"text/javascript\">  setTimeout('location=(\"http://192.168.65.66/Theatre_DMX/index.php\")' ,10); </script>");

?>