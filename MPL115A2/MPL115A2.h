/*
 MPL115A2 Sensor Library for mbed   
   ported to mbed by joe holdsworth <joeholdsworth@gmail.com>
   created for arduino by R.N <zan73722@gmail.com>

   2012-05-07 Ported mbed beta version - tested on LPC1768
*/

#ifndef MPL115A2_H
#define MPL115A2_H

#include "mbed.h"

class MPL115A2
{
    private:
        DigitalOut _shdnPin;
        bool _bShutdown;
        short _i2c_address;
        short _sia0, _sib1, _sib2, _sic12, _sic11, _sic22;
        unsigned short _uiPadc, _uiTadc;
        I2C *_i2c;
        Serial *_pc;
        bool _debug;
       
        
    public:
        MPL115A2(I2C *i2c, const PinName shdnPin = p21);
        MPL115A2(I2C *i2c, Serial *pc, const PinName shdnPin = p21); //pass serial for debug
        void begin();
        void shutdown();
        void ReadSensor();
        float GetPressure();
        float GetTemperature();
};
#endif