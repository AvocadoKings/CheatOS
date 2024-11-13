#include "SDManager.h"

SdFat32 _initSd_(){
    SdFat32 SD;

    if(!SD.begin(SDCSpin, SD_SCK_MHZ(4))){
        Serial.println("Could not initialize Sd card!");
    }
    if (SD.vol()->fatType() == SDFAT) {
        Serial.println("Fat type partition not found!");
    }

    return SD;
};


File32 getFile(const char* path, bool write){
    File32 file;

    if(!file.open(path, (write) ? FILE_WRITE : FILE_READ)){
        Serial.println("Error opeining file!");
    }

    return file;
};