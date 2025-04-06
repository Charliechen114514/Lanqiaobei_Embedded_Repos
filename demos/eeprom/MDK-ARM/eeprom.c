#include "eeprom.h"
#include "i2c.h"
void eeprom_write(uint8_t addr, uint8_t data)
{
    I2CStart();
    I2CSendByte(0xA0);
    I2CWaitAck();
    
    I2CSendByte(addr);
    I2CWaitAck();
    
    I2CSendByte(data);
    I2CWaitAck();
    
    I2CStop();
    
    HAL_Delay(20);
}

uint8_t eeprom_read(uint8_t addr)
{
    I2CStart();
    I2CSendByte(0xA0);
    I2CWaitAck();
    
    I2CSendByte(addr);
    I2CWaitAck();
    I2CStop();
    
    I2CStart();
    I2CSendByte(0xA1);
    I2CWaitAck();
    
    uint8_t res = I2CReceiveByte();
    I2CSendNotAck();
    
    I2CStop();
    
    return res;
}
