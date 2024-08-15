// MotorControl.cpp
// Mecha Platypus
// This file implements the MotorControl class, handling all motor and servo operations.

#include "MotorControl.h"
#include <Wire.h>

// Constructor: Initialize all motor speeds and positions to 0
MotorControl::MotorControl() : 
    leftHighSpeed(0), leftLowSpeed(0), rightHighSpeed(0), rightLowSpeed(0),
    liftHighSpeed(0), liftLowSpeed(0), intakeSpeed(0), gatePosition(0) {}

// Initialize the PWM driver
void MotorControl::init() {
    Wire.begin();
    pwm.begin();
    pwm.setOscillatorFrequency(27000000);
    pwm.setPWMFreq(50);  // Set to 50Hz for most RC servos
}

// Set drive motor speeds based on joystick input
void MotorControl::setDriveMotors(int leftSpeed, int rightSpeed) {
    // Map joystick values (-128 to 127) to motor speeds (0 to MAX_SPEED)
    if (leftSpeed < 0) {
        leftLowSpeed = map(abs(leftSpeed), 0, 128, 0, MAX_SPEED);
        leftHighSpeed = 0;
    } else {
        leftHighSpeed = map(leftSpeed, 0, 128, 0, MAX_SPEED);
        leftLowSpeed = 0;
    }
    
    if (rightSpeed < 0) {
        rightLowSpeed = map(abs(rightSpeed), 0, 128, 0, MAX_SPEED);
        rightHighSpeed = 0;
    } else {
        rightHighSpeed = map(rightSpeed, 0, 128, 0, MAX_SPEED);
        rightLowSpeed = 0;
    }
}

// Activate the intake system at maximum speed
void MotorControl::activateIntake() {
    intakeSpeed = MAX_INTAKE;
}

// Stop the intake system
void MotorControl::stopIntake() {
    intakeSpeed = 0;
}

// Open the gate (set servo to open position)
void MotorControl::openGate() {
    gatePosition = 400; // Adjust this value as needed for specific servo (when the robot is built)
}

// Close the gate (set servo to closed position)
void MotorControl::closeGate() {
    gatePosition = 0; // Adjust this value as needed for specific servo (when the robot is built)
}

// Activate the lift to move upwards
void MotorControl::liftUp() {
    liftHighSpeed = MAX_LIFT;
    liftLowSpeed = 0;
}

// Activate the lift to move downwards
void MotorControl::liftDown() {
    liftHighSpeed = 0;
    liftLowSpeed = MAX_LIFT;
}

// Stop the lift movement
void MotorControl::stopLift() {
    liftHighSpeed = 0;
    liftLowSpeed = 0;
}

// Apply all current motor and servo settings
void MotorControl::applyMotorSettings() {
    setDCMotors();
    setServoGate();
}

// Set PWM values for all DC motors
void MotorControl::setDCMotors() {
    pwm.setPWM(motor_left_high, 0, leftHighSpeed);
    pwm.setPWM(motor_left_low, 0, leftLowSpeed);
    pwm.setPWM(motor_right_high, 0, rightHighSpeed);
    pwm.setPWM(motor_right_low, 0, rightLowSpeed);
    pwm.setPWM(motor_lift_high, 0, liftHighSpeed);
    pwm.setPWM(motor_lift_low, 0, liftLowSpeed);
    pwm.setPWM(motor_intake, 0, intakeSpeed);
}

// Set PWM value for the gate servo
void MotorControl::setServoGate() {
    pwm.setPWM(servo_gate, 0, gatePosition);
}