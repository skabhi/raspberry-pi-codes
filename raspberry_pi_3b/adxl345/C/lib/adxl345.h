#ifndef ADXL345_H
#define ADXL345_H

#include <iostream>
#include <wiringPiI2C.h>
#include "adxl345_registers.h"

class ADXL345 {
public:
    ADXL345(int deviceId);
    ~ADXL345();

    int getDeviceID();
    void getODR();
    void setODR(int8_t rate);
    void setFullResXG(int8_t xg);
    void readAcceleration(float &x, float &y, float &z);
    void startMeasurement();

private:
    int fd;
};

#endif // ADXL345_H
