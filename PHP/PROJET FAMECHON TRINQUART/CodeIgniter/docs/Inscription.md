#Description du controleur
Le controleur Inscription sert a rentrer dans la base de donner tout les utilisateur qui s'inscrie entreprise et membre


#Constructor
	public function __construct()
S'occupe de charger les librairies et les models utiles par la suite.

#create_entreprise
	public function create_entreprise()
Il charge les vues "StageHeaderView" , "DivMainView" ,  "EndDivMainView" , "StageFooterView" qui permet une presentation jolie du site. Puis charge la vues "InscriptionEntrepriseView" qui affiche le formulaire pour rentrer les information de l'utilisateur. La fonction create_entreprise() recupère ensuite les information fournie et verirife que le mail fournie ne soit pas déjà sur la BDD et affiche une erreur si les mails sont les meme. Il rentre les information fournie dans la BDD a la classe T_USER a partir de [getuser](Modele.md#getuser). Il rentre par defaut a l'atribut USER_STATUT la valeur 'ENTREPRISE' Puis envoie un mail à l'admin pour avertir de l'inscription d'une entreprise.

#create_membre
	public function create_membre() 
Fonctionement similaire a [create_entreprise()](Inscription.md#create_entreprise). A la difference qu'il met par defaut a l'atribut USER_STATUT la valeur 'MEMBRE'et n'envoie pas de mail a l'admin.
	

