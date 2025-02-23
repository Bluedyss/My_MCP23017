#include "My_MCP23017.h"

My_MCP23017::My_MCP23017(uint8_t address) {
    _address = address;
    _iodirA = 0xFF;  // Default: all pins set as inputs
    _iodirB = 0xFF;
}

void My_MCP23017::begin() {
    Wire.begin();
    writeRegister(IODIRA, _iodirA);  // Set initial direction for PORTA
    writeRegister(IODIRB, _iodirB);  // Set initial direction for PORTB
}

void My_MCP23017::pinMode(uint8_t pin, uint8_t mode) {
    if (pin < 8) {
        // Modify PORTA direction
        if (mode == OUTPUT) _iodirA &= ~(1 << pin);
        else _iodirA |= (1 << pin);
        writeRegister(IODIRA, _iodirA);
    } else if (pin < 16) {
        // Modify PORTB direction
        pin -= 8;
        if (mode == OUTPUT) _iodirB &= ~(1 << pin);
        else _iodirB |= (1 << pin);
        writeRegister(IODIRB, _iodirB);
    }
}

void My_MCP23017::digitalWrite(uint8_t pin, uint8_t value) {
    uint8_t reg = (pin < 8) ? GPIOA : GPIOB;
    uint8_t bit = (pin < 8) ? pin : (pin - 8);
    uint8_t current = readRegister(reg);

    if (value) current |= (1 << bit);
    else current &= ~(1 << bit);

    writeRegister(reg, current);
}

uint8_t My_MCP23017::digitalRead(uint8_t pin) {
    uint8_t reg = (pin < 8) ? GPIOA : GPIOB;
    uint8_t bit = (pin < 8) ? pin : (pin - 8);
    return (readRegister(reg) & (1 << bit)) ? HIGH : LOW;
}

void My_MCP23017::writePortA(uint8_t value) {
    writeRegister(GPIOA, value);
}

void My_MCP23017::writePortB(uint8_t value) {
    writeRegister(GPIOB, value);
}

uint8_t My_MCP23017::readPortA() {
    return readRegister(GPIOA);
}

uint8_t My_MCP23017::readPortB() {
    return readRegister(GPIOB);
}

void My_MCP23017::writeRegister(uint8_t reg, uint8_t value) {
    Wire.beginTransmission(_address);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

uint8_t My_MCP23017::readRegister(uint8_t reg) {
    Wire.beginTransmission(_address);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(_address, (uint8_t)1);
    return Wire.available() ? Wire.read() : 0;
}
