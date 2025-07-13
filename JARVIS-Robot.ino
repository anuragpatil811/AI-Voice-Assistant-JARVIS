#include <ESP8266WiFi.h>

const char* ssid = "Room009";  // Replace with your WiFi SSID
const char* password = "Sadguru009"; // Reace with your WiFi Password

WiFiServer server(80);

// Define motor control pins
#define ENA 4  // D2 (GPIO4)
#define A1 0   // D3 (GPIO0)
#define A2 2   // D4 (GPIO2)
#define ENB 14 // D5 (GPIO14)
#define B1 12  // D6 (GPIO12)
#define B2 13  // D7 (GPIO13)

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    server.begin();

    // Set motor pins as OUTPUT
    pinMode(ENA, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(B1, OUTPUT);
    pinMode(B2, OUTPUT);

    // Stop motors initially
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
}

void loop() {
    WiFiClient client = server.available();
    if (!client) {
        return;
    }

    String request = client.readStringUntil('\r');
    client.flush();

    Serial.println("Command Received: " + request);

    if (request.indexOf("FORWARD") != -1) {
        digitalWrite(A1, HIGH);
        digitalWrite(A2, LOW);
        digitalWrite(B1, HIGH);
        digitalWrite(B2, LOW);
    } else if (request.indexOf("BACKWARD") != -1) {
        digitalWrite(A1, LOW);
        digitalWrite(A2, HIGH);
        digitalWrite(B1, LOW);
        digitalWrite(B2, HIGH);
    } else if (request.indexOf("LEFT") != -1) {
        digitalWrite(A1, LOW);
        digitalWrite(A2, HIGH);
        digitalWrite(B1, HIGH);
        digitalWrite(B2, LOW);
    } else if (request.indexOf("RIGHT") != -1) {
        digitalWrite(A1, HIGH);
        digitalWrite(A2, LOW);
        digitalWrite(B1, LOW);
        digitalWrite(B2, HIGH);
    } else if (request.indexOf("STOP") != -1) {
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(B1, LOW);
        digitalWrite(B2, LOW);
    }

    // Send response to client
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<html><body><h1>Motor Command Received!</h1></body></html>");
    client.stop();
}
