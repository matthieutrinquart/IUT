#include "ColorImage.hpp"
#include <stdint.h>
#include <iostream>
#include <stdexcept>

ColorImage::ColorImage(uint16_t w,uint16_t h)
	: width(w), height(h), array(nullptr)
{
	array = new uint8_t [width * height * 3];
}


ColorImage::ColorImage(const ColorImage & o)
	:	width(o.width) , height(o.height), array(nullptr)
{
	array = new uint8_t[o.width * o.height];
	for(size_t t=0 ; t < size_t(o.width * o.height) ; t++)
		array[t]=o.array[t];
}

ColorImage::~ColorImage()
{
	delete [] array ;
}

void ColorImage::writePPM(std::ostream & f) const
{
	f << "P6 \n" <<"#flousht je suis un commentaire wsoaw incroyable \n" << width << ' ' << height << "\n";

	f << "255\n";

	f.write((const char *) array , size_t (width * height * 3)) ;
}

void ColorImage::skip_line(std::istream & f)
{
	char c;
	f.get(c);
	while(c!= '\n')
		f.get(c);
}

void ColorImage::skip_comments(std::istream & f)
{
	char c;
	f.get(c);
	while(c == '#')
	{
		skip_line(f);
		f.get(c);
	}
	f.putback(c);
}

ColorImage * ColorImage::readPPM(std::istream & is)
{
	char c[3];
	is.get(c[0]);
	is.get(c[1]);
	is.get(c[2]);

	if(!(c[0] == 'P' && c[1] == '6' && c[2]=='\n'))
	{
		throw std::runtime_error("This is not a PGM file");
	}
	skip_comments(is);
	uint16_t w,h;
	is >> w >> h ;
	skip_comments(is);void  setpixelxy(uint8_t x ,uint8_t y , Color color);
	uint16_t max_c;
	is>> max_c;
	if(max_c > 255) throw std::runtime_error(">255");

	is.get();

	ColorImage * gi = new ColorImage(w,h);
	is.read((char * )gi->array,w*h * 3);
	return gi;

}

void  ColorImage::setpixelxy(uint16_t x ,uint16_t y , Color color)
{
  array[(y*width + x)*3] = color.r ;
  array[(y*width + x)*3 + 1] = color.g ;
  array[(y*width + x)*3 + 2] = color.b ;


}
Color ColorImage::getpixelxy(uint16_t x ,uint16_t y )
{
	Color couleur ;
  couleur.r = array[(y*width + x)*3] ;
  couleur.g =array[(y*width + x)*3 + 1]  ;
  couleur.b =array[(y*width + x)*3 + 2]  ;
	return couleur ;


}


void ColorImage::clear(Color color)
{
	for(uint16_t i = 0; i<  height ; ++i)
  {
	for(uint16_t o = 0; o< width  ; ++o)
  {
			setpixelxy(o , i, color) ;
	}
}
}

void ColorImage::rectangle(uint16_t x,uint16_t y,uint16_t w,uint16_t h, Color color)
{


  for(uint16_t i = x; i< x+w ; ++i)
  {


    setpixelxy(i , y, color) ;
    setpixelxy(i , y + h, color) ;

    }
    for(uint16_t o = y ; o<h+y ;++o)
    {
      setpixelxy(x , o, color) ;
      setpixelxy(x + w , o, color) ;

    }

  }
	void ColorImage::fillRectangle(uint16_t x,uint16_t y,uint16_t w,uint16_t h,Color color)
	{

		for(uint16_t i = x; i< x+w ; ++i)
		{
			setpixelxy(i , y, color) ;
			setpixelxy(i , y + h, color) ;

	//		array[(i*width + x)] = color ;
	//		array[(i*width + x) + h] = color ;
	//		setpixelxy(i , y + h, color) ;

			}

		for(uint16_t p = 0 ; p<=w ;++p)
		{

			for(uint16_t o = y ; o<=h+y ;++o)
			{
				setpixelxy(x , o, color) ;
				setpixelxy(x + p , o, color) ;
			//	array[(x*width + o)+ (h*p)] = color ;
	//			array[((x +p)*width + o) ] = color ;

			}
	}
	}
	
	Color & ColorImage::pixel(uint16_t x,uint16_t y)
	{
		
		Color couleur(array[(y * width + x ) * 3] ,array[(y * width + x) * 3 + 1] ,array[(y * width + x)* 3 +2] );
		return  couleur ;
		
		
		
		
	}
const  Color & ColorImage::pixel(uint16_t x,uint16_t y) const
	{
		
		Color couleur(array[(y * width + x)*3 ] ,array[y * width + x + 1] ,array[y * width + x +2] );
		return  couleur ;
		
		
		
		
	}
ColorImage * ColorImage::simpleScale (uint16_t w , uint16_t h) const
{

  ColorImage * retour = new ColorImage(w,h) ;

  double ratiow = (double)((width)/w) ;
  double ratioh = (double)((height)/h) ;

  for(uint16_t _y = 0 ; _y < h; ++_y)
  {
    for(uint16_t _x = 0 ; _x < w ; ++_x)
    {
      double x  = _x * ratiow ;
      double y  = _y * ratioh ;

      uint16_t xtronc = (uint16_t)x;
      uint16_t ytronc = (uint16_t)y;
      retour->pixel(_x , _y) = pixel(xtronc  , ytronc);


    }


  }

  return retour ;


}
 
