#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "objetsOFF.h"

using namespace std;


int main()
{
	Objet monObjet;
		//monObjet.charge_OFF("data/sphere.off");
		monObjet.charge_OFF("lucy.off");
		//monObjet.infos();

		monObjet.calculAir();
		cout << "fini, l'air est egale a : "<< monObjet.Air << endl;

		cout << "je sleep" << endl;
		Sleep(5000000);

	return(EXIT_SUCCESS);
}
