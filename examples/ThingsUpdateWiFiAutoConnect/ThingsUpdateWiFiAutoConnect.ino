/***************************************************
  Consentium IoT - Edge Board Library
  -------------------------------------------------
  This library is designed for use with Consentium IoT's 
  ESP8266, ESP32, and Raspberry Pi Pico W-compatible edge boards.

  Features:
  - Seamless WiFi connectivity
  - REST-based data transmission to the Consentium IoT Cloud

  Hardware Setup:
  - Connect an LED to GPIO 16 (ESP8266), GPIO 23 (ESP32), or GPIO 25 (Raspberry Pi Pico W) 
    to indicate REST events.

  Tutorials and Documentation:
  Visit us at: http://docs.consentiumiot.com/code-usage/wifi-auto-connect-api

  For Support:
  Email: official@consentiumiot.com

  MIT license - Redistribution must include this header.
 ****************************************************/

#include <ConsentiumThings.h>

// Create ConsentiumThings object
ConsentiumThingsDalton board;

// Define API keys
const char *SendApiKey = "YOUR_API_KEY";      // API key for sending data
const char *BoardApiKey = "YOUR_BOARD_API_KEY"; // API key for the board

// Define the interval for data sending
constexpr int interval = 7000;  // 7 seconds

void setup() {
  // Consentium IoT branding message
  Serial.println("Consentium IoT - Edge Board Library");
  Serial.println("------------------------------------");
  Serial.println("Initializing ConsentiumThings Board...");

  // Initialize WiFi with auto-connect feature
  board.initWiFiAutoConnect();

  // Initialize the board for sending data
  board.beginSend(SendApiKey, BoardApiKey);

  Serial.println("ConsentiumThings Board Initialized!");
  Serial.println("------------------------------------");
  Serial.println();
}

void loop() {
  // Prepare sample sensor data
  double data_0 = 1.0;  // Sample temperature data
  vector<double> sensorValues = {data_0};  // Sensor data vector
  const char* sensorInfo[] = {"Temperature"}; // Sensor info array

  board.sendData(sensorValues, sensorInfo, LOW_PRE);  // Send over REST with low precision

  // Wait before sending the next batch of data
  delay(interval);
}
