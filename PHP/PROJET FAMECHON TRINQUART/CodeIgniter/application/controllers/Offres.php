<?php
class Offres extends CI_Controller
{
	public function __construct()
	{
		parent::__construct();
		$this->load->helper(array('url','form'));
		$this->load->library('session');
		
		//echo $this->upload->data();
		
		$titre['titre'] = 'Creation d\'offres';
		$this->load->view('StageHeaderView',$titre);
		
		$UserInfo['NOM'] = $this->session->NOM;
		$UserInfo['PRENOM'] = $this->session->PRENOM;
		
		$this->load->view('StageUserInfoView', $UserInfo);
	}
	
	public function index()	//fonction appellé par défaut
	{
		if (!$this->session->USER_STATUT == 'ENTREPRISE')
		{
			redirect('Stage/');	
		}else
		{
			$this->CreateOffre();
		}
	}
	
	public function CreateOffre()
	{
		if (!$this->session->USER_STATUT == 'ENTREPRISE')
		{
			redirect('Stage/');	
		}
		if ($this->session->IS_ACTIV == 0)
		{
			$this->load->view('entrepriseNO');
		}
		else{
		
		
		
		$data = array
		(
			'ID_ENTREPRISE' => $this->session->ID_USER,
			'titre' => $this->input->post('Titre'),
			'DATE_DEBUT' => $this->input->post('dateDebut'),
			'duree' => $this->input->post('duree'),
			'Mission' => $this->input->post('Mission'),
			'Contact' => $this->input->post('Contact'),
			//'PJ' => $this->input->post('PJ'),		//on récupere seulement le nom de la piece jointe
			'PJ' => NULL,	//<------------------------a changer plus tard-------------
			'COMPLEMENT_INFO' => $this->input->post('complInfo')
		);
		
		//JE TRY QUELQUE CHOSE
		$config['upload_path']          = './PJ/';
		$config['allowed_types']        = '*';
		$config['max_size']             = 5000;
		$config['max_width']            = 0;
		$config['max_height']           = 0;

		$this->load->library('upload', $config);
		
		$this->upload->initialize($config);
		
		$error['error']='';
		
		if (!$this->upload->do_upload('PJ'))						//Si ya une erreur
		{
			if($this->input->post('envoyer')=="Envoyer")
			{
				$error = array('error' => $this->upload->display_errors());
				
				if($error['error'] == '<p>You did not select a file to upload.</p>')
				{
					$error['error']='';
				}
			}
				$this->load->view('DivMainView');
				$this->load->view('OffreFormView',$error);
				$this->load->view('EndDivMainView');
		}
		else													//Si ya un fichier a envoyer
		{
			$uploadData = $this->upload->data();
			//$PJ = array('PJ' => $uploadData['file_name']);
			
			$data = array
			(
				'ID_ENTREPRISE' => $this->session->ID_USER,
				'titre' => $this->input->post('Titre'),
				'DATE_DEBUT' => $this->input->post('dateDebut'),
				'duree' => $this->input->post('duree'),
				'Mission' => $this->input->post('Mission'),
				'Contact' => $this->input->post('Contact'),
				//'PJ' => $this->input->post('PJ'),		//on récupere seulement le nom de la piece jointe
				'PJ' => $uploadData['file_name'],	//<------------------------a changer plus tard-------------
				'COMPLEMENT_INFO' => $this->input->post('complInfo')
			);
			$this->load->view('DivMainView');
			$this->load->view('upload_success');
			$this->load->view('EndDivMainView');
		}
		//FIN TRY
		
		if($this->input->post('envoyer')=="Envoyer")
		{
			$this->load->model('StageModel');
			$this->StageModel->insert_stage($data);
			
		}
		$this->load->view('StageFooterView');
	}
	}
	
	public function MesOffres()
	
