#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include "objetsOFF.h"

using namespace std;


int main()
{
	Objet monObjet;
	monObjet.charge_OFF("../data/bouddha10k.off");	//On charge notre Objet OFF dans la RAM

	//------------Initialisation des variables utilisée pour avoir le temps de calcul
	float temps;
	clock_t t1, t2;
	t1 = clock();
	//------------------------------------------------------------------------------


	monObjet.calculAir();		//Appelle de la fonction calculAir()


	//-----------------------Calcul du temps d'execution ---------------------------
	t2 = clock();
	temps = (float)(t2-t1)/CLOCKS_PER_SEC;
	printf("temps = %f\n", temps);
	//------------------------------------------------------------------------------

	cout << "fini, l'air est egale a : "<< monObjet.Air << endl;	//affichage de l'air
	return(EXIT_SUCCESS);
}
