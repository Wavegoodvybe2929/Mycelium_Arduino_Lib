#include <MyceliumSensor.h>

MyceliumSensor sensor(A0, A1, 0.05);  // Differential pins and threshold

void setup() {
    Serial.begin(9600);
    sensor.begin();
    Serial.println("Node firmware started. Listening for spikes...");
}

void loop() {
    if (sensor.detectSpike()) {
        float pot = sensor.readPotential();
        Serial.print("S:");
        Serial.println(pot, 4);
    } else {
        Serial.println("S:0.0000");
    }
    delay(1000);  // 1 Hz sample rate
}
