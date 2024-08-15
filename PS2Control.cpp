// PS2Control.cpp
// This file implements the PS2Control class, handling all PS2 controller input operations.

#include "PS2Control.h"

// Constructor
PS2Control::PS2Control() {}

// Initialize the PS2 controller
void PS2Control::setup() {
    int error = -1;
    // Try to configure the controller multiple times in case of initial failure
    for (int i = 0; i < 10; i++) {
        delay(1000);  // Wait 1 second between attempts
        // Attempt to configure the controller
        error = ps2x.config_gamepad(PS2X_CLK, PS2X_CMD, PS2X_SEL, PS2X_DAT);
        Serial.print(".");  // Print a dot for each attempt
    }
    
    // Report the result of the configuration attempts
    switch (error) {
        case 0:
            Serial.println("Connected to PS2 controller successfully.");
            break;
        case 1:
            Serial.println("ERROR: Controller not found.");
            break;
        case 2:
            Serial.println("ERROR: Communication error.");
            break;
        case 3:
            Serial.println("ERROR: Unable to enter pressures mode.");
            break;
    }
}

// Read the latest input from the PS2 controller
void PS2Control::readGamepad() {
    ps2x.read_gamepad(false, false);
}

// Get the Y-axis value of the left analog stick
// Returns a value from -128 (up) to 127 (down)
int PS2Control::getLeftStickY() {
    return 128 - ps2x.Analog(PSS_LY);
}

// Get the Y-axis value of the right analog stick
// Returns a value from -128 (up) to 127 (down)
int PS2Control::getRightStickY() {
    return 128 - ps2x.Analog(PSS_RY);
}

// Check if a specific button is pressed
// 'button' should be one of the PSB_* constants defined in the PS2X library
bool PS2Control::isButtonPressed(int button) {
    return ps2x.Button(button);
}