			<!--titre, durée, date début, mission, contact -champ libre-, pièce jointe -complément d’informations, facultatif- )-->
			<p><?=$error?></p>
			<form name = "formulaire" action="" enctype="multipart/form-data" method="post">
				titre du stage : <input name="Titre" id="formulaire" type="text" value="" size="25" required /><br /><br />
				durée du stage (en semaines) : <input name="duree" id="formulaire" type="number" value="" size="25" min="1" max="24" required  /><br /><br />
				date de début du stage : <input name="dateDebut" id="formulaire" type="date"  value="" size="25" required /><br /><br />
				Mission du stage: <input name="Mission" id="formulaire" type="text"  value="" size="25" required  /><br /><br />
				Contact : </br><input name="Contact" id="formulaire" type="text"  value="" size="25" required /><br /><br />
				Pièce jointe : <input name="PJ" id="formulaire" type="file" value="" /><br /><br />
				complement d'informations : <input name="complInfo" id="formulaire" type="text"  value="" /><br /><br />
				<input type="submit" name="envoyer" value="Envoyer" /> 
				<input type="reset" value="Effacer" />
			</form>