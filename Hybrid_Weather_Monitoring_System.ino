#include <DHT.h>
#define DHTPIN 2       // DHT11 Data Pin
#define IR_SENSOR 3    // IR Obstacle Sensor Pin
#define LED 4          // LED Indicator Pin
#define TRANSISTOR 5   // Transistor for device control
#define BUTTON 6       // Push Button Input
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    pinMode(IR_SENSOR, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(TRANSISTOR, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    
    Serial.begin(9600);
    dht.begin();
}

void loop() {
    float temp = dht.readTemperature();
    float humidity = dht.readHumidity();
    int irStatus = digitalRead(IR_SENSOR);
    int buttonStatus = digitalRead(BUTTON);

    Serial.print("Temp: "); Serial.print(temp); Serial.print("°C, ");
    Serial.print("Humidity: "); Serial.print(humidity); Serial.print("%, ");
    Serial.print("IR Sensor: "); Serial.println(irStatus);

    // If an obstacle is detected, turn on LED
    if (irStatus == LOW) {
        digitalWrite(LED, HIGH);
    } else {
        digitalWrite(LED, LOW);
    }

    // If button is pressed, activate transistor
    if (buttonStatus == LOW) {
        digitalWrite(TRANSISTOR, HIGH);
    } else {
        digitalWrite(TRANSISTOR, LOW);
    }

    delay(1000);
}
