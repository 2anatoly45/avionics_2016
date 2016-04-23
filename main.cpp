#include "mbed.h"
#include "L3G4200D.h"
#include "MPL115A2.h"

DigitalOut led(LED1);


I2C i2c(p9, p10);        // sda, scl
L3G4200D gyro(p28, p27);

Serial pc(USBTX, USBRX); // tx, rx

//MPL115A2 p_sensor(&i2c, &pc); //DEBUG verion
MPL115A2 p_sensor(&i2c);


int main() {

  p_sensor.begin();

  pc.printf("\n\n\nHello World!\n\n");

  int g[3];

  while(1) {
    p_sensor.ReadSensor();
    pc.printf("Pressure  = %f\n\r", p_sensor.GetPressure());
    pc.printf("Temp      = %f\n\r", p_sensor.GetTemperature());

    gyro.read(g);
    pc.printf("Gyro      = %d,   %d,   %d\n\r", g[0],g[1],g[2]);

    //accel.read();
    //pc.printf("Accel     = %f,   %f,   %f,\n\r", /* */ );

    wait(1);
  }

  return 0;
}
