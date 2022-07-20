<?php
	Class Profile extends CI_Controller
	{	
	
		public function __construct()
		{
			parent::__construct();
			$this->load->library('session');
			$this->load->helper('url');
			$Titre['titre'] = 'Modifications du profil';
			$this->load->view('StageHeaderView',$Titre);
			//session_start();
		}
		public function affichage_Entreprise()	//fonction appellé par défaut
		{
            //session_start();
            $h = true ;
            $this->load->model('StageModel');
           $p =  $this->StageModel->getUsers();
            $id = $this->session->ID_USER ;
            $data = array
            (
                'NOM' => $this->session->NOM ,
                'PRENOM' => $this->session->PRENOM,
                'MAIL' => $this->session->MAIL,
                'TELEPHONE' => $this->session->TELEPHONE,
                'RAISON_SOCIALE' =>$this->session->RAISON_SOCIALE 
            );
            // session_start();
            // $this->load->view('modifierViews',$data);
            
			if ($this->input->post('modifier')=="Modifier")
			{
				$data = array
				(
					'NOM' => $this->input->post('Nom'),
					'PRENOM' => $this->input->post('PRENOM'),
					'MAIL' => $this->input->post('mail'),
					'MDP' => $this->input->post('mdp_') != ''?sha1($this->input->post('mdp_')):$this->session->MDP,
					'TELEPHONE' => $this->input->post('tel'),
					'RAISON_SOCIALE'=> $this->input->post('raison')
                );
                foreach  ( $p as $row ) 
		{ 
                if(($data['MAIL'] == $row->MAIL) && ($id != $row->ID_USER))
			{
				$this->load->view('vue_erreur');
				$h = false ;
            }
        }
            if($h)
            {
               $this->StageModel->UpdateUser($data,$id);
               
               $this->session->NOM =$data["NOM"];
               $this->session->PRENOM = $data["PRENOM"];
               $this->session->MAIL = $data["MAIL"];
               $this->session->MDP = $data["MDP"];
               $this->session->TELEPHONE = $data["TELEPHONE"];
               $this->session->RAISON_SOCIALE = $data["RAISON_SOCIALE"];
               redirect('Stage/');
            }
			}
            $this->load->view('DivMainView');
            $this->load->view('ModifierViews_Entreprise',$data);
            $this->load->view('EndDivMainView');
			$this->load->view('StageFooterView');
			
        }
		
		
        public function affichage_Membre()	//fonction appellé par défaut
		{
          //  session_start();
          $h = true ;
            $this->load->model('StageModel');
            $id = $this->session->ID_USER ;
            $data = array
            (
                'NOM' => $this->session->NOM ,
                'PRENOM' => $this->session->PRENOM,
                'MAIL' => $this->session->MAIL,
                'TELEPHONE' => $this->session->TELEPHONE,
                'DATE_NAISS' =>$this->session->DATE_NAISS ,
                'DIPLOME' =>$this->session->DIPLOME 
            );
           // session_start();
           // $this->load->view('modifierViews',$data);
            
            if ($this->input->post('modifier')=="Modifier")
            {
				$data = array
				(
					'NOM' => $this->input->post('Nom'),
					'PRENOM' => $this->input->post('PRENOM'),
					'MAIL' => $this->input->post('mail'),
					'MDP' => $this->input->post('mdp_') != ''?sha1($this->input->post('mdp_')):$this->session->MDP,
					'TELEPHONE' => $this->input->post('tel'),
					'DATE_NAISS'=> $this->input->post('date'),
					'DIPLOME'=> $this->input->post('diplome')
                );
                foreach  ( $p as $row ) 
                { 
                        if(($data['MAIL'] == $row->MAIL) && ($id != $row->ID_USER))
                    {
                        $this->load->view('vue_erreur');
                        $h = false ;
                    }
                }
                if($h)
                {
                $this->StageModel->UpdateUser($data,$id);
               
                $this->session->NOM =$data["NOM"];
                $this->session->PRENOM = $data["PRENOM"];
                $this->session->MAIL = $data["MAIL"];
                $this->session->MDP = $data["MDP"];
                $this->session->TELEPHONE = $data["TELEPHONE"];
                $this->session->DATE_NAISS = $data["DATE_NAISS"];
                $this->session->DIPLOME = $data["DIPLOME"];
               
               redirect('Stage/');
                }
            }
            $this->load->view('DivMainView');
            $this->load->view('ModifierViews_membre',$data);
            $this->load->view('EndDivMainView');
			$this->load->view('StageFooterView');
			
        }
        public function affichage_Admin()	//fonction appellé par défaut
		{
          //  session_start();
          $bool = true ;
            $this->load->model('StageModel');
            $p =  $this->StageModel->getUsers();
            $id = $this->session->ID_USER ;
            $data = array
            (
                'NOM' => $this->session->NOM ,
                'PRENOM' => $this->session->PRENOM,
                'MAIL' => $this->session->MAIL,
                'TELEPHONE' => $this->session->TELEPHONE,
            );
           // session_start();
           // $this->load->view('modifierViews',$data);
            
            if ($this->input->post('modifier')=="Modifier")
            {
				$data = array
				(
					'NOM' => $this->input->post('Nom'),
					'PRENOM' => $this->input->post('PRENOM'),
					'MAIL' => $this->input->post('mail'),
					'MDP' => $this->input->post('mdp_') != ''?sha1($this->input->post('mdp_')):$this->session->MDP,
                );
                
                foreach  ( $p as $row ) 
                { 
                        if(($data['MAIL'] == $row->MAIL) && ($id != $row->ID_USER))
                    {
                        $this->load->view('vue_erreur');
                        $bool = false ;
                    }
                }
                if( $bool)
                {
                    $this->StageModel->UpdateUser($data,$id);
               
                    $this->session->NOM =$data["NOM"];
                    $this->session->PRENOM = $data["PRENOM"];
                    $this->session->MAIL = $data["MAIL"];
                    $this->session->MDP = $data["MDP"];
                    redirect('Stage/');
                }
            }
            $this->load->view('DivMainView');
            $this->load->view('ModifierViews_Admin',$data);
            $this->load->view('EndDivMainView');
			$this->load->view('StageFooterView');
			
        }
}


?>