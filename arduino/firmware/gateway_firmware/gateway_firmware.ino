void setup() {
    Serial.begin(9600);
    Serial1.begin(9600);  // Assuming node connected to Serial1
    Serial.println("Gateway firmware started. Waiting for node data...");
}

void loop() {
    if (Serial1.available()) {
        String data = Serial1.readStringUntil('\n');
        Serial.print("Node data: ");
        Serial.println(data);
    }
}
