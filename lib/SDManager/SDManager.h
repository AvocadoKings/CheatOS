#ifndef SDMANAGER_H
#define SDMANAGER_H

#include <Arduino.h>
#include <SdFat.h>

#define SDFAT 1
#define SDCSpin 4

SdFat32 _initSd_();

File32 getFile(const char* path, bool write=0);

#endif