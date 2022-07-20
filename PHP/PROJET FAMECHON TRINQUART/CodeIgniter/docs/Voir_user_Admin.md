#Description du controleur
Le controleur Voir_user_Admin permet à l'admin de voir , supprimer et modifier un utilisateur.


#Constructor
	public function __construct()
S'occupe de charger les librairies et les models utiles par la suite.

#index
		public function index()	
redirige vers la fonction [affichage()](Voir_user_Admin.md#affichage).

#affichage
		public function affichage()	
Charge les vues 'StageHeaderView' , 'DivMainView' et 'EndDivMainView'.La fonction récupère la table T_USER de la BDD grace a [getUsers()](Modele.md#getuser) et les fournie a la vue 'AdminViews' qui affichera un tableau des utilisateur.Redirige vers [modifier($h)](Voir_user_Admin.md#Modifier) si l'admin click sur modifier.Redirige vers [supprimer($h)](Voir_user_Admin.md#Supprimer) si l'utilisateur click sur supprimer.

#Modifier
       public function modifier($h)	
Fonctionement similaire a [affichage_Entreprise()](Profile.md#affichage_entreprise) et [affichage_Membre()](Profile.md#affichage_Membre) mais vue par l'admin. la fonction veririfie si l'utilisateur selectionner est une entreprise et un membre pour afficher la vue "ModifierViews_membre" ou "ModifierViews_Entreprise_Admin".Si l'utilisateur est une entreprise l'admin peut verifier si l'entreprise a était valider et peut la validé ou la dévalidé en cliquant sur la checkbox.En cliquant sur modifier l'admin sera rediriger vers [affichage()](Voir_user_Admin.md#affichage).
	

#Supprimer
    public function supprimer($h)	
La fonction utilise la methode [DeleteUser($h)](Modele.md#deleteuser) qui supprime un utilisateur(en cascade) et redirige vers [affichage()](Voir_user_Admin.md#affichage).
	



