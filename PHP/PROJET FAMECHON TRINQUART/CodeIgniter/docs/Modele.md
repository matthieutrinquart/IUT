#Le modele

Notre modele "models/StageModel.php" permet d'executer les differentes requetes vers la base de données nécessaires au bon fontctionnement du site et de les communiquer au controlleurs.

###getOffres
	public function getOffres() : Array 
Renvoie toute les offres de la base de donnée au controlleurs

###getUsers
	public function getUsers() : Array 
Renvoie tout les utilisateurs de la base de donnée au controlleurs

###insert_entreprise
	public function insert_entreprise($data)
Rajoute une entreprise dans la BDD avec en paramètre un tableau associatif contenant les données.

###insert_stage
	public function insert_stage($data)
Rajoute une offre dans la base de données avec les données en paramètre

###getOffresWhere
	public function getOffresWhere($where) : Array 
Retourne les Offres avec un tableau associatif passé en paramètre pour le where

###updateOffre
	public function updateOffre($data,$id)
Met a jour l'offre $id avec les données passé en paramètre

###UpdateUser
	public function UpdateUser($data,$id)
Modifie un utilisateur.

###DeleteOffre
	public function DeleteOffre($id)
Supprime une offre avec l'id passé en paramètre

###DeleteUser
	public function DeleteUser($id)
Supprime un utilisateur avec l'id passé en paramètre

###getCommentairesWhere
	public function getCommentairesWhere($id) : Array 
Renvoie les commentaires de la base de données avec l'id de l'offre en paramètre

###getCommentaires
	public function getCommentaires() : Array 
Renvoie tout les commentaires.

###insert_commentaire
	public function insert_commentaire($data)
Ajoute un commentaire dans la BDD. $Data doit être un tableau associatif avec l'id de l'offre et de l'utilisateur.

###getIdAdmin
	public function getIdAdmin() : Array or Nothing
Renvoie un tableau associatif contenant les données de l'administrateur s'il existe.

###insertlike
	public function insertlike($data)
Rajoute un like dans la base de donné avec l'id de l'utilisateur et l'id de l'offre passé dans un tableau associatif.


###getlikeWhere
	public function getlikeWhere($id) : Array 
Retourne les Likes ou l'id de l'offre est égale a l'id passé en parametre.

###getlikeWhere_id_user
	public function getlikeWhere_id_user($id_offre , $id_user) : Boolean 
Retourne TRUE si l'utilisateur n'apparait pas dans la liste des likes de cette offre 

###getlike
	public function getlike() : Array 
Renvoie tout les likes de la BDD

###deletelike
	public function deletelike($where)
Supprime un like avec le tableau associatif passé en parametre

