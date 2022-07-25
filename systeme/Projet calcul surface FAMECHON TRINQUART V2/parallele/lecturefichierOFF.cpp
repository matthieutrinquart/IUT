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

	//------------Initialisation des variables utilisée pour avoir le temps de calcul de chaque pthread
	float temps;
    clock_t t1, t2;
    t1 = clock();
   	//------------------------------------------------------------------------------

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


	//-----------------------Calcul du temps d'execution ---------------------------
	t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);
	//------------------------------------------------------------------------------
	return NULL ;
}



int main(int argc,char* argv[])
{
	monObjet = new Objet();
	monObjet->charge_OFF("../data/bouddha10k.off");
	
	
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
	
	
	const unsigned int nbthread = atoi(argv[1]);



	pthread_t * tbthread = nullptr ;
	int reste=0;

	if( monObjet->nbfaces != 0)	//on cherche combien de threads on veut crée (dans ce cas la 1 thread fait 25 faces)
	{
		tbthread = new pthread_t[nbthread] ;
		reste = monObjet->nbfaces % nbthread ;

	}
	intervalAire ** tbstruct ;

	tbstruct = new intervalAire * [nbthread] ;
	for (unsigned int i=0; i< nbthread ; ++i )
	  tbstruct[i]= new intervalAire;


	for(unsigned int i = 0 ; i <nbthread ; ++i)
	{

			for(int o = 0 ; o <= reste ; ++o)
			{
			tbstruct[i]->debut = i *  (monObjet->nbfaces / nbthread) + o;
			tbstruct[i]->fin = i * (monObjet->nbfaces / nbthread) + (monObjet->nbfaces / nbthread) + o;
			tbstruct[i]->air = 0  ;
		//	tbstruct[i]->Obj = monObjet;
	}

		/*cout << "tbstruct[i]->debut = " << tbstruct[i]->debut << endl
		<< "tbstruct[i]->fin = " << tbstruct[i]->fin << endl
		<< "tbstruct[i]->air " << tbstruct[i]->air << endl
		<< "tbstruct[i]->Obj" << tbstruct[i]->Obj->nbsommets <<"    " << tbstruct[i]->Obj->nbfaces  << endl<<endl;
		*/

		pthread_create(&tbthread[i], NULL, calculAir, (void *)tbstruct[i]);
	}
	for(unsigned int i = 0 ; i <nbthread ; ++i)
	{
		pthread_join(tbthread[i], NULL);
	 // cerr << "fini : " << i << endl;
	}
	double air = 0 ;

	//std::cout << " nbthread = " << nbthread << endl;

	for(unsigned int i = 0; i<nbthread ; i++)
	{
	//	std::cout << tbstruct[i]->air << endl;
		air = air + tbstruct[i]->air ;
	}



	//	monObjet->calculAir();


	cout << "fini, l'air est egale a : "<< air << endl;

	//usleep(5000000);

	for (unsigned int i=0; i< nbthread ; ++i )
	  delete [] tbstruct[i];

	delete[] tbstruct;

	return(EXIT_SUCCESS);
}
