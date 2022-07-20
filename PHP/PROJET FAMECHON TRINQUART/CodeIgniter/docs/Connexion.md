#Description du controller
Connexion vas s'occuper de charger la page de connexion et de verifier que l'utilisateur à bien rentré ses données correctement.  
Le controller va aussi s'occuper de déconnecter l'utilisateur lorsqu'il le souhaite.   

#Constructor
	public function __construct()
S'occupe de charger les librairies et les models utiles par la suite.

#Login
	public function login()
Dans un premier temps verifie si la Session existe. Si c'est le cas l'utilisateur sera rediriger vers la page principale.  
Ensuite Login vas charger la vue du formulaire d'inscription, avec un message d'erreur si l'utilisateur a déja essayer de se connecter.  
Une fois les données du formulaire récuperé, Login vas demander à la base de donnée si l'utilisateur existe et si les identifiants sont les bons.  
Si c'est le cas alors on rentre dans la Session les paramètres de l'utilisateur.
Si l'authentification a réussi alors l'utilisateur est redirigé vers "Stage/"


Voir : [getUsers](Modele.md#getUsers)

#LogOut
	public function logOut()
LogOut va s'occuper comme son nom l'indique, de déconnecter l'utilisateur et de supprimer les données en Session.  
Une fois fait, Logout redirige vers "Stage/".