	{
		if (!$this->session->USER_STATUT == 'ENTREPRISE')
		{
			redirect('Stage/');	
		}
		
		$this->load->model('StageModel');
		$where = array
		(
			'ID_ENTREPRISE' => $this->session->ID_USER
		);
		
		$data['offre'] = $this->StageModel->getOffresWhere($where);
		$data['MonOffre'] = $this->session->ID_USER;
		$this->load->view('StageOffreView',$data);
		$this->load->view('StageFooterView');
		
	}
	
	public function ModifierOffre($id_offre)
	{
		if ($this->session->IS_ACTIV == 0)
		{
			$this->load->view('entrepriseNO');
		}
		else{
		$config['upload_path']          = './PJ/';
		$config['allowed_types']        = '*';
		$config['max_size']             = 5000;
		$config['max_width']            = 0;
		$config['max_height']           = 0;

		$this->load->library('upload', $config);
		
		$this->upload->initialize($config);
		
		
		$where = array(
			'ID_OFFRE' => $id_offre
		);
		
		$this->load->model('StageModel');
		
		$data['offre'] = $this->StageModel->getOffresWhere($where);
		
		// $data = array(
			// 'TITRE' => $request->TITRE,
			// 'DATE_DEBUT' => $request->DATE_DEBUT,
			// 'DUREE' => $request->DUREE,
			// 'MISSION' => $request->MISSION,
			// 'CONTACT' => $request->CONTACT,
			// 'PJ' => $request->PJ,
			// 'COMPLEMENT_INFO' => $request->COMPLEMENT_INFO
		// );
		
		
		$PJrequest = $data['offre'];
		
		$oldPJ = NULL;
		foreach ($PJrequest as $PJtemp)
			$oldPJ = $PJtemp->PJ;
		
		$data['oldPJ'] = base_url().'PJ/'.$oldPJ;
		
		$this->load->view('DivMainView');
		$this->load->view('OffreModificationForm',$data);
		$this->load->view('EndDivMainView');
		
		$uploadData = NULL;
			
		if (!$this->upload->do_upload('PJ'))						//Si ya une erreur
		{

		}else
		{
			$uploadData = $this->upload->data();
		}
		
		
		if($this->input->post('modifier')=="Modifier")
		{			
			
			$PJ = NULL;
			if($oldPJ != NULL && $uploadData['file_name'] == NULL)		//Si il y avait une piece jointe precedemment et que l'utilisateur ne rentre rien
			{
				$PJ = $oldPJ;									//on change rien
			}else if ($uploadData['file_name'] != '' && $oldPJ != NULL)					//Sinon si l'utilisateur met une piece jointe et que il y en avait une avant.
			{
				$PJ = $uploadData['file_name'];
				
				unlink('./PJ/'.$oldPJ);
				
			}else if($oldPJ == NULL)									//SInon si il n'y avait pas de piece jointe
			{
				$PJ = $uploadData['file_name'];					//on met ce que l'utilisateur rentre
			}else if($oldPJ == $uploadData['file_name'])
			{
				$PJ = $uploadData['file_name'];
			}
			
			$data2 = array
			(
				'TITRE' => $this->input->post('Titre'),
				'DATE_DEBUT' => $this->input->post('dateDebut'),
				'DUREE' => $this->input->post('duree'),
				'MISSION' => $this->input->post('Mission'),
				'CONTACT' => $this->input->post('Contact'),
				'PJ' => $PJ,
				'COMPLEMENT_INFO' => $this->input->post('complInfo')
			);
			
			
			$this->StageModel->updateOffre($data2,$id_offre);
			redirect('Offres/MesOffres');
		}
		
		if($this->input->post('supprimer')=="Supprimer")
		{
			$this->StageModel->DeleteOffre($id_offre);
			redirect('Offres/MesOffres');
		}
		
		if($this->input->post('supprold')=="Supprimer la piece jointe")
		{
			if(!unlink('./PJ/'.$oldPJ))
			{
				echo "ERREUR : la piece jointe n'a pas pu être supprimer";
			}
			$data3 = array(
				'PJ' => NULL
			);
			$this->StageModel->updateOffre($data3,$id_offre);
			redirect('Offres/MesOffres');
		}
	}
	}
}
?>