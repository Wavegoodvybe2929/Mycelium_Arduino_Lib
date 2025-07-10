#include "MyceliumSensor.h"

MyceliumSensor::MyceliumSensor(uint8_t pinA, uint8_t pinB, float threshold)
    : _pinA(pinA), _pinB(pinB), _threshold(threshold), _lastPotential(0.0) {}

void MyceliumSensor::begin() {
    pinMode(_pinA, INPUT);
    pinMode(_pinB, INPUT);
}

float MyceliumSensor::readPotential() {
    float valA = analogRead(_pinA);
    float valB = analogRead(_pinB);
    float diff = (valA - valB) * (5.0 / 1023.0); // Convert to voltage assuming 10-bit ADC
    _lastPotential = diff;
    return diff;
}

bool MyceliumSensor::detectSpike() {
    float potential = readPotential();
    return fabs(potential) > _threshold;
}

void MyceliumSensor::setThreshold(float newThreshold) {
    _threshold = newThreshold;
}
