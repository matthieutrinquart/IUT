			<?php foreach($offre as $o):?>
					<div class="offre">
						<h2> <?=$o->TITRE?></h2>
						<h4> <?=$o->DUREE?> 
						<?php if(isset($o->DATE_DEBUT)):?>
							<?=$o->DATE_DEBUT?></h4>
						<?php else:?>
							<I> Date de debut du stage variable </I></h4>
						<?php endif; ?>
						<p><?=$o->MISSION?></p>
						<label> <?=$o->CONTACT?> </label>
						
						<?php if(isset($o->PJ)):?>
							<a href="<?php echo base_url();?>PJ/<?=$o->PJ?>"><?=$o->PJ?></a>
						<?php else:?>
							<I> Pas de pieces jointe </I></h4>
						<?php endif; ?>
						
						<?php if(isset($o->COMPLEMENT_INFO)):?>
							<label><?=$o->COMPLEMENT_INFO?></label>
						<?php endif; ?>
						<span>
						<?php if (isset($voirOffre)):?>
							<?php if($voirOffre == 'Voir'):?>
								<?=anchor('Stage/voirOffre/'.$o->ID_OFFRE, 'Voir l\'offre'); ?>
							<?php elseif ($voirOffre == 'Retour'):?>
								<?=anchor('Stage/', 'Retour');?>
							<?php endif; ?>
						<?php endif; ?>
							<br/>
						<!-- DEBUT COMMENTAIRE --> 
							<?php if (isset($_SESSION['USER_STATUT'])):?>
								<?php if($_SESSION['USER_STATUT'] == 'ADMIN'):?>
									<form name = "formulaire" action="" method="post">
										<input type="hidden" id="ID_OFFRE" name="ID_OFFRE" value="<?=$o->ID_OFFRE?>">
										Commentaire : <input type="text" name="commentaire">
										<input type="submit" name="envoyer" Value="Envoyer">
									</form>
									<br/>
								<?php endif; ?>
							<?php endif; ?>
							<?php if(isset($MonOffre)):?>
								<div class="droite"><?php echo anchor("Offres/ModifierOffre/".$o->ID_OFFRE, "Modifier l'offre")?></div>
							<?php endif; ?>
						</span>
						<?php if(isset($commentaire)):?>
							<?php foreach($commentaire as $c):?>
								<?php if($c->ID_OFFRE == $o->ID_OFFRE):?>
									<div class="commentaire">
										<p><?=$c->TEXTE?></p>
									</div>
								<?php endif; ?>
							<?php endforeach; ?>
							<?php endif; ?>
							<!-- FIN COMMENTAIRE COMMENTAIRE --> 
							<form name = "formulaire" action="" method="post">
					<?php if(isset($_SESSION['ID_USER']) && $_SESSION['USER_STATUT'] != 'ENTREPRISE'):?>
							<?php if($this->StageModel->getlikeWhere_id_user($o->ID_OFFRE , $_SESSION['ID_USER'])):?>
											<input type="submit" name="Liker" value="liker" />
								<?php else:?>
										<input type="submit" name="Dislike" value="dislike" />
								<?php endif; ?>
											<input type="hidden" name="id_offre" value="<?=$o->ID_OFFRE?>"/>
						<?php endif; ?>
											<p>Nombre de like : <?=count($this->StageModel->getlikeWhere($o->ID_OFFRE))?></p>
								<?php if(isset($like) && !empty($like)):?>
									<?php foreach($like as $c):?>
											<div class="like">
											</div>
									<?php endforeach; ?>
								<?php endif; ?>
							</form>
					</div>
			<?php endforeach; ?>
