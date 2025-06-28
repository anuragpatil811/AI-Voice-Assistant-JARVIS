
#define ENA D1  
#define A1 D2   
#define A2 D3   
#define ENB D4  
#define B1 D5   
#define B2 D6 

void setup() {
    Serial.begin(9600);  // Start Serial Communication
    pinMode(ENA, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    
    pinMode(ENB, OUTPUT);
    pinMode(B1, OUTPUT);
    pinMode(B2, OUTPUT);

    // Set initial state
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
    analogWrite(ENA, 255); // Full speed
    analogWrite(ENB, 255); // Full speed
}

void loop() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');  // Read serial input
        command.trim();  

        if (command == "LED_ON") {
            digitalWrite(7, HIGH);
            Serial.println("LED is ON");
        } else if (command == "LED_OFF") {
            digitalWrite(7, LOW);
            Serial.println("LED is OFF");
        } else if (command == "MOTOR_FORWARD") {
            digitalWrite(A1, HIGH);
            digitalWrite(A2, LOW);
            digitalWrite(B1, HIGH);
            digitalWrite(B2, LOW);
            Serial.println("Motors moving FORWARD");
        } else if (command == "MOTOR_BACKWARD") {
            digitalWrite(A1, LOW);
            digitalWrite(A2, HIGH);
            digitalWrite(B1, LOW);
            digitalWrite(B2, HIGH);
            Serial.println("Motors moving BACKWARD");
        } 
           else if (command == "MOTOR_LEFT") 
        {
            digitalWrite(A1, LOW);
            digitalWrite(A2, HIGH);
            digitalWrite(B1, HIGH);
            digitalWrite(B2, LOW);
            Serial.println("Motors moving LEFT");
           // analogWrite(ENA, 150);
           // analogWrite(ENB, 150);
        } 
        else if (command == "MOTOR_RIGHT") 
        {
            digitalWrite(A1, HIGH);
            digitalWrite(A2, LOW);
            digitalWrite(B1, LOW);
            digitalWrite(B2, HIGH);
            Serial.println("Motors moving RIGHT");
            //analogWrite(ENA, 150);
            //analogWrite(ENB, 150);
        } 
        else if (command == "MOTOR_STOP") {
            digitalWrite(A1, LOW);
            digitalWrite(A2, LOW);
            digitalWrite(B1, LOW);
            digitalWrite(B2, LOW);
            Serial.println("Motors STOPPED");
        }
    }
}  
