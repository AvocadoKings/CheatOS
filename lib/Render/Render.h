#ifndef RENDER_H
#define RENDER_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_ImageReader.h>
#include <SdFat.h>

#define screenWidth 320
#define screenHeight 240
#define CSpin 14
#define DCpin 27
#define MOSIpin 23
#define SCLKpin 18
#define RSTpin 33

Adafruit_ST7789 _initDisplay_();
Adafruit_ImageReader _initReader_(SdFat32 SD);

uint16_t rgb(int r, int g, int b);

void drawPixel(Adafruit_ST7789 display, uint16_t x, uint16_t y, uint16_t c);

void drawLine(Adafruit_ST7789 display, uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t c);

void drawRect(Adafruit_ST7789 display, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t );

void drawRRect(Adafruit_ST7789 display, uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t r, uint16_t c);

void drawTri(Adafruit_ST7789 display, uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t c);

void drawCircle(Adafruit_ST7789 display, uint16_t x, uint16_t y, uint16_t r, uint16_t c);

void drawBitmap(Adafruit_ST7789 display, uint16_t x, uint16_t y, uint8_t *map, uint16_t w, uint16_t h, uint16_t c);

void drawImage(Adafruit_ST7789 display, Adafruit_ImageReader reader, const char* path, uint16_t x, uint16_t y);

#endif