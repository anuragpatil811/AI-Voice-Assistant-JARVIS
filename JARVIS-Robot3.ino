#include <SoftwareSerial.h>

#define ENA 11
#define A1 10
#define A2 7
#define ENB 6
#define B1 8
#define B2 9

SoftwareSerial BT(2, 3); // RX, TX (Bluetooth module)

void setup() {
    BT.begin(9600);    // Start Bluetooth Serial at 9600
    pinMode(ENA, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(B1, OUTPUT);
    pinMode(B2, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
}

void loop() {
    if (BT.available()) {
        String command = BT.readStringUntil('\n');
        command.trim();

        if (command == "LED_ON") {
            digitalWrite(LED_BUILTIN, HIGH);
            BT.println("LED is ON");
        } else if (command == "LED_OFF") {
            digitalWrite(LED_BUILTIN, LOW);
            BT.println("LED is OFF");
        } else if (command == "MOTOR_FORWARD") {
            digitalWrite(A1, HIGH);
            digitalWrite(A2, LOW);
            digitalWrite(B1, HIGH);
            digitalWrite(B2, LOW);
            BT.println("Motors moving FORWARD");
        } else if (command == "MOTOR_BACKWARD") {
            digitalWrite(A1, LOW);
            digitalWrite(A2, HIGH);
            digitalWrite(B1, LOW);
            digitalWrite(B2, HIGH);
            BT.println("Motors moving BACKWARD");
        } else if (command == "MOTOR_LEFT") {
            digitalWrite(A1, LOW);
            digitalWrite(A2, HIGH);
            digitalWrite(B1, HIGH);
            digitalWrite(B2, LOW);
            BT.println("Motors turning LEFT");
        } else if (command == "MOTOR_RIGHT") {
            digitalWrite(A1, HIGH);
            digitalWrite(A2, LOW);
            digitalWrite(B1, LOW);
            digitalWrite(B2, HIGH);
            BT.println("Motors turning RIGHT");
        } else if (command == "MOTOR_STOP") {
            digitalWrite(A1, LOW);
            digitalWrite(A2, LOW);
            digitalWrite(B1, LOW);
            digitalWrite(B2, LOW);
            BT.println("Motors STOPPED");
        }
    }
}
