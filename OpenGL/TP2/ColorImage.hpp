#include <stdint.h>
#include "stdint.h"
#include <iostream>
#include <inttypes.h>
#include "inttypes.h"
#include "Color.hpp"


class ColorImage
{
	const uint16_t width,height;
	uint8_t *array;

	public :
	ColorImage() = delete;
	ColorImage & operator=(const ColorImage& b) = delete;
	ColorImage(uint16_t w,uint16_t h);
	ColorImage(const ColorImage& orig);
	~ColorImage();



	void writePPM(std::ostream & f) const;
	ColorImage * simpleScale(uint16_t w,uint16_t h) const;
	static ColorImage * readPPM(std::istream & is);
	static void skip_line(std::istream & f);			//dans le cours c'est pas static
	static void skip_comments(std::istream & f);		//dans le cours c'est pas static
	void clear(Color color);
	void  setpixelxy(uint16_t x ,uint16_t y , Color color);
	Color getpixelxy(uint16_t x ,uint16_t y );
	Color & pixel(uint16_t x,uint16_t y);// Accesseur de modification
	const  Color& pixel(uint16_t x , uint16_t y) const ;
	void rectangle(uint16_t x,uint16_t y,uint16_t w,uint16_t h,Color color);
	void fillRectangle(uint16_t x,uint16_t y,uint16_t w,uint16_t h,Color color);

};
