<?php
	Class Connexion extends CI_Controller
	{	
	
		public function __construct()
		{
			parent::__construct();
			$this->load->library('session');
			$this->load->helper('url');
		}
		
		public function index()	//fonction appellé par défaut
		{
			$this->login();
		}
		
		public function login()	//A faire ne pas oublier de rediriger l'utilisateur vers la page de stage s'il est deja connecté
		{
			if(isset($this->session->ID_USER))
				redirect('Stage/');
			
			//echo "truc".$this->session->message."truc";
			//chargement de l'en tete
			$data['titre'] = 'Connexion';
			$this->load->view('StageHeaderView',$data);
			
			//chargement de la page de connexion
			
			if(isset($this->session->message))
			{
				$data['Message'] = $this->session->message;
			}else
			{
				$data['Message'] = 'Veuillez saisir vos identifiants : ';
			}
			
			$this->load->view('DivMainView');
			$this->load->view('ConnexionForm',$data);
			$this->load->view('EndDivMainView');
			
			//chargement du model pour recuperer les utilisateurs 
			$this->load->model('StageModel');
			$user = $this->StageModel->getUsers();
			
			//On stocke le mail et le mot de passe que l'utilisateur a rentré
			$mail = $this->input->post('login');
			$pwd = $this->input->post('pwd');
			
			$pwd = sha1($pwd);
			
			//variable pour savoir si l'authentification a reussi
			$is_login_successfull = false;
			
			//on parcours la BDD des utilisateurs
			foreach($user as $u)
			{
				if($u->MAIL == $mail && $pwd == $u->MDP)
				{
					echo 'Le nom d\'utilisateur et le pwd sont bon';
					session_start();
					$this->session->ID_USER = $u->ID_USER;
					$this->session->NOM = $u->NOM;
					$this->session->PRENOM = $u->PRENOM;
					$this->session->MAIL = $u->MAIL;
					$this->session->MDP = $u->MDP;
					$this->session->TELEPHONE = $u->TELEPHONE;
					$this->session->USER_STATUT = $u->USER_STATUT;
					$this->session->RAISON_SOCIALE = $u->RAISON_SOCIALE;
					$this->session->IS_ACTIV = $u->IS_ACTIV;
					$this->session->DATE_NAISS = $u->DATE_NAISS;
					$this->session->DIPLOME = $u->DIPLOME;
					
					$is_login_successfull = true;
				}
			}
			
			//Si l'authentification a reussi
			if($is_login_successfull)
			{
				echo "Identifiants bon";
				redirect('Stage/');
			}else
			{
				$this->session->message = 'Identifiants incorrects';
			}
			$this->load->view('StageFooterView');

		}
		
		public function logoff()	//A faire ne pas oublier de rediriger l'utilisateur vers la page de stage s'il n'est pas connecté
		{
			if(!isset($this->session->USER_STATUT))
			{
				redirect('Stage/');
			}
			
			// unset($this->session->ID_USER);
			// unset($this->session->NOM);
			// unset($this->session->PRENOM);
			// unset($this->session->MAIL);
			// unset($this->session->MDP);
			// unset($this->session->TELEPHONE);
			// unset($this->session->USER_STATUT);
			// unset($this->session->RAISON_SOCIALE);
			// unset($this->session->IS_ACTIV);
			// unset($this->session->DATE_NAISS);
			// unset($this->session->DIPLOME);
			
			
			unset
			(
				$_SESSION['ID_USER'],
				$_SESSION['NOM'],
				$_SESSION['PRENOM'],
				$_SESSION['MAIL'],
				$_SESSION['MDP'],
				$_SESSION['TELEPHONE'],
				$_SESSION['USER_STATUT'],
				$_SESSION['RAISON_SOCIALE'],
				$_SESSION['IS_ACTIV'],
				$_SESSION['DATE_NAISS'],
				$_SESSION['DIPLOME'],
				$_SESSION['message']
			);
			
			redirect('Stage/');
		}
	}
?>