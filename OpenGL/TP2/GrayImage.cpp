#include "GrayImage.hpp"
#include <stdint.h>
#include <iostream>
#include <stdexcept>

GrayImage::GrayImage(uint16_t w,uint16_t h)
	: width(w), height(h), array(nullptr)
{
	array = new uint8_t [width * height];
}


GrayImage::GrayImage(const GrayImage& o)
	:	width(o.width) , height(o.height), array(nullptr)
{
	array = new uint8_t[o.width * o.height];
	for(size_t t=0 ; t < size_t(o.width * o.height) ; t++)
		array[t]=o.array[t];
}

GrayImage::~GrayImage()
{
	delete [] array ;
}

void GrayImage::writePGM(std::ostream & f) const
{
	f << "P5 \n" <<"#flousht je suis un commentaire wsoaw incroyable \n" << width << ' ' << height << "\n";

	f << "255\n";

	f.write((const char *) array , size_t (width * height)) ;
}

void GrayImage::skip_line(std::istream & f)
{
	char c;
	do{
	f.get(c);
	}
	while(c!= '\n');

}

void GrayImage::skip_comments(std::istream & f)
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

GrayImage * GrayImage::readPGM(std::istream & is)
{
	char c[3];
	is.get(c[0]);
	is.get(c[1]);
	is.get(c[2]);

	if(!(c[0] == 'P' && c[1] == '5' && c[2]=='\n'))
	{
		throw std::runtime_error("This is not a PGM file");
	}
	skip_comments(is);
	uint16_t w,h;
	is >> w >> h ;
	skip_comments(is);
	uint16_t max_c;
	is>> max_c;
	if(max_c > 255) throw std::runtime_error(">255");

	is.get();

	GrayImage * gi = new GrayImage(w,h);

	is.read((char *)gi->array,w*h);
	return gi;
}

void GrayImage::clear(uint8_t color)
{
	for(size_t i = 0; i<= size_t(width * height) ; ++i)
	{
		if(array[i] == color)
		{
			array[i] = 0 ;

		}


	}

}

void GrayImage::rectangle(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint8_t color)
{


	for(uint16_t i = x; i< x+h ; ++i)
	{


		array[(i*width + x)] = color ;
		array[(i*width + x) + w] = color ;
//		setpixelxy(i , y + h, color) ;

		}
		for(uint16_t o = y ; o<=w+y ;++o)
		{
			array[(x*width + o)] = color ;
			array[((x+h)*width + o) ] = color ;

		}
}

void GrayImage::fillRectangle(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint8_t color)
{

	for(uint16_t i = x; i< x+h ; ++i)
	{


		array[(i*width + x)] = color ;
		array[(i*width + x) + w] = color ;
//		setpixelxy(i , y + h, color) ;

		}

	for(uint16_t p = 0 ; p<=h ;++p)
	{

		for(uint16_t o = y ; o<=w+y ;++o)
		{
		//	array[(x*width + o)+ (h*p)] = color ;
			array[((x +p)*width + o) ] = color ;

		}
}
}

GrayImage * GrayImage::SimpleScale (uint16_t w , uint16_t h) const
{

  GrayImage * retour = new GrayImage(w,h) ;

  double ratiow = (double)((width)/w) ;
  double ratioh = (double)((height)/h) ;

  for(uint16_t _y = 0 ; _y < h ; ++_y)
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
GrayImage * GrayImage::bilinearScal(uint16_t w,uint16_t h) const
{
	GrayImage* retour = new GrayImage(w,h);

	double ratiow = (double)(width)/w;
	double ratioh = (double)(height)/h;
	for(uint16_t _y = 0 ; _y <h ; ++_y)
	{for(uint16_t _x = 0 ; _x <w ; ++_x)
	{
	double x = _x * ratiow ;
	double y = _y * ratioh ;
	uint16_t x1 = (uint16_t)x;
		uint16_t y1 = (uint16_t)y;
		double e = x-x1 ;
		double u = y-y1 ;


		uint16_t xp1 = (x1 +1 >= width ? x1 : x1 + 1);
		uint16_t yp1 = (y1 +1 >= height ? y1 : y1 + 1);

		retour->pixel(_x,_y)=
		(1- e) * (1-u) * pixel(x1,y1)
		+ (1-e) * u * pixel(x1 , yp1)
		+ e * (1-u)* pixel(xp1 , y1)
		+ e * u *  pixel(xp1 , yp1);
	}}


	return retour ;


}
