const int buzzer = 7;  // Buzzer connected to pin 7
bool alarmOn = false;   // Flag to track alarm state

void setup() {
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();
        
        if (command == "ALARM_ON") {
            alarmOn = true;
        } 
        else if (command == "ALARM_OFF") {
            alarmOn = false;
            noTone(buzzer); // Stop beeping
        }
    }

    if (alarmOn) {
        tone(buzzer, 1000); // Beep at 1000 Hz
        delay(500);
        noTone(buzzer);
        delay(500);
    }
}
