#include "Color.hpp"

Color operator*(double alpha , const Color& color)
{
	Color couleur(alpha * color.r , alpha * color.g , alpha * color.b);
	
	
	return couleur ;
 }
 
 Color operator+(double alpha , const Color& color)
{
	Color couleur(alpha + color.r , alpha + color.g , alpha + color.b);
	
	
	return couleur ;
 }
