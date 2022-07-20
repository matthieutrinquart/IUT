<?php
	Class Voir_user_Admin extends CI_Controller
	{	
	
		public function __construct()
		{
			parent::__construct();
			$this->load->library('session');
            $this->load->helper('url');
    
		}
		
		public function index()	
		{
			$this->affichage();
        }
		
		public function affichage()	
		{
            $this->load->model('StageModel');
            $data['BDD'] = $this->StageModel->getUsers();

            $titre['titre'] = 'Voir utilisateur';
            $this->load->view('StageHeaderView', $titre);
            $this->load->view('DivMainView');
            $this->load->view('AdminViews',$data);
            $this->load->view('EndDivMainView');

               
            foreach( $data['BDD'] as $o)
        {
		if($this->input->post($o->ID_USER)=="Modifier")
		{
            
           $h = $o->ID_USER ;
        
                 redirect("Voir_user_Admin/modifier/$h");
        }
        if($this->input->post($o->ID_USER)=="supprimer")
		{
            
           $h = $o->ID_USER ;
        
                 redirect("Voir_user_Admin/supprimer/$h");
        }
    }

			//	redirect('Voir_user_Admin/modifier');
        
        }
    
    

        public function modifier($h)	
		{
            $data2;
            $bool = true ;
            $this->load->model('StageModel');
            $data['BDD'] = $this->StageModel->getUsers();
            foreach( $data['BDD'] as $o)
            {
                if($o->ID_USER == $h)
                {
            $data2 = array
		(
            'NOM' => $o->NOM,
            'PRENOM' => $o->PRENOM,
            'MAIL' => $o->MAIL,
            'TELEPHONE' => $o->TELEPHONE,
            'MDP'=> $o->MDP,
            'USER_STATUT' => $o->USER_STATUT,
            'RAISON_SOCIALE' => $o->RAISON_SOCIALE,
            'IS_ACTIV' => $o->IS_ACTIV == 1?'checked':'',
            'DATE_NAISS' => $o->DATE_NAISS,
            'DIPLOME' => $o->DIPLOME
        );
    }
}
    



            $this->load->view('StageHeaderView');

            $this->load->view('DivMainView');
            if($data2['USER_STATUT'] == 'ENTREPRISE')
            {
                $this->load->view('ModifierViews_Entreprise_Admin',$data2);
                if ($this->input->post('modifier')=="Modifier")
			{
				$data3 = array
				(
					'NOM' => $this->input->post('Nom'),
					'PRENOM' => $this->input->post('PRENOM'),
					'MAIL' => $this->input->post('mail'),
					'MDP' => $this->input->post('mdp_') != ''?sha1($this->input->post('mdp_')):$data2['MDP'],
					'TELEPHONE' => $this->input->post('tel'),
                    'RAISON_SOCIALE'=> $this->input->post('raison'),
                    'IS_ACTIV'=> $this->input->post("valider")=="cocher"?1:0,
                );
                foreach  ( $data['BDD'] as $row ) 
                { 
                        if(($data3['MAIL'] == $row->MAIL) && ($h != $row->ID_USER))
                    {
                        $this->load->view('vue_erreur');
                        $bool = false ;
                    }
                }
                if( $bool)
                {
                $this->StageModel->UpdateUser($data3 ,$h);
                redirect("Voir_user_Admin/");
                }
            }

            $this->load->view('EndDivMainView');
        }
        else
            {
                $this->load->view('ModifierViews_membre',$data2);
                if ($this->input->post('modifier')=="Modifier")
                {
                $data3 = array
				(
					'NOM' => $this->input->post('Nom'),
					'PRENOM' => $this->input->post('PRENOM'),
					'MAIL' => $this->input->post('mail'),
					'MDP' => $this->input->post('mdp_') != ''?sha1($this->input->post('mdp_')):$data2['MDP'],
					'TELEPHONE' => $this->input->post('tel'),
                    'DATE_NAISS'=> $this->input->post('date'),
                    'DIPLOME'=> $this->input->post("diplome")
                );

               foreach  ( $data['BDD'] as $row ) 
                { 
                        if(($data3['MAIL'] == $row->MAIL) && ($h != $row->ID_USER))
                    {
                        $this->load->view('vue_erreur');
                        $bool = false ;
                    }
                }
                if( $bool)
                {
                $this->StageModel->UpdateUser($data3 ,$h);
                redirect("Voir_user_Admin/");
                }
            }

            }
    }
    public function supprimer($h)	
    {
    
        $this->load->model('StageModel');
        $this->StageModel->DeleteOffre($h);
        $this->StageModel->DeleteUser($h);
        redirect("Voir_user_Admin/");

    }
}
?>