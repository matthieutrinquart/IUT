    <H1>Inscription Entreprise</H1>
    <form name = "formulaire" action="" method="post">
		Nom Dépositaire : <input name="Nom" id="formulaire" type="text" value=""  size="25" required /><br />
		Prènom Dépositaire : <input name="PRENOM" id="formulaire" type="text" value="" size="25"required  /><br />
		mail : <input name="mail" id="formulaire" type="text"  value="" size="25" required required pattern="[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+.[a-zA-Z]{2,}$" /><br />
		Mots de passe: <input name="mdp" id="formulaire" type="password"  value="" size="25"required  /><br />
		Confirmation de Mots de passe : <input name="mdp_conf" id="formulaire" type="password"  value="" size="25" required  oninput="check(this)"/><br />
		raison sociale : <input name="raison" id="formulaire"  value="" size="25" required /><br />
		téléphone : <input name="tel" id="formulaire" type="text"  value=""  size="25" required /><br />
		<input type="submit" name="envoyer" value="Envoyer" /> 
		<input type="reset" value="Effacer" />
		
		<script>
			function check(input) 
			{
				if (input.value != document.getElementById('mdp_').value) {
					input.setCustomValidity('LES MDP SONT PAS LES MEME');
				} else 
				{
					input.setCustomValidity('');
				}
			}
		</script>
	</form>
