// PS2Control.h
// Mecha Platypus
// This header file declares the PS2Control class, which manages all PS2 controller input for the robot.

#ifndef PS2_CONTROL_H
#define PS2_CONTROL_H

#include <PS2X_lib.h>
#include "Constants.h"

class PS2Control {
public:
    PS2Control();
    void setup();  // Initialize the PS2 controller
    void readGamepad();  // Read the latest input from the PS2 controller
    int getLeftStickY();  // Get the Y-axis value of the left analog stick
    int getRightStickY();  // Get the Y-axis value of the right analog stick
    bool isButtonPressed(int button);  // Check if a specific button is pressed

private:
    PS2X ps2x;  // PS2X library object for controller communication
};

#endif // PS2_CONTROL_H