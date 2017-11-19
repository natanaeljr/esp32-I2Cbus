**I2Cbus**
==========

I2C interface library for working with **ESP32 _esp-idf_**, and supports master mode only.

The intention of this library is to read and write to I2C slave devices with ease, by providing quick and specific functions aimed at 8-bit registers. It is based on I2Cdev by Jeff Rowberg.

You can clone it right into your project components directory or in your specific library path.

`git clone https://github.com/natanaeljr/I2Cbus-esp32.git I2Cbus`

## Usage

The library provides two ready-to-use objects: `I2Cbus0` which corresponds to ESP32 I2C port 0, and `I2Cbus1` which corresponds to ESP32 I2C port 1. However you can create your own object as you will.

### Example:

```C++
// default objects
I2Cbus0.begin(GPIO_NUM_16, GPIO_NUM_17);
I2Cbus1.begin(GPIO_NUM_21, GPIO_NUM_22);
// OR
// create an object which manages port 0
I2Cbus_t myI2C(I2C_NUM_0);
// configure and initialize
myI2C.begin(GPIO_NUM_21, GPIO_NUM_22, 400000);  // 400KHz

// call methods
myI2C.setTimeout(100);  // default 1000ms
myI2C.scanner();
myI2C.close();
```

### List of methods:

```C++
// SETUP
esp_err_t begin(gpio_num_t sda_io_num, gpio_num_t scl_io_num, uint32_t clk_speed = I2CBUS_CLOCKSPEED_DEFAULT);
esp_err_t begin(gpio_num_t sda_io_num, gpio_num_t scl_io_num, gpio_pullup_t sda_pullup_en, gpio_pullup_t scl_pullup_en, uint32_t clk_speed = I2CBUS_CLOCKSPEED_DEFAULT);
esp_err_t close();
void setTimeout(uint32_t ms);

// WRITING
esp_err_t writeBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t data, int32_t timeout = -1);
esp_err_t writeBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t data, int32_t timeout = -1);
esp_err_t writeByte(uint8_t devAddr, uint8_t regAddr, uint8_t data, int32_t timeout = -1);
esp_err_t writeBytes(uint8_t devAddr, uint8_t regAddr, size_t length, const uint8_t *data, int32_t timeout = -1);

// READING
esp_err_t readBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t *data, int32_t timeout = -1);
esp_err_t readBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t *data, int32_t timeout = -1);
esp_err_t readByte(uint8_t devAddr, uint8_t regAddr, uint8_t *data, int32_t timeout = -1);
esp_err_t readBytes(uint8_t devAddr, uint8_t regAddr, size_t length, uint8_t *data, int32_t timeout = -1);

// TOOLS
esp_err_t testConnection(uint8_t devAddr, int32_t timeout = -1);
void scanner();
```

## Menuconfig

You can change some library settings in menuconfig under components and I2Cbus.

![menuconfig-I2Cbus](https://raw.githubusercontent.com/natanaeljr/gh-assets/master/I2Cbus-esp32/menuconfig1.png "Menuconfig I2Cbus")

---

Copyright (c) 2017 Natanael Rabello