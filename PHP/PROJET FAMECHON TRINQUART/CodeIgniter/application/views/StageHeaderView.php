<!doctype html>
<html lang="fr">
	<head>
		<meta charset = "UTF-8">
		<link rel="stylesheet" type="text/css" href="<?php echo base_url();?>css/Style.css" />
		<title><?=$titre ?></title>
	</head>
	<body>
		<div class="page">			
			<div class="header">
				<nav>
					<ul id="menu">
							<li><?php echo anchor("Stage/", "Accueil")?></li>
						<?php if(!isset($_SESSION['USER_STATUT'])):?>
							<li><?php echo anchor("Inscription/create_membre", "S'inscrire (Membre)")?></li>
							<li><?php echo anchor("Inscription/create_entreprise", "S'inscrire (Entreprise)")?></li>
							<li><?php echo anchor("Connexion/login", "Se connecter")?></li>
						<?php endif; ?>
						<?php if(isset($_SESSION['USER_STATUT']) && $_SESSION['USER_STATUT'] == 'ENTREPRISE'):?>
							<li><?php echo anchor("Offres/", "Créer une offre")?></li>
							<li><?php echo anchor("Offres/MesOffres", "Mes offres")?></li>
							<li><?php echo anchor("Connexion/logoff", "Se déconnecter")?></li>
							<li><?php echo anchor("Profile/affichage_Entreprise", "Modifier Profil")?></li>
						<?php endif; ?>
						<?php if(isset($_SESSION['USER_STATUT']) && $_SESSION['USER_STATUT'] == 'MEMBRE'):?>
							<li><?php echo anchor("Connexion/logoff", "Se déconnecter")?></li>
							<li><?php echo anchor("Profile/affichage_Membre", "Modifier Profil")?></li>
						<?php endif; ?>
						<?php if(isset($_SESSION['USER_STATUT']) && $_SESSION['USER_STATUT'] == 'ADMIN'):?>
							<li><?php echo anchor("Connexion/logoff", "Se déconnecter")?></li>
							<li><?php echo anchor("Profile/affichage_Admin", "Modifier Profil")?></li>
							<li><?php echo anchor("Voir_user_Admin/", "Voir utilisateur")?></li>
						<?php endif; ?>
					</ul>
				</nav>
			</div>	