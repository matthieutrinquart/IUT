
#include <fstream>
#include <iostream>

#include "ColorImage.hpp"
#include "GrayImage.hpp"
using namespace std;
int main()
{
	std::ifstream monFlux("jpg.ppm",std::ios::binary );
	ColorImage * pi = ColorImage::readPPM(monFlux);
	ColorImage * teste ;
	monFlux.close() ;

teste = pi->simpleScale(500 ,700 ) ;
//cout << teste->width << endl ;
//Color jaune( 255 ,255,0);
  //pi->clear(jaune);
	//pi->clear(255);SS
	//Color jaune( 255 ,255,0);
	//pi->rectangle( (uint16_t) (uint16_t)200, (uint16_t)100, (uint16_t)200, (uint16_t)100, jaune);

//pi->setpx(300 ,301 , 255) ;

/*
for(int i = 0 ; i< 320 ; ++i)
{

pi->setpx( i ,i , 0) ;S
S
}
*/
	std::filebuf fb ;
	fb.open("test.ppm" , std::ios::out);
	std::ostream os(&fb) ;
teste->writePPM(os) ;
fb.close() ;

	return(0);
}
