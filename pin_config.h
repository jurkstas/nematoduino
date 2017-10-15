#ifndef pin_config_h
#define pin_config_h

// Motor pins

#ifdef FOUR_WHEEL_DRIVE
const uint8_t rightMotor1PinA = 2;
const uint8_t rightMotor1PinB = 3;

const uint8_t leftMotor1PinA = 6;
const uint8_t leftMotor1PinB = 7;

const uint8_t rightMotor2PinA = 4;
const uint8_t rightMotor2PinB = 5;

const uint8_t leftMotor2PinA = 8;
const uint8_t leftMotor2PinB = 9;
#else
const uint8_t rightMotorPinA = 9;
const uint8_t rightMotorPinB = 10;

const uint8_t leftMotorPinA = 3;
const uint8_t leftMotorPinB = 11;
#endif

// Button pin (configured so that on is LOW)
const uint8_t buttonPin = 13;

// Transmit and receive pins for distance sensor
const uint8_t tPin = 33;
const uint8_t rPin = 32;

// Transmit and receive pins for front right distance sensor
const uint8_t tRPin = 39;
const uint8_t rRPin = 38;

// Transmit and receive pins for front left  distance sensor
const uint8_t tLPin = 21;
const uint8_t rLPin = 20;

//Tail Right
const uint8_t tTLPin = 47;
const uint8_t rTLPin = 46;

//Tail Left
const uint8_t tTRPin = 22;
const uint8_t rTRPin = 23;

// Pin for status LED (turns on when nose touch neurons stimulated)
const uint8_t statusPin = 12;

const uint8_t LightSensorPin = 51;

#endif
