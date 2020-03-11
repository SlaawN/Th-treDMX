<?php

    class BDD 
    {
        	//variable pour représentant la bdd 
		
		Private $_bdd = null;
		//Accesseurs ------------
        public function getBase()
        {
            if(!is_null($this->_bdd))
            {			
				return $this->_bdd;
            }else
            {
				echo "Base Non accessible";
				return null;
			}		
		}

		//Constructeur
		/*
			$ip_bdd        Adresse IP du server MySQLQ
			$name_bdd      Nom de la base de donnée
			$user_bdd      User privilégié de la BDD
			$mdp_bdd       Mdp du User Privilégié
		*/

        function Connexion_BDD($ip_bdd,$name_bdd,$user_bdd,$mdp_bdd)
        {
            try
            {
				$this->_bdd = new PDO('mysql:host='.$ip_bdd.';dbname='.$name_bdd.';charset=utf8',$user_bdd,$mdp_bdd);
			}
			catch (Exception $e){
				$this->_bdd = null;
	        	echo "<p>".$e->getMessage()."</p>";
			}
		}

		//fonction connection a la bdd
		/*
			$LoginCompare  login du visiteur
			$mdp_bdd       Mdp du visiteur
			$table         table des users
			$champLogin    champ du login
			$champMdp      champ du Mdp
		*/
		
		// verification de compte sur la bdd retourne true si oui false si non
        public function Autorisation($table,$champLogin,$champMdp) 
        {
            if(!is_null($this->_bdd))
            {
				$request=$this->_bdd->query("SELECT username FROM `".$table."` WHERE username='$champLogin' AND password='$champMdp'");                     					
					
				 if ($request->rowCount()==1)
			 	 {
				 	return true;
			 	 }
			return false; 
			}	 
        }
        
        public function Admin($table,$champLogin,$champMdp) 
        {
            if(!is_null($this->_bdd))
            {
				$request=$this->_bdd->query("SELECT username FROM `".$table."` WHERE username='$champLogin' AND password='$champMdp' and admin =1");                     					
					
				 if ($request->rowCount()==1)
			 	 {
				 	return true;
			 	 }
			return false; 
			}	 
        }
    }