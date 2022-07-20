## Description du fonctionnement du site :

###Composition du site
* [Stage](/Stage/)
	* Stage/index	  -> Accueil du site avec toute les offres affichées.
	* Stage/voirOffre  -> Affiche les détails de l'offre séléctionné avec en parametre l'id de l'offre

* [Inscription](/Inscription/)
	* Inscription/create_entreprise -> Page de formulaire pour la création (inscription) d'un compte entreprise
	* Inscription/create_membre -> Page de formulaire pour la création (inscription) d'un compte membre
	
* [Connexion](/Connexion/)
	* Connexion/login -> Permet la connexion d'un utilisateur
	* Connexion/logout -> Permet la deconnexion d'un utilisateur
	
* [Offres](/Offres/)
	* Offres/index -> permet la redirection vers la page principale au cas ou un utilisateur essaierait d'y acceder sans être une entreprise.
	* Offres/CreateOffre -> Permet a l'entreprise de créer une offre de stage.
	* Offres/MesOffres -> Permet a l'entreprise de consulter ses offres de stages.
	* Offres/ModifierOffre -> Permet a l'entreprise de modifier/supprimer une offre que l'entreprise a créer

* [Profil](/Profile/)
	* Profil/affichage_Entreprise -> Permet d'afficher la liste des Entreprises 
	* Profil/affichage_Membre -> Permet d'afficher la liste des Membres 
	* Profil/affichage_Admin -> Permet d'afficher la liste de/des Admin(s) 