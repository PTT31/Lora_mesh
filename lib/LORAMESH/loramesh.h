#ifndef _LORAMESH_H
#define _LORAMESH_H
#include "stdio.h"
class LoraMesh{
    public:
    static LoraMesh& Init(){
        static LoraMesh instance;
        return instance;
    }
    struct LoraMesh_config
    {
         // LoRa pins
        uint8_t loraCs = 0; // LoRa chip select pin
        uint8_t loraIrq = 0; // LoRa IRQ pin
        uint8_t loraRst = 0; // LoRa reset pin
        uint8_t loraIo1 = 0; // LoRa DIO1 pin\

        LoraMesh_config() {}
    };
    void begin (LoraMesh_config config = LoraMesh_config());
    
};

#endif