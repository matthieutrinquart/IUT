<?php
class Stage extends CI_Controller
{
	public function __construct()
	{
		parent::__construct();
		$this->load->helper('url');
		$this->load->library('session');
		$this->load->model('StageModel');
	}
	
	public function index()	//fonction appellé par défaut
	{
		if(isset($this->session->message))
			unset($_SESSION['message']);
		
		
		$data['offre'] = $this->StageModel->getOffres();
		$data['voirOffre'] = 'Voir';
		$titre['titre'] = 'Accueil';
		$this->load->view('StageHeaderView',$titre);
		
		if(isset($this->session->USER_STATUT))
		{
			if($this->session->USER_STATUT == 'MEMBRE')
			{
				$UserInfo['NOM'] = $this->session->NOM;
				$UserInfo['PRENOM'] = $this->session->PRENOM;
				$this->load->view('StageUserInfoView',$UserInfo);
			}else if($this->session->USER_STATUT == 'ENTREPRISE')
			{
				$UserInfo['NOM'] = $this->session->NOM;
				$UserInfo['PRENOM'] = $this->session->PRENOM;
				$this->load->view('StageUserInfoView',$UserInfo);
			}
			else if($this->session->USER_STATUT == 'ADMIN')
			{
				$UserInfo['NOM'] = $this->session->NOM;
				$UserInfo['PRENOM'] = $this->session->PRENOM;
				$this->load->view('StageUserInfoView',$UserInfo);
			}
		}
		
		$data['like'] = $this->StageModel->getlike();
		foreach( $data['offre'] as $o)
        {
			
			if($this->input->post('Liker')=="liker")
			{
				$data2['ID_OFFRE'] =  $this->input->post('id_offre') ;
				$data2['ID_USER'] = $this->session->ID_USER ;
				$this->StageModel->insertlike($data2);
				redirect('Stage/') ;

			}
			if($this->input->post('Dislike')=="dislike")
			{
				$data2['ID_OFFRE'] =  $this->input->post('id_offre') ;
				$data2['ID_USER'] = $this->session->ID_USER ;
				$this->StageModel->deletelike($data2);
				redirect('Stage/') ;

			}
		}
	
		$data['commentaire'] = $this->StageModel->getCommentaires();
		
	//	$this->load->view('StageOffreView',$data);
	//	$this->load->view('StageFooterView');
		
		if ($this->input->post('envoyer')=="Envoyer")
		{
			// print_r($this->StageModel->getIdAdmin());
			// $ID_USER = $this->StageModel->getIdAdmin()
			$values = array
			(
				'ID_OFFRE' => $this->input->post('ID_OFFRE'),
				'ID_USER'  => $this->StageModel->getIdAdmin(),
				'TEXTE'    => $this->input->post('commentaire')
			);
			
			$this->StageModel->insert_commentaire($values);
			redirect('Stage/');
		}
		$this->load->view('StageOffreView',$data);
		$this->load->view('StageFooterView');
		
	}
	
	public function voirOffre($id)
	{
		$titre['titre'] = 'Information de l\'offre '.$id;
		$this->load->view('StageHeaderView',$titre);
		
		if(isset($this->session->USER_STATUT))
		{
			if($this->session->USER_STATUT == 'MEMBRE')
			{
				$UserInfo['NOM'] = $this->session->NOM;
				$UserInfo['PRENOM'] = $this->session->PRENOM;
				$this->load->view('StageUserInfoView',$UserInfo);
			}else if($this->session->USER_STATUT == 'ENTREPRISE')
			{
				$UserInfo['NOM'] = $this->session->NOM;
				$UserInfo['PRENOM'] = $this->session->PRENOM;
				$this->load->view('StageUserInfoView',$UserInfo);
			}
			else if($this->session->USER_STATUT == 'ADMIN')
			{
				$UserInfo['NOM'] = $this->session->NOM;
				$UserInfo['PRENOM'] = $this->session->PRENOM;
				$this->load->view('StageUserInfoView',$UserInfo);
			}
		}
		$where = array
		(
			'ID_OFFRE' => $id
		);
		
		$data['voirOffre'] = 'Retour';
		
		
		$data['offre'] = $this->StageModel->getOffresWhere($where);
		$data['commentaire'] = $this->StageModel->getCommentairesWhere($where);
		//$data['commentaire'] = $this->StageModel->getCommentairesWhere($where);
		
		$this->load->view('StageOffreView',$data);
		$this->load->view('StageFooterView');
		
	}
	
	public function tests()
	{
		echo base_url();
	}
	
}
?>