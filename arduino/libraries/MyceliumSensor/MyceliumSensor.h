#ifndef MYCELIUM_SENSOR_H
#define MYCELIUM_SENSOR_H

#include <Arduino.h>

class MyceliumSensor {
public:
    MyceliumSensor(uint8_t pinA, uint8_t pinB, float threshold = 0.05);

    void begin();
    bool detectSpike();
    float readPotential();
    void setThreshold(float newThreshold);

private:
    uint8_t _pinA;
    uint8_t _pinB;
    float _threshold;
    float _lastPotential;
};

#endif // MYCELIUM_SENSOR_H
