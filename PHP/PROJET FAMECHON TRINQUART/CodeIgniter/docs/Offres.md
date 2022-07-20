#Description du controller
Le controller Offre va permettre à l'entreprise de créer, modifier et supprimer une offre.

#Constructor
	public function __construct()
S'occupe de charger les librairies, les models et la vue d'en tête.  


#Index
	public function index()
Verifie que l'utilisateur est bien connecté en tant qu'entreprise et le redirige sur la page de connexion s'il n'est pas connecté.   
S'il est connecté alors index le redirige vers Offres/MesOffres.  

#Mes Offres
	public function MesOffres()
Redirige l'utilisateur vers la page principale si la session n'est pas celle d'une entreprise.  
  
Si l'utilisateur est connécté en tant qu'entreprise alors le controlleur vas afficher les Offres faites par cette entreprise.  
  

A partir de la l'entreprise pourras :  
- Soit cliquer sur Créer une offre dans le menu pour créer une nouvelle offre (appelle d' "Offres/CreateOffre").  
- Soit cliquer sur le liens "modifier l'offre" pour modifier cette offre.

#CreateOffre
	public function createOffre()
CreateOffre vas s'occuper d'afficher le formulaire pour créer une offre.
La fonction va ensuite récuperer les données du formulaire si elles sont correctes et les envoyer au modele via [insert_stage($data)](Modele.md#insert_stage) pour créer l'offre.

##La pièce jointe
L'utilisateur a la possibilité d'ajouter une pièce jointe via le formulaire.
La taille maximum d'une pièce jointe est de 5Mo et elle peut être de tout les types d'extension.

note : si la pièce jointe est un fichier php ou html lorsqu'on va vouloir la consulter, le navigateur vas interpreter le fichier au lieu de juste le visualiser.





