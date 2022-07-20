#Pour installer le Site web il faut :
* extraire l'archive dans le dossier du serveur
* ajouter les droits de maniére récurssive dans tout le site. (0777)
* configurer le site dans les premieres lignes de install.php ; Il faut saisir les parametres de la BDD ainsi que les données de l'administrateur.
* Lancez la page http://www.UrlDuSite.com/leDossierOuIlYALeProjet/install.php
* vous allez normalement être rediriger vers la page principale du site.
* vérifiez que la Base de Donnée a été correctement créer et que le fichier CodeIgniter/application/config/database.php n'est pas vide avec les bon paramètres
* Supprimer les fichiers install.php et script.sql