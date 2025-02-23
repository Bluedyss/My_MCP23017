#ifndef MY_MCP23017_H
#define MY_MCP23017_H

#include <Arduino.h>
#include <Wire.h>

#define MCP23017_DEFAULT_ADDR 0x20  // Default I2C address (A0, A1, A2 connected to GND)

// MCP23017 register addresses
#define IODIRA   0x00  // Direction register for PORTA (1 = input, 0 = output)
#define IODIRB   0x01  // Direction register for PORTB
#define GPIOA    0x12  // Port register for PORTA (read/write)
#define GPIOB    0x13  // Port register for PORTB
#define OLATA    0x14  // Output latch register for PORTA
#define OLATB    0x15  // Output latch register for PORTB

class My_MCP23017 {
public:
    My_MCP23017(uint8_t address = MCP23017_DEFAULT_ADDR);
    void begin();

    void pinMode(uint8_t pin, uint8_t mode);
    void digitalWrite(uint8_t pin, uint8_t value);
    uint8_t digitalRead(uint8_t pin);

    void writePortA(uint8_t value);
    void writePortB(uint8_t value);
    uint8_t readPortA();
    uint8_t readPortB();

private:
    uint8_t _address;
    uint8_t _iodirA, _iodirB;  // Stores pin direction configuration

    void writeRegister(uint8_t reg, uint8_t value);
    uint8_t readRegister(uint8_t reg);
};

#endif
