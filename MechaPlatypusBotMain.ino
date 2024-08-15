// Mecha Platypus

// Include necessary libraries and header files
#include <Wire.h>            // For I2C communication
#include <PID_v1.h>          // For PID control
#include "Constants.h"       // Custom constants for the project
#include "MotorControl.h"    // Custom class for motor control
#include "PS2Control.h"      // Custom class for PS2 controller input

// PID controller instance
// These variables will be used for PID control 
double Input, Output, Setpoint;
PID pid(&Input, &Output, &Setpoint, const_Kp, const_Ki, const_Kd, DIRECT);

// Declare instances of our custom classes
MotorControl motorControl;   // Handles all motor and servo operations
PS2Control ps2Control;       // Handles PS2 controller input

void setup() {
    // Initialize serial communication for debugging
    Serial.begin(115200);
    
    // Initialize motor control system
    motorControl.init();
    
    // Setup PS2 controller
    ps2Control.setup();
    
    // Set PID output limits
    // This sets the maximum and minimum values the PID controller can output
    pid.SetOutputLimits(-255, 255);
}

void loop() {
    // Read PS2 controller input
    // This updates the internal state of the ps2Control object with the latest controller data
    ps2Control.readGamepad();
    
    // Control robot movement
    // Get the Y-axis values of both analog sticks for tank-style control
    int leftSpeed = ps2Control.getLeftStickY();
    int rightSpeed = ps2Control.getRightStickY();
    // Set the drive motors based on the stick positions
    motorControl.setDriveMotors(leftSpeed, rightSpeed);
    
    // Control intake system
    // Activate the intake system when the Cross button (X on PlayStation) is pressed
    if (ps2Control.isButtonPressed(PSB_CROSS)) {
        motorControl.activateIntake();
    } else {
        motorControl.stopIntake();
    }
    
    // Control gate system
    // Open the gate when the Circle button (O on PlayStation) is pressed
    if (ps2Control.isButtonPressed(PSB_CIRCLE)) {
        motorControl.openGate();
    } else {
        motorControl.closeGate();
    }
    
    // Control lift system
    // Lift up when Triangle is pressed, down when Square is pressed
    if (ps2Control.isButtonPressed(PSB_TRIANGLE)) {
        motorControl.liftUp();
    } else if (ps2Control.isButtonPressed(PSB_SQUARE)) {
        motorControl.liftDown();
    } else {
        motorControl.stopLift();
    }
    
    // Apply all motor controls
    // This function call updates all motor and servo positions based on the current settings
    motorControl.applyMotorSettings();
    
    // Short delay to prevent over-polling and allow time for motor updates
    delay(50);
}