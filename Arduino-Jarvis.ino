#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT); // Example: LED on pin 13
}

void loop() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();

        if (command == "LIGHT_ON") {
            digitalWrite(LED_BUILTIN, HIGH);
        } else if (command == "LIGHT_OFF") {
            digitalWrite(LED_BUILTIN, LOW);
        }
    }
}
