#include <errno.h>
#include <unistd.h>

#include <cstring>
#include <cstdlib>
#include <cstdio>

#include <cmath>

#include <iostream>

#include "objetsOFF.h"


point3 VecteurFromPoints(const point3 * _p1, const point3 * _p2) {
point3 res;
	res.x = _p2->x - _p1->x;
	res.y = _p2->y - _p1->y;
	res.z = _p2->z - _p1->z;
return res;
}

Objet::Objet() {
	strcpy(nom, "nil");
	nbsommets=0;
	nbfaces=0;
	id=0;
}

Objet::~Objet() {
//nil
}

void Objet::charge_OFF(const char nom_fichier[40])
{
	unsigned int i;
	FILE * fichier;
	unsigned int n;

	char magic[10];

	if ((fichier=fopen(nom_fichier,"r"))==NULL)		//erreur
	{
			perror("Erreur a l'ouverture du fichier OFF");
	        	exit(1);
	}

	fscanf(fichier,"%s\n",magic);

	if (strcmp(magic, "OFF")!=0) //erreur
	{
		perror("Erreur dans l'en tête du fichier OFF");
	        exit(0);
	}

	fscanf(fichier,"%u %u %u\n",&nbsommets, &nbfaces, &i);

	//Remplissage de la liste de points
	point3 temp;

	for (i=0;i<nbsommets;i++)
	{
	    fscanf(fichier,"%lf %lf %lf\n",&temp.x,&temp.y,&temp.z);
		if (min.x>temp.x)
			min.x=temp.x;
		if (min.y>temp.y)
			min.y=temp.y;
		if (min.z>temp.z)
			min.z=temp.z;

		if (max.x<temp.x)
			max.x=temp.x;
		if (max.y<temp.y)
			max.y=temp.y;
		if (max.z<temp.z)
			max.z=temp.z;

		lpoints.push_back(temp);
	}

	//Remplissage de la liste de faces
	iFaceTri ftemp;

	for (i=0;i<nbfaces;i++)
	{
	   fscanf(fichier,"%u %u %u %u\n",&n, &ftemp.s0, &ftemp.s1,&ftemp.s2);
		if (n!=3) {
			perror("Erreur au chargement des faces, non triangulaires");
			exit(1);
			}
		lifaces.push_back(ftemp);
	}


	//calcul du centroid de l'objet à partir de la boîte min/max
	centroid.x = (max.x + min.x) / 2.0f;
	centroid.y = (max.y + min.y) / 2.0f;
	centroid.z = (max.z + min.z) / 2.0f;

	std::cerr << "Chargement du fichier " << nom_fichier << std::endl;
	std::cerr << "\t" << nom_fichier << " : " << nbsommets << " points - " << nbfaces << " faces" << std::endl;
	std::cerr << "\t" << nom_fichier << " MAX : " << max.x << " " << max.y << " " << max.z << std::endl;
	std::cerr << "\t" << nom_fichier << " MIN : " << min.x << " " << min.y << " " << min.z << std::endl;
	std::cerr << "\t" << nom_fichier << " CENTROID : " << centroid.x << " " << centroid.y << " " << centroid.z << std::endl;

	fclose(fichier);

}


void Objet::infos()
{
   std::cerr << "Objet " << nom << ", nbsommets " << nbsommets << " nbfaces " << nbfaces << "\n";

	std::cerr << "\n SOMMETS\n";
	std::deque<point3>::iterator pit, pitend = lpoints.end();

	for( pit = lpoints.begin(); pit != pitend; ++pit)
		std::cerr << "[" << (*pit).x << " " << (*pit).y << " " << (*pit).z << "]\n";

	std::cerr << "\n FACES\n";
	std::deque<iFaceTri>::iterator fit, fitend = lifaces.end();

	for(fit = lifaces.begin() ; fit != fitend ; ++fit)
		std::cerr << "{" << (*fit).s0 << " " << (*fit).s1 << " " << (*fit).s2 << "}\n";
}


void Objet::calculAir()
{
	double a,b,c,p;
	for(unsigned int i = 0 ; i <= nbfaces - 1 ; ++i)
	{
		a = calculDistance(lpoints[lifaces[i].s0],lpoints[lifaces[i].s1]);
		b = calculDistance(lpoints[lifaces[i].s0],lpoints[lifaces[i].s2]);
		c = calculDistance(lpoints[lifaces[i].s1],lpoints[lifaces[i].s2]);


		p = ( a + b + c ) / 2 ;
		Air += sqrt(p * (p - a) * (p - b) * (p - c)) ;


		//std::cout << Air << std::endl;
	}
}

double Objet::calculDistance(point3 A,point3 B)
{
	return (sqrt((B.x - A.x ) * (B.x - A.x ) + ( B.y - A.y ) * ( B.y - A.y ) + ( B.z - A.z ) * ( B.z - A.z )));
}
