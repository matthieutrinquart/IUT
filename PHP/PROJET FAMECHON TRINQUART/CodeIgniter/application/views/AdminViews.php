			<!--titre, durée, date début, mission, contact -champ libre-, pièce jointe -complément d’informations, facultatif- )-->

 <form name = "fd" action="" method="post">
 <table>			
<tr>
    <td>ID</td>
    <td>NOM</td>
    <td>PRENOM</td>
    <td>MAIL</td>
    <td>STATUT</td>
  </tr>
<?php foreach( $BDD as $row ) :?>
	<?php if($row->USER_STATUT != 'ADMIN'):?>
  <tr>
    <td><?=$row->ID_USER?></td>
    <td><?=$row->NOM?></td>
    <td><?=$row->PRENOM?></td>
    <td><?=$row->MAIL?></td>
    <td><?=$row->USER_STATUT?></td>
    <td><input type="submit" name= <?=$row->ID_USER?> value="Modifier" />  </td>
    <td><input type="submit" name= <?=$row->ID_USER?> value="supprimer" />  </td>
   
  </tr>
  <?php endif; ?>

			<?php endforeach; ?>
            </table>	
            </form> 