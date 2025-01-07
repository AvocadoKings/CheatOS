#ifndef TFT_h
#define TFT_h

#include <utils.h>
#include "driver/spi_master.h"
#include "soc/spi_struct.h"
#include "soc/spi_reg.h"


#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   15  // Chip select control pin
#define TFT_DC   2  // Data Command control pin
#define TFT_RST  4 

#define SPIFreq 27000000
#define TFTWidth 320
#define TFTHeight 240

void sendCommand(uint8_t cmd);

void sendData(uint8_t data);

void TFTInit();

void setAddrWindow(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1);

void drawPixel(uint16_t x, uint16_t y, uint16_t c,uint16_t *screen);
void drawPixels(const uint16_t* data_in);

void fillArea(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t c, uint16_t* screen);

void drawImage(const char* path,int x0, int y0, int width, int height, uint16_t* screen);
void drawImage(String img,int x0, int y0, int width, int height, uint16_t* screen);

class TFTFrame{
public:
   TFTFrame();
};

#endif