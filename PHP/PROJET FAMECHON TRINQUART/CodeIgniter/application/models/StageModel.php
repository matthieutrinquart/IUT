<?php
	class StageModel extends CI_Model
	{
		public function getOffres()
		{
			$offre = $this->db->get('T_OFFRE');
			return $offre->result();
		}
		
		public function getUsers()
		{
			$users = $this->db->get('T_USER');
			return $users->result();
		}
		
		public function insert_entreprise($data)
		{
			$this->db->insert('T_USER', $data);
		}
		
		public function insert_stage($data)
		{
			$this->db->insert('T_OFFRE', $data);
		}
		
		public function getOffresWhere($where)
		{
			$offre = $this->db->get_where('T_OFFRE',$where);
			return $offre->result();
		}
		
		public function updateOffre($data,$id)
		{
			$this->db->where('ID_OFFRE', $id);
			$this->db->update('T_OFFRE', $data);
		}
		
		public function UpdateUser($data,$id)
		{
			$this->db->update('T_USER', $data, "ID_USER = $id");
		}
		
		public function DeleteOffre($id)
		{
			$this->db->delete('T_LIKES', array('ID_OFFRE' => $id));
			$this->db->delete('T_COMMENTAIRE', array('ID_OFFRE' => $id));
			$this->db->delete('T_OFFRE', array('ID_OFFRE' => $id));
		}
		
		public function DeleteUser($id)
		{
			$this->db->delete('T_USER', array('ID_USER' => $id));
		}
		
		public function getCommentairesWhere($id)
		{
			$offre = $this->db->get_where('T_COMMENTAIRE',$id);
			return $offre->result();
		}
		
		public function getCommentaires()
		{
			$offre = $this->db->get('T_COMMENTAIRE');
			return $offre->result();
		}
		
		public function insert_commentaire($data)
		{
			$this->db->insert('T_COMMENTAIRE', $data);
		}		
		
		public function getIdAdmin()
		{
			$UserStatut = array
			(
				'USER_STATUT' => 'ADMIN'
			);
			
			$query = $this->db->get_where('T_USER', $UserStatut);
			$row = $query->row();
			if(isset($row))
			{
				return $row->ID_USER;
			}
			

			
		}
		public function insertlike($data)
		{
			$this->db->insert('T_LIKES', $data);
		}
		public function getlikeWhere($id)
		{
			$where = array(	
				'ID_OFFRE' => $id
			);
			$like = $this->db->get_where('T_LIKES',$where);
			return $like->result();
		}
		public function getlikeWhere_id_user($id_offre , $id_user)
		{
			$where = array(	
				'ID_OFFRE' => $id_offre,
				'ID_USER' => $id_user
			);
			$like = $this->db->get_where('T_LIKES',$where);
			$row = $like->row() ;
			if(isset($row))
			return false ;
			else 
			return true ;
		}
		public function getlike()
		{
			$like = $this->db->get('T_LIKES');
			return $like->result();
		}
		public function deletelike($where)
		{
			$this->db->delete('T_LIKES', $where );

		}
	}
?>