#include "CourbeBezier.hpp"


CourbeBezier::CourbeBezier()//constructeur
{



}

CourbeBezier::~CourbeBezier()//destructeur
{

}

int CourbeBezier::factorial(const int n)//fonction qui fait le factorielle
{
    int res = 1;//par defaut la valeur du factorielle est a 1

    /* boucle for qui fait le factorielle*/
    for(int i = 2; i <= n; i++)
        res*=i;
    return res;
}




vector<point3> CourbeBezier::Bernstein(int pas , std::deque<point3> * controlPointList)
{

  vector<point3> tableau;//vecteur qui va avoir tout les points de bezier
              /*boucle qui parcours tout les t */
	 for(double  t = 0 ; t <=1 + (1/(double)pas) ; t = t + (1/(double)pas))
   {
      point3 Point ;//point qui va garder la valeur du point a un instant t
      unsigned int i = 0;//valeur qui va etre incrementer pour voir a quelle points on est
        /*boucle qui parcours les points P0 P1 P2 ....Pn etc...*/
	       for (std::deque<point3>::iterator it = controlPointList -> begin(); it != controlPointList-> end(); ++it)
	         {
             /*on applique la formule de Bernstein pour x et Pn */
              float	xpos1 = (factorial((controlPointList->size()-1))/(factorial(i)*factorial((controlPointList->size()-1 - i))) )
              * pow (t,i) * pow((1-t),(controlPointList->size()-1-i)) * (*it).x;


              /*on applique la formule de Bernstein pour y et Pn */
		          float	ypos1 = (factorial(controlPointList->size()-1)/(factorial(i)*factorial( controlPointList->size()-1 - i)) ) * pow (t,i) * pow((1-t),(controlPointList->size()-i-1)) * (*it).y;

              /*on applique la formule de Bernstein pour z et Pn */
				      float	zpos1 = (factorial(controlPointList->size()-1)/(factorial(i)*factorial( controlPointList->size()-1 - i)) ) * pow (t,i) * pow((1-t),(controlPointList->size()-i-1)) * (*it).z;

              /*on addition les valeur pour tout les Pn*/
				      Point.x = Point.x + xpos1 ;
				      Point.y = Point.y + ypos1 ;
				      Point.z = Point.z + zpos1 ;
				      ++i;//on passe au point suivant

            }

      tableau.push_back(Point);//on met le point dans le vector

    }
return tableau ;//on retourne le vector

}
