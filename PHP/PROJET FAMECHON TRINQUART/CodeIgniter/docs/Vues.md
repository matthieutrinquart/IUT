Dans cette page nous aborderons seulement les vues les plus utilisé et les vues nécessitant une légére expliquation

#StageHeaderView
StageHeaderView est la vue qui va servir a afficher l'en tête. Elle est utilisé par tout les controlleurs.
Chaque controlleur va envoyer le titre de la page à cette vu.  
La vue vérifie ensuite les sessions pour afficher un menu dynamique.

#StageOffreView
StageOffreView s'occupe d'afficher les offres.  
Elle est appellé par "Stage" et "Offres" pour afficher les offres de stages de maniére cohérante aux données reçue.

#ConnexionForm
Affiche le formulaire de connexion et le message d'erreur s'il existe.

#InscriptionEntrepriseView
Affiche le formulaire d'inscription pour les entreprises.

#InscriptionMembreView
Affiche le formulaire d'inscription pour les membres.

#OffreFormView
Affiche le formulaire de création d'une offre de stage avec un message d'erreur s'il existe.

#OffreModificationForm
Affiche le formulaire de modification des offres avec des données déja rempli.
le controlleur Offre vas envoyer les informations concernant l'offre a cette vue qui va ensuite charger le formulaire avec les données envoyé par le controlleur.

#StageFooterView
Un simple footer avec le notre nom dessus.

#AdminViews
Affiche sous forme de tableau les utilisateurs de la BDD

#InscriptionEntrepriseViews, InscriptionMembreViews
Et un formulaire d'inscription pour les entreprises et les membres.

#ModifierViews_Admin, ModifierViews_Entreprise, ModifierViews_membre
Formulaire de modification de l'admin , Entreprise et membre

#ModifierViews_Entreprise_Admin
Formulaire de modification de l'entreprise par l'admin

#vue_erreur
Erreur si le mail est déjà sur la BDD

#entrepriseNO
Erreur si l'admin n'a pas validé une entreprise