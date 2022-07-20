#Description du controleur
Le controleur Profile permet a un utilisateur de modifier sont profile


#Constructor
	public function __construct()
S'occupe de charger les librairies et les models utiles par la suite et charge la vue "StageHeaderView" pour rendre le site jolie.

#affichage_Entreprise
	public function affichage_Entreprise()
Récupère les Session et tes fournie a la vue "ModifierViews_Entreprise" qui affiche le formulaire pour modifier l'utilisateur avec tout les informations prealabrement récuperer dans la session. Quand l'utilisateur click sur 'modifier' le controleur récupère les informations du formulaire tout en verifiant si le mail et pas déjà utiliser(affiche un message d'erreur si le mail et le meme). il rentre les informations dans la BDD grace a la fonction [UpdateUser($data,$id)](Modele.md#updateuser)

#affichage_Membre
	public function affichage_Membre()
Fonctionement similaire a [affichage_Entreprise()](Profile.md#affichage_entreprise). A la difference qu'il utilise la vue "ModifierViews_membre"

#affichage_Admin
	 public function affichage_Admin()
Fonctionement similaire a [affichage_Entreprise()](Profile.md#affichage_entreprise) et [affichage_Membre()](Profile.md#affichage_Membre). A la difference qu'il utilise la vue "ModifierViews_Admin"
	

