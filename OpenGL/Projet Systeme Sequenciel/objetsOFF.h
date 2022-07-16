#ifndef _H_OBJETSOFF
#define _H_OBJETSOFF

#include <deque>

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

  void calculAir();
  double calculDistance(point3 A, point3 B);



};

#endif
