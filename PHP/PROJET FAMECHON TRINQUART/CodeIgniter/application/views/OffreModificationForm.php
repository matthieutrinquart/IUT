			<!--titre, durée, date début, mission, contact -champ libre-, pièce jointe -complément d’informations, facultatif- )-->
			<?php foreach($offre as $o):?>
			<form name = "formulaire" action="" enctype="multipart/form-data" method="post">
				titre du stage : <input name="Titre" id="formulaire" type="text" value="<?=$o->TITRE?>" size="25" required /><br /><br />
				durée du stage (en semaines) : <input name="duree" id="formulaire" type="number" value="<?=$o->DUREE?>" size="25" min="1" max="24" required  /><br /><br />
				<?php if(isset($o->DATE_DEBUT)):?>
					date de début du stage : <input name="dateDebut" id="formulaire" type="date"  value="<?=$o->DATE_DEBUT?>" size="25" required /><br /><br />
				<?php else: ?>
					date de début du stage : <input name="dateDebut" id="formulaire" type="date"  value="" size="25" required /><br /><br />
				<?php endif; ?>
				Mission du stage: <input name="Mission" id="formulaire" type="text"  value="<?=$o->MISSION?>" size="25" required  /><br /><br />
				Contact : </br><input name="Contact" id="formulaire" type="text"  value="<?=$o->CONTACT?>" size="25" required /><br /><br />
				<?php if(isset($o->PJ)):?>
					Pièce jointe : (5 Mo max) <input name="PJ" id="formulaire" type="file" value="<?=$o->PJ?>" /><br />L'ancienne PJ est : <?=$oldPJ?><br /><br />
					
					Supprimer l'ancienne Piece jointe (irréversible) : <input type="submit" name="supprold" value="Supprimer la piece jointe" /><br /><br />
				<?php else: ?>
					Pièce jointe : (5 Mo max) <input name="PJ" id="formulaire" type="file" value="" /><br /><br />
				<?php endif; ?>
				<?php if(isset($o->COMPLEMENT_INFO)):?>
					complement d'informations : <input name="complInfo" id="formulaire" type="text"  value="<?=$o->TITRE?>" /><br /><br />
				<?php else: ?>
					complement d'informations : <input name="complInfo" id="formulaire" type="text"  value="" /><br /><br />
				<?php endif; ?>
				<input type="submit" name="modifier" value="Modifier" />
				<input type="submit" name="supprimer" value="Supprimer" />
			</form>
			<?php endforeach; ?>