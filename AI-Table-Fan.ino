#define IN1 8      // L293D IN1
#define IN2 7      // L293D IN2
#define ENA 9      // L293D EN1 (Enable 1,2)

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);   // Motor initially OFF
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    if (command == 'M') {
      digitalWrite(IN1, HIGH);    // Set direction
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 200);      // Start motor (speed: 0–255)
    } 
    else if (command == 'F') {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 0);        // Stop motor
    }
  }
}
