#include <stdint.h>
#include "stdint.h"
#include <iostream>
#include <inttypes.h>
#include "inttypes.h"


class GrayImage
{
public:
	const uint16_t width,height;
	uint8_t *array;

	public :
	GrayImage() = delete;
	GrayImage & operator=(const GrayImage& b) = delete;
	GrayImage(uint16_t w,uint16_t h);
	GrayImage(const GrayImage& orig);
	~GrayImage();



	void writePGM(std::ostream & f) const;
	static GrayImage * readPGM(std::istream & is);
	static void skip_line(std::istream & f);			//dans le cours c'est pas static
	static void skip_comments(std::istream & f);		//dans le cours c'est pas static
	void clear(uint8_t color);
	void rectangle(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint8_t color);
	inline uint16_t getwidht() { return width ;};
	inline uint16_t getheight() { return height ;};
	inline uint16_t getpx(uint16_t x , uint16_t y) {  return array[y*width + x];};
	inline void setpx(uint16_t x , uint16_t y , uint8_t valeur) {array[y*width + x] = valeur;};
	void fillRectangle(uint16_t x,uint16_t y,uint16_t w,uint16_t h,uint8_t color) ;
	GrayImage * SimpleScale(uint16_t w , uint16_t h) const;
	inline uint8_t& pixel(uint16_t x,uint16_t y){return  array[y * width + x ] ;  } ;// Accesseur de modification
  inline  const  uint8_t& pixel(uint16_t x , uint16_t y) const {return  array[y * width + x ] ;  } ;
	GrayImage * bilinearScal(uint16_t w,uint16_t h) const;
};
