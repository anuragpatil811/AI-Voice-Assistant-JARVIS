#include <DHT.h>

#define DHTPIN 2      // D4 pin on NodeMCU
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (!isnan(humidity) && !isnan(temperature)) {
    Serial.print(temperature);
    Serial.print(",");
    Serial.println(humidity);
  } else {
    Serial.println("Error");
  }
  delay(2000); // every 2 seconds
}
