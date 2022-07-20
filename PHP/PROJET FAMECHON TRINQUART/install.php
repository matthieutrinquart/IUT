<?php
//Veuillez saisir les parametres du serveurs avec les parametres de l'ADMIN
$hostname = 'localhost';
$Port = '3306' ;
$username = 'A2019M3104G07';
$password = '._hNmhzv';
$database = 'A2019M3104G07';

$NOM_ADMIN = 'NOM_ADMIN';
$PRENOM_ADMIN = 'PRENOM_ADMIN';
$MAIL_ADMIN = 'MDP_ADMIN@MDP_ADMIN.fr';
$MDP_ADMIN = sha1('MDP_ADMIN');


// ATTENTION NE PAS MODIFIER APRES CETTE LIGNE 


// fichiers a supprimer pour les test :
// vider database.php
// vider la BDD
// Ne pas oublier que ce fichier et script.sql se supprimment automatiquement donc penser a faire une sauvegarde avant










	define('DB_HOST', $hostname);
	define('DB_PORT', $Port);
	define('DB_DATABASE', $database);
	define('DB_USERNAME', $username);
	define('DB_PASSWORD', $password);
	try
	{
		$PDO_BDD = new PDO('mysql:host='.DB_HOST.';port='.DB_PORT.';dbname='.DB_DATABASE, DB_USERNAME, DB_PASSWORD);
		$PDO_BDD->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$PDO_BDD->exec("SET NAMES 'utf8'");
	}
	catch(Exception $e)
	{
		echo 'Erreur : '.$e->getMessage().'<br />';
		echo 'N° : '.$e->getCode();
		exit();
	}

$sql = file_get_contents('script.sql');
$qr = $PDO_BDD->exec($sql);

$PDO_BDD->query($sql);

$requeteAdmin = "INSERT INTO `T_USER` (`ID_USER`, `NOM`, `PRENOM`, `MAIL`, `MDP`, `TELEPHONE`, `USER_STATUT`, `RAISON_SOCIALE`, `IS_ACTIV`, `DATE_NAISS`, `DIPLOME`) VALUES (NULL, "."'$NOM_ADMIN'".", "."'$NOM_ADMIN'".", "."'$MAIL_ADMIN'".", "."'$MDP_ADMIN'".", NULL, 'ADMIN', NULL, NULL, NULL, NULL)";

$PDO_BDD->query($requeteAdmin);

//Changer database de codeigniter
$fichierTexte=
"<?php
defined('BASEPATH') OR exit('No direct script access allowed');

\$active_group = 'default';
\$query_builder = TRUE;

\$db['default'] = array(
	'dsn'	=> '',
	'hostname' => '$hostname',
    'username' => '$username',
    'password' => '$password',
    'database' => '$database',
	'dbdriver' => 'mysqli',
	'dbprefix' => '',
	'pconnect' => FALSE,
	'db_debug' => (ENVIRONMENT !== 'production'),
	'cache_on' => FALSE,
	'cachedir' => '',
	'char_set' => 'utf8',
	'dbcollat' => 'utf8_general_ci',
	'swap_pre' => '',
	'encrypt' => FALSE,
	'compress' => FALSE,
	'stricton' => FALSE,
	'failover' => array(),
	'save_queries' => TRUE
);";

file_put_contents('CodeIgniter/application/config/database.php', $fichierTexte, FILE_APPEND);

//file_put_contents('ton_fichier.txt', PHP_EOL.$add, FILE_APPEND);
//Install.php lance 

unlink("script.sql");
unlink("install.php");


header('Location: CodeIgniter/');

?>