#include "mbed.h"
#include "ADXL343.h"


ADXL343::ADXL343(I2C *i2c): _device(i2c) {
  // set low power bit for normal operation
  _device->writeReg(BW_RATE, 0x0A);    // default value
  _device->writeReg(DATA_FORMAT, 0x3); // set range to +/- 16g
  _device->writeReg(FIFO_MODE, 0x00);  // bypass FIFO mode
}

void ADXL343::read(int acc[3]) {
 //TODO: request a read
  data[0] = DATAX0 | (1 << 7);

  _device->write(ACC_ADDRESS, data, 1);
  _device->read(ACC_ADDRESS, data, 6);

  byte xl = data[0];
  byte xh = data[1];
  byte yl = data[2];
  byte yh = data[3];
  byte zl = data[4];
  byte zh = data[5];

  acc[0] = (short) (xh << 8 | xl); 
  acc[1] = (short) (yh << 8 | yl); 
  acc[2] = (short) (zh << 8 | zl); 
}
/*
void ADXL343::enableDefault(void) {


}*/

void ADXL343::writeReg(byte reg, byte value) {
  data[0] = reg;
  data[1] = value;

  _device->write(ACC_ADDRESS, data, 2);
}

byte ADXL343::readReg(byte reg) {
  byte value = 0;

  _device->write(ACC_ADDRESS, &reg, 1);
  _device->read(ACC_ADDRESS, &value, 1);

  return value;
}

