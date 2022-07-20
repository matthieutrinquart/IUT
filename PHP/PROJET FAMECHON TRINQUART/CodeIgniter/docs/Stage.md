#Description du controller
Stage vas s'occuper d'afficher toutes les offres ou juste l'offre sélectionnée.  

#Constructor
	public function __construct()
S'occupe de charger les librairies et les models utiles par la suite.

#Index
	public function index()
Dans un premier temps charge la vue StageHeader pour afficher le menu.
Puis demande au modele les offres et les affiches avec la vue "StageOffre.php".

Voir : [getoffre](Modele.md#getoffres)

#Voir offre
	public function voirOffre($id)
Stage/voirOffre permet d'afficher seulement une offre précise lorsque l'utilisateur clique sur "voir Offre".

Elle demande au modele l'offre, où l'id de l'offre est égale à l'id passé en parametre.  
Voir : [getoffreswhere](Modele.md#getoffreswhere)
	

