#ifndef _ADXL343_H
#define _ADXL343_H

#include "mbed.h"

// register addresses

#define DEVID          0x00
#define ACC_ADDRESS    0xE5

#define THRESH-TAP     0x1D
#define OFSX           0x1E
#define OFSY           0x1F
#define OFSZ           0x20
#define DUR            0x21
#define LATENT         0x22
#define WINDOW         0x23
#define THRESH_ACT     0x24
#define THRESH_INACT   0x25
#define TIME_INACT     0x26
#define ACT_INACT_CTL  0x27
#define THRESH_FF      0x28
#define TIME_FF        0x29
#define TAP_AXES       0x2A
#define ACT_TAP_STATUS 0x2B
#define BW_RATE        0x2C
#define POWER_CTL      0x2D
#define INT_ENABLE     0x2E
#define INT_MAP        0x2F
#define INT_SOURCE     0x30
#define DATA_FORMAT    0x31

#define DATAX0         0x32
#define DATAX1         0x33
#define DATAY0         0x34
#define DATAY1         0x35
#define DATAZ0         0x36
#define DATAZ1         0x37

#define FIFO_CTL       0x38
#define FIFO_STATUS    0x39

typedef char byte;

class ADXL343 {

  public:

    ADXL343(I2C *i2c);
    void read(int acc[3]);

  private:

//    void enableDefault(void);
    void writeReg(byte reg, byte value);
    byte readReg(byte reg);

    I2C *_device;
    byte _data[6];
    int _rates[3];

}; 


#endif
