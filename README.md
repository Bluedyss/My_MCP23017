# My_MCP23017 Library

This is an Arduino library for controlling the MCP23017 I/O expander over the I2C bus without using external libraries.

## Features
- Control 16 digital I/O pins via I2C
- Set pin modes (input/output)
- Read and write digital values
- Read and write entire ports (PORTA and PORTB)
- Simple and lightweight implementation

## Functions

### `My_MCP23017(uint8_t address = 0x20)`
Creates an instance of the MCP23017 library with the specified I2C address.

### `void begin()`
Initializes the MCP23017 and sets default pin directions.

### `void pinMode(uint8_t pin, uint8_t mode)`
Sets the mode of a specific pin (INPUT or OUTPUT).

### `void digitalWrite(uint8_t pin, uint8_t value)`
Writes a HIGH or LOW value to a specified pin.

### `uint8_t digitalRead(uint8_t pin)`
Reads the state of a specified pin (HIGH or LOW).

### `void writePortA(uint8_t value)`
Writes an 8-bit value to all pins in PORTA.

### `void writePortB(uint8_t value)`
Writes an 8-bit value to all pins in PORTB.

### `uint8_t readPortA()`
Reads the 8-bit state of PORTA.

### `uint8_t readPortB()`
Reads the 8-bit state of PORTB.

## Example Usage

```cpp
#include <Wire.h>
#include "My_MCP23017.h"

My_MCP23017 mcp(0x20); // MCP23017 at default I2C address

void setup() {
    Serial.begin(9600);
    mcp.begin(); // Initialize MCP23017

    // Set all pins as outputs
    for (uint8_t i = 0; i < 16; i++) {
        mcp.pinMode(i, OUTPUT);
    }
}

void loop() {
    // Blink all pins
    for (uint8_t i = 0; i < 16; i++) {
        mcp.digitalWrite(i, HIGH);
    }
    delay(500);
    for (uint8_t i = 0; i < 16; i++) {
        mcp.digitalWrite(i, LOW);
    }
    delay(500);
}
```

## Installation
1. Download the ZIP file from GitHub or [here](sandbox:/mnt/data/My_MCP23017.zip).
2. Extract it to your `Documents/Arduino/libraries/` folder.
3. Restart the Arduino IDE and use `#include "My_MCP23017.h"` in your sketch.

