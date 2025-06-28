#include <ESP8266WiFi.h>

const char* ssid = "Your_WiFi_SSID";  // Replace with your WiFi SSID
const char* password = "Your_WiFi_Password";  // Replace with your WiFi Password

WiFiServer server(80);

// Motor Driver Pins
#define ENA D1  
#define A1 D2   
#define A2 D3   
#define ENB D4  
#define B1 D5   
#define B2 D6   

void setup() {
    Serial.begin(9600);
    
    pinMode(ENA, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    
    pinMode(ENB, OUTPUT);
    pinMode(B1, OUTPUT);
    pinMode(B2, OUTPUT);

    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);

    analogWrite(ENA, 255);  // Full speed
    analogWrite(ENB, 255);  // Full speed

    // Connect to WiFi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    
    Serial.println("Connected to WiFi!");
    Serial.println(WiFi.localIP());  
    server.begin();
}

void loop() {
    WiFiClient client = server.available();
    if (!client) return;

    Serial.println("Client connected!");
    while (!client.available()) delay(1);

    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    if (request.indexOf("/forward") != -1) {
        digitalWrite(A1, HIGH);
        digitalWrite(A2, LOW);
        digitalWrite(B1, HIGH);
        digitalWrite(B2, LOW);
    } else if (request.indexOf("/backward") != -1) {
        digitalWrite(A1, LOW);
        digitalWrite(A2, HIGH);
        digitalWrite(B1, LOW);
        digitalWrite(B2, HIGH);
    } else if (request.indexOf("/left") != -1) {
        digitalWrite(A1, LOW);
        digitalWrite(A2, HIGH);
        digitalWrite(B1, HIGH);
        digitalWrite(B2, LOW);
    } else if (request.indexOf("/right") != -1) {
        digitalWrite(A1, HIGH);
        digitalWrite(A2, LOW);
        digitalWrite(B1, LOW);
        digitalWrite(B2, HIGH);
    } else if (request.indexOf("/stop") != -1) {
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
        digitalWrite(B1, LOW);
        digitalWrite(B2, LOW);
    }

    // Send Response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<!DOCTYPE html><html><body>");
    client.println("<h1>WiFi Robot Control</h1>");
    client.println("<p><a href='/forward'>Move Forward</a></p>");
    client.println("<p><a href='/backward'>Move Backward</a></p>");
    client.println("<p><a href='/left'>Turn Left</a></p>");
    client.println("<p><a href='/right'>Turn Right</a></p>");
    client.println("<p><a href='/stop'>Stop</a></p>");
    client.println("</body></html>");
    
    client.stop();
    Serial.println("Client disconnected.");
}
