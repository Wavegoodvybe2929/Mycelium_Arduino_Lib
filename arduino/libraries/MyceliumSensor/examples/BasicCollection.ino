#include <MyceliumSensor.h>

MyceliumSensor sensor(A0, A1, 0.05);  // Pins A0 and A1, threshold 0.05V

void setup() {
    Serial.begin(9600);
    sensor.begin();
    Serial.println("Mycelium spike monitoring started...");
}

void loop() {
    if (sensor.detectSpike()) {
        float pot = sensor.readPotential();
        Serial.print("Spike detected! Potential: ");
        Serial.print(pot, 4);
        Serial.println(" V");
    }
    delay(1000);  // Sample every second
}
