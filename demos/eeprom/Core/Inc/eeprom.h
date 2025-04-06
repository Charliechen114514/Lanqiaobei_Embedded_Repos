#ifndef EEPROM_H
#define EEPROM_H
#include "stm32g4xx_hal.h"

void eeprom_write(uint8_t addr, uint8_t data);

uint8_t eeprom_read(uint8_t addr);

#endif



