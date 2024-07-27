#ifndef ADXL345_REGISTERS_H
#define ADXL345_REGISTERS_H

#define REG_DEVID         0x00
#define REG_OFSX          0x1E
#define REG_OFSY          0x1F
#define REG_OFSZ          0x20

#define REG_BW_RATE       0x2C
#define REG_POWER_CTL     0x2D
#define REG_DATA_FORMAT   0x31
#define REG_DATA_X_LOW    0x32
#define REG_DATA_X_HIGH   0x33
#define REG_DATA_Y_LOW    0x34
#define REG_DATA_Y_HIGH   0x35
#define REG_DATA_Z_LOW    0x36
#define REG_DATA_Z_HIGH   0x37

// REG_BW_RATE write values
#define ODR_3200          0X0F
#define ODR_1600          0X0E
#define ODR_800           0X0D
#define ODR_400           0X0C
#define ODR_200           0X0B
#define ODR_100           0X0A
#define ODR_50            0X09
#define ODR_25            0X08
#define ODR_12_5          0X07

#define ODR_400_LP        0X1C
#define ODR_200_LP        0X1B
#define ODR_100_LP        0X1A
#define ODR_50_LP         0X19
#define ODR_25_LP         0X18
#define ODR_12_5_LP       0X17

// REG_DATA_FORMAT write values
#define FULL_RES_2G       0X08
#define FULL_RES_4G       0X09
#define FULL_RES_8G       0X0A
#define FULL_RES_16G      0X0B
#define TEN_BIT_2G        0X00
#define TEN_BIT_4G        0X01
#define TEN_BIT_8G        0X02
#define TEN_BIT_16G       0X03

#endif // ADXL345_REGISTERS_H
