// Constants.h
// Mecha Platypus
// This file defines various constants used throughout the project.

#ifndef CONSTANTS_H
#define CONSTANTS_H

// Define constants for PID controller
// These values may need tuning based on our robot (if we decide to build it lol) and requirements
#define const_Kp 0.5  // Proportional gain
#define const_Ki 0.6  // Integral gain
#define const_Kd 0.7  // Derivative gain

// PS2 controller pin definitions
// These should match the pins where our PS2 controller is connected
#define PS2X_CMD 13  // Command pin
#define PS2X_DAT 12  // Data pin
#define PS2X_SEL 15  // Select pin
#define PS2X_CLK 14  // Clock pin

// Motor and servo pin definitions
// These should match the pins where our motors and servos are connected on the PWM driver
#define motor_left_high 10   // Left drive motor forward
#define motor_left_low 11    // Left drive motor reverse
#define motor_right_high 12  // Right drive motor forward
#define motor_right_low 13   // Right drive motor reverse
#define motor_intake 5       // Intake motor
#define servo_gate 6         // Gate servo
#define motor_lift_high 8    // Lift motor up
#define motor_lift_low 9     // Lift motor down

// Max speed constants for motors and servo
// These values may need adjustment based on our specific motors and power system
#define MAX_SPEED 2000   // Maximum speed for drive motors
#define MAX_INTAKE 4000  // Maximum speed for intake motor
#define MAX_LIFT 4000    // Maximum speed for lift motor

#endif // CONSTANTS_H