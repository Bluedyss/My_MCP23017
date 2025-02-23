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
