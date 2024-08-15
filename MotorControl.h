// MotorControl.h
// Mecha Platypus
// This header file declares the MotorControl class, which manages all motor and servo operations for the robot.

#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <Adafruit_PWMServoDriver.h>
#include "Constants.h"

class MotorControl {
public:
    MotorControl();
    void init();  // Initialize the motor control system
    void setDriveMotors(int leftSpeed, int rightSpeed);  // Set speeds for drive motors
    void activateIntake();  // Turn on the intake system
    void stopIntake();  // Turn off the intake system
    void openGate();  // Open the gate servo
    void closeGate();  // Close the gate servo
    void liftUp();  // Activate the lift to move up
    void liftDown();  // Activate the lift to move down
    void stopLift();  // Stop the lift movement
    void applyMotorSettings();  // Apply all current motor and servo settings

private:
    Adafruit_PWMServoDriver pwm;  // PWM driver for motor control
    // Motor speed variables
    int leftHighSpeed, leftLowSpeed, rightHighSpeed, rightLowSpeed;
    int liftHighSpeed, liftLowSpeed, intakeSpeed;
    int gatePosition;  // Position of the gate servo
    
    void setDCMotors();  // Set PWM values for DC motors
    void setServoGate();  // Set PWM value for gate servo
};

#endif // MOTOR_CONTROL_H