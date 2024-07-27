// Example ADXL345 code

#include "../lib/adxl345.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "../lib/adxl345_registers.h"


#define DEVICE_ID 0x53

int main() {
    try {
        ADXL345 sensor(DEVICE_ID);
        
        int id = sensor.getDeviceID();
        sensor.setODR(ODR_200_LP);
        sensor.setFullResXG(FULL_RES_16G);
        sensor.getODR();
        
        std::cout << "ID: " << id << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        sensor.startMeasurement();

        for (int i = 0; i < 10000; ++i) {
            float x, y, z;
            sensor.readAcceleration(x, y, z);
            std::cout << "x: " << x << ", y: " << y << ", z: " << z << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << "\n";
        return -1;
    }

    return 0;
}


