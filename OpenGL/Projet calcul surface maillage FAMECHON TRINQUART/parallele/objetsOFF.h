#ifndef _H_OBJETSOFF
#define _H_OBJETSOFF

#include <deque>
//~ #include "struct.hpp"
#include "point3.h"
#include "iFaceTri.h"

class Objet {

  public :
	char nom[40];

	unsigned int nbsommets;
	unsigned int nbfaces;

	unsigned int id;

	std::deque<point3> lpoints;
	std::deque<iFaceTri> lifaces;

	point3 min;
	point3 max;
	point3 centroid;

  double Air;

	Objet();
	Objet(const Objet&);
	~Objet();

	void charge_OFF(const char nom_fichier[40]);

	void infos();




};


struct intervalAire
{
	unsigned int debut,fin;
	double air;
	//Objet * Obj;
};

#endif
