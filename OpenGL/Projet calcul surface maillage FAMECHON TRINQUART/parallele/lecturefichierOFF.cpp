#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include "objetsOFF.h"
#include "point3.h"
#include <stdlib.h>

using namespace std;


Objet * monObjet ;		//declaration de monObjet en global pour pouvoir s'en servir dans calcuAir dans avoir a le faire passer dans une structure


double calculDistance(point3 A,point3 B)		//la methode utilisé pour calculer la distance entre 2 points
{
	return (sqrt((B.x - A.x ) * (B.x - A.x ) + ( B.y - A.y ) * ( B.y - A.y ) + ( B.z - A.z ) * ( B.z - A.z )));
}

void * calculAir(void * _arg)
{


	intervalAire * ptr = (struct intervalAire *)  _arg ;
	double a=0, b=0, c=0, p=0;	//  p est le perimetre du triangle
								//  a est la distance entre A et B
								//  b est la distance entre A et C
								//  c est la distance entre B et C

	for(unsigned int i = ptr->debut ; i< ptr->fin ; ++i)
	{
		a = calculDistance(monObjet->lpoints[monObjet->lifaces[i].s0],monObjet->lpoints[monObjet->lifaces[i].s1]);		//  calcule de la distance entre A et B
		b = calculDistance(monObjet->lpoints[monObjet->lifaces[i].s0],monObjet->lpoints[monObjet->lifaces[i].s2]);		//  calcule de la distance entre A et C
		c = calculDistance(monObjet->lpoints[monObjet->lifaces[i].s1],monObjet->lpoints[monObjet->lifaces[i].s2]);		//  calcule de la distance entre B et C

		p = ( a + b + c ) / 2 ;									//calcul du permietre du triangle
		ptr->air += sqrt(p * (p - a) * (p - b) * (p - c)) ;		//utilisation de la Formule de Héron
	}



	return NULL ;
}



int main(int argc,char* argv[])
{

	monObjet = new Objet();
	monObjet->charge_OFF("../data/bouddha10k.off");		//le nom du ficher qu'on veut lire 

	//debut du compteur pour avoir le temps d'execution
	float temps;
    clock_t t1, t2;
    t1 = clock();

	//exceptions si la valeure entrée en parametre est problématique
	if(argc == 1)
		throw std::runtime_error("Veuillez preciser le nombre de thread que vous voulez en parametre");

	if(atoi(argv[1]) < 0)
	{
		throw std::runtime_error("Le nombre de thread est negatif !!!");
	}
	if((unsigned int)atoi(argv[1]) > monObjet->nbfaces)	
	{
		throw std::runtime_error("Le nombre de thread voulu est supérieur au nombre de faces !!!");
	}

	const unsigned int nbthread = atoi(argv[1]);	//on fait passer le nombre de thread en parametre.

	pthread_t * tbthread = nullptr ;	//déclaration du tableau de pthread_t
	int reste=0;						//déclaration du reste qui nous servira pour mieux repartir le nombre de face que chaque thread va traiter

	if( monObjet->nbfaces != 0)
	{
		tbthread = new pthread_t[nbthread] ;		//allocation dynamique du nombre de thread
		reste = monObjet->nbfaces % nbthread ;		//initialisation du reste de faces pas découpable
	}
	else							//exception
	{
		throw std::runtime_error("l'objet n'a pas de faces ?!");
	}

	intervalAire ** tbstruct ;		//Déclaration du tableau de pointeur sur la structure intervalAire
									//elle va stocker Debut, Fin et aire
									//de cette maniere chaque thread seras quelles faces il doit traiter
									//La structure est déclarer dans objetsOFF.h

	tbstruct = new intervalAire * [nbthread] ;		//alocation
	for (unsigned int i=0; i< nbthread ; ++i )
	  tbstruct[i]= new intervalAire;		//alocation de chaque pointeurs du tableau

	int o =  1;		//création du compteur pour savoir de combien on dois décaler le tableau
	for(unsigned int i = 0 ; i <nbthread ; ++i)	//pour chaque thread on remplis la structure et on crée le thread en faisant passer l'addresse de la structure en parametre 
	{
		if(reste > 0 )	//si il y a un reste alors on repartis les faces restantes dans les derniers thread crée
	    {
			if((int)i < (int)nbthread - reste)	//si on est au debut on coupe normalement
	        {
				tbstruct[i]->debut = i *  (monObjet->nbfaces / nbthread);
				tbstruct[i]->fin = i * (monObjet->nbfaces / nbthread) + (monObjet->nbfaces / nbthread);
				tbstruct[i]->air = 0  ;
			}else if((int)i == (int)nbthread - reste)	//si il nous reste plus que 'reste' thread a crée
			{
				tbstruct[i]->debut = i * (monObjet->nbfaces / nbthread);
				tbstruct[i]->fin = i * (monObjet->nbfaces / nbthread) + (monObjet->nbfaces / nbthread) + 1;	//on decale de 1 a la fin
				tbstruct[i]->air = 0  ;
			}
			else if((int)i > (int)nbthread - reste)		//et quand on arrive vers la fin
			{
				tbstruct[i]->debut = i *  (monObjet->nbfaces / nbthread) + o  ;//on décale le début
				tbstruct[i]->fin = i * (monObjet->nbfaces / nbthread) + (monObjet->nbfaces / nbthread) +  o +1 ;	//et la fin
				tbstruct[i]->air = 0  ;
				++o ;	//on incrémente le compteur de décalage
			}
		}else if(reste == 0)	//si il n'y a pas de reste alors on decoupe juste le tableau
		{
			tbstruct[i]->debut = i *  (monObjet->nbfaces / nbthread);
			tbstruct[i]->fin = i * (monObjet->nbfaces / nbthread)  + (monObjet->nbfaces / nbthread);
			tbstruct[i]->air = 0  ;
		}
		pthread_create(&tbthread[i], NULL, calculAir, (void *)tbstruct[i]);	//création des threads 
	}


	for(unsigned int i = 0 ; i <nbthread ; ++i)
	{
		pthread_join(tbthread[i], NULL);		//on attend la fin d'execution des pthreads
	}
	double air = 0 ;

	for(unsigned int i = 0; i<nbthread ; i++)
	{
		air = air + tbstruct[i]->air ;		//on additionne les aires
	}


	//fin de la mesure du temps
	t2 = clock();
	temps = (float)(t2-t1)/CLOCKS_PER_SEC;
	printf("temps = %f\n", temps);

	//affichage de l'aire
	cout << "fini, l'air est egale a : "<< air << endl;

	//Destruction des pointeurs
	for (unsigned int i=0; i< nbthread ; ++i )
	  delete [] tbstruct[i];

	delete[] tbstruct;

	return(EXIT_SUCCESS);
}
