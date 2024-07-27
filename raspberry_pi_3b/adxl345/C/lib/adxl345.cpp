#include "adxl345.h"
#include "adxl345_registers.h"
#include <unistd.h> // for usleep

ADXL345::ADXL345(int deviceId) {
    fd = wiringPiI2CSetup(deviceId);
    if (fd == -1) {
        std::cerr << "Failed to init I2C communication.\n";
        throw std::runtime_error("I2C initialization failed");
    }
    std::cout << "I2C communication successfully setup.\n";
}

ADXL345::~ADXL345() {
    // Close the I2C file descriptor if necessary
    if (fd != -1) {
        close(fd);
    }
}

int ADXL345::getDeviceID() {
    return wiringPiI2CReadReg8(fd, REG_DEVID);
}

void ADXL345::getODR() {
    int rate = wiringPiI2CReadReg8(fd, REG_BW_RATE);
    std::cout << "BW REG: " << rate << "\n";
}

void ADXL345::setODR(int8_t rate) {
    wiringPiI2CWriteReg8(fd, REG_BW_RATE, rate);
}

void ADXL345::setFullResXG(int8_t xg) {
    wiringPiI2CWriteReg8(fd, REG_DATA_FORMAT, xg);
}

void ADXL345::startMeasurement() {
    wiringPiI2CWriteReg8(fd, REG_POWER_CTL, 0b00001000);
}

void ADXL345::readAcceleration(float &x, float &y, float &z) {
    int16_t dataX = wiringPiI2CReadReg16(fd, REG_DATA_X_LOW);
    int16_t dataY = wiringPiI2CReadReg16(fd, REG_DATA_Y_LOW);
    int16_t dataZ = wiringPiI2CReadReg16(fd, REG_DATA_Z_LOW);

    x = static_cast<float>(dataX) / 256.0f;
    y = static_cast<float>(dataY) / 256.0f;
    z = static_cast<float>(dataZ) / 256.0f;
}
