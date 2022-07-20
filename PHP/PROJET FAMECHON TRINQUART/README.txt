Installation du site :

-extraire l'archive dans le dossier du serveur

-ajouter les droits de maniére récurssive dans tout le site. (0777)

-configurer le site dans les premieres lignes de install.php ; Il faut saisir les parametres de la BDD ainsi que les données de l'administrateur.

-Lancez la page http://www.UrlDuSite.com/leDossierOuIlYALeProjet/install.php

-vous allez normalement être rediriger vers la page principale du site.

-vérifiez que la Base de Donnée a été correctement créer et que le fichier CodeIgniter/application/config/database.php n'est pas vide avec les bon paramètres

-Supprimer les fichiers install.php et script.sql



Génération de la doc :


- Installez une version de python que Mkdocs supporte (https://www.mkdocs.org/)

- Installez mkdocs via pip (voir la doc de Mkdoc)

- ouvrez un cmd, allez dans le répértoire CodeIgniter, puis tappez mkdocs build

- Vous devriez voir apparaitre un dossier site, Mettez le sur un serveur pour le consulter.

Note : si vous voulez voir la doc sans la "construire" vous pouvez ecrire mkdocs serve a la place.
Rendez vous ensuite sur http://127.0.0.1:8000
Vous devriez voir le site apparaitre.