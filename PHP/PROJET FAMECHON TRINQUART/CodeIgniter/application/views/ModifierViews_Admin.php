    <H1>Modifier</H1>
    <form name = "formulaire" action="" method="post">
		Nom  : <input name="Nom" id="Login" type="text" value=<?=$NOM?>  size="25" required /><br />
		Prènom  : <input name="PRENOM" id="nom" type="text" value=<?=$PRENOM?> size="25"required  /><br />
		mail : <input name="mail" id="mail" type="text"  value=<?=$MAIL?> size="25" required required pattern="[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+.[a-zA-Z]{2,}$" /><br />
		Changer mots de passe <input name="mdp" id="mdp_" type="password"  value="" size="25"  /><br />
		Confirmation de Mots de passe : <input name="mdp_conf" id="mdp_conf" type="password"  value="" size="25"  oninput="check(this)"/><br />
		<input type="submit" name="modifier" value="Modifier" /> 
		
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
