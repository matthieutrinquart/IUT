<?php
class Inscription extends CI_Controller 
{
	public function __construct()
	{
		parent::__construct();
		$this->load->helper('url');
		$this->load->library('session');		
	}
	
	public function create_entreprise() 
	{
		$titre['titre'] = 'Inscription Entreprise';
		$this->load->view('StageHeaderView',$titre);
		
        $this->load->view('DivMainView');
		$this->load->view('InscriptionEntrepriseView');
		$this->load->view('EndDivMainView');
		
        $this->load->model('StageModel');
        $data = array
		(
            'NOM' => $this->input->post('Nom'),
            'PRENOM' => $this->input->post('PRENOM'),
            'MAIL' => $this->input->post('mail'),
            'MDP' => sha1($this->input->post('mdp')),
            'TELEPHONE' => $this->input->post('tel'),
            'USER_STATUT' => 'ENTREPRISE',
            'RAISON_SOCIALE' => $this->input->post('raison'),
            'IS_ACTIV' => false,
            'DATE_NAISS' => null,
            'DIPLOME' => null
        );
		$p =  $this->StageModel->getUsers();
		$h = true ;
		$admin = null ;
		
		foreach  ( $p as $row ) 
		{ 
			if($data['MAIL'] == $row->MAIL)
			{
				$this->load->view('vue_erreur');
				$h = false ;
			}
			if("ADMIN" == $row->USER_STATUT)
			{
				$admin = $row->MAIL ;
			}
		}


		if ($h && $this->input->post('envoyer')=="Envoyer")
		{
			if(
			    $this->input->post('Nom') !== null && 
			    $this->input->post('PRENOM') !== null && 
			    $this->input->post('mail') !== null && 
			    $this->input->post('mdp') !== null &&
			    $this->input->post('tel') !== null &&
			    $this->input->post('raison') !== null &&
			   !empty($this->input->post('Nom')) && 
			   !empty($this->input->post('PRENOM')) && 
			   !empty($this->input->post('mail')) && 
			   !empty($this->input->post('mdp')) && 
			   !empty($this->input->post('tel')) && 
			   !empty($this->input->post('raison'))
			){
				mail($admin,"Depositaire ".$data['NOM'].' '.$data['PRENOM']."Veut creer un compte" ,'clicker sur le lien pour vous connecter et accepter ou refuser'.' '.$data['NOM'].' '.$data['PRENOM'].' '.base_url().'index.php/Connexion/login/');
				$this->StageModel->insert_entreprise($data);
				$this->load->helper('url');
				redirect('Connexion/login');
			}else
			{
				echo 'Erreur veuillez vous n\'avez pas tout saisis (dsl pour l\'erreur avec un echo )';
			}
			

		}
		$this->load->view('StageFooterView');

	}


	public function create_membre() 
	{
		$titre['titre'] = 'Inscription Membre';
		$this->load->view('StageHeaderView',$titre);
		
        $this->load->view('DivMainView');
		$this->load->view('InscriptionMembreView');
		$this->load->view('EndDivMainView');
		
		$this->load->model('StageModel');
		
		$data = array
		(
			'NOM' => $this->input->post('Nom'),
			'PRENOM' => $this->input->post('PRENOM'),
			'MAIL' => $this->input->post('mail'),
			'MDP' => sha1($this->input->post('mdp')),
			'TELEPHONE' => null,
			'USER_STATUT' => 'MEMBRE',
			'RAISON_SOCIALE' =>null ,
			'IS_ACTIV' => null,
			'DATE_NAISS' => null,
			'DIPLOME' => null
		);
		
		$p =  $this->StageModel->getUsers();
		$h = true ;
		
		foreach  ( $p as $row ) 
		{ 
			if($data['MAIL'] == $row->MAIL)
			{
				
				$this->load->view('vue_erreur');
				$h = false ;
			}
		}


		if ($h && $this->input->post('envoyer')=="Envoyer")
		{
			if(
			    $this->input->post('Nom') !== null && 
			    $this->input->post('PRENOM') !== null && 
			    $this->input->post('mail') !== null && 
			    $this->input->post('mdp') !== null &&
			   !empty($this->input->post('Nom')) && 
			   !empty($this->input->post('PRENOM')) && 
			   !empty($this->input->post('mail')) && 
			   !empty($this->input->post('mdp')) 
			)
			{   
				$this->StageModel->insert_entreprise($data);
				$this->load->helper('url');
				redirect('Connexion/login');
			}else
			{
				echo 'Erreur veuillez vous n\'avez pas tout saisis (dsl pour l\'erreur avec un echo )';
			}
		}
		$this->load->view('StageFooterView');
	}
}
?>