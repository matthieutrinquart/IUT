#include "Cercle.hpp"

Cercle::Cercle(point _centre ,float _rayon):centre(_centre) ,Rayon(_rayon)//constructeur de cercle qui prend en parametre un point et un rayon
{
}

Cercle::~Cercle()//destructeur
{





}

point Cercle::Point(int i , int pas)// retourne un point du cercle par rapport a un pas
{
  point angle ; //le point que va prendre les coordonné

  angle.X = (Rayon * cos(i * (2 * M_PI)/pas)+ centre.X);//la coordonné X du point
  angle.Y = (Rayon * sin(i * (2 * M_PI)/pas)+ centre.Y);//la coordonné Y du point
  angle.Z = 0;//la coordonné Z du point qui vaut 0
return angle;//retourne le point
}
