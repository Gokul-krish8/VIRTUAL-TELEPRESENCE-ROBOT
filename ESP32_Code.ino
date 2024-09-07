#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "realme 12x 5G";      // Your Wi-Fi network name
const char* password = "u747zuks";   // Your Wi-Fi network password
const char* serverName = "http://192.168.234.59:5000/command"; // Raspberry Pi IP and Flask port

const int joystickXPin = 34; // Replace with your joystick X pin
const int joystickYPin = 35; // Replace with your joystick Y pin

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  
  // Try connecting to WiFi for 30 seconds
  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startTime < 30000) {
    delay(1000);
    Serial.println("Connecting...");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
    Serial.print("ESP32 IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Failed to connect to WiFi");
  }
}

void loop() {
  int xValue = analogRead(joystickXPin);
  int yValue = analogRead(joystickYPin);

  String command = "";

  if (yValue > 3000) { // Threshold for forward movement
    command = "forward";
    Serial.println("Forward");
  } else if (yValue < 1000) { // Threshold for backward movement
    command = "backward";
    Serial.println("Backward");
  } else if (xValue > 3000) { // Threshold for right movement
    command = "right";
    Serial.println("Right");
  } else if (xValue < 1000) { // Threshold for left movement
    command = "left";
    Serial.println("Left");
  } else {
    command = "stop";
    Serial.println("Stop");
  }

  if (command != "") {
    sendCommand(command);
  }

  delay(100);
}

void sendCommand(String command) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // Construct the full URL
    String url = String(serverName) + "?direction=" + command;
    Serial.println("Requesting URL: " + url);
    
    // Make the HTTP GET request
    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      Serial.print("Server response: ");
      Serial.println(response);
    } else {
      Serial.print("Error on HTTP request: ");
      Serial.println(httpResponseCode);
    }
    
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}
