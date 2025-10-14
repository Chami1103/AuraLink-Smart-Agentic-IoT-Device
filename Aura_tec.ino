/*
 * AuraLink - Smart Agentic IoT Device
 * ESP32 Firmware for IoT Device Layer
 * Group ID: 62
 * 
 * Hardware Components:
 * - ESP32 Development Board
 * - DHT22 Temperature & Humidity Sensor
 * - OLED Display (128x64, I2C)
 * - RGB LED (Common Cathode)
 * 
 * Features:
 * - Reads temperature and humidity from DHT22
 * - Publishes sensor data via MQTT
 * - Subscribes to AI-generated quotes and email summaries
 * - Displays messages on OLED screen
 * - Shows urgency level using RGB LED
 */

#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ArduinoJson.h>

// ======================== CONFIGURATION ========================
// WiFi Credentials
const char* ssid = "YOUR_WIFI_SSID";           // Replace with your WiFi SSID
const char* password = "YOUR_WIFI_PASSWORD";   // Replace with your WiFi password

// MQTT Broker Configuration
const char* mqtt_server = "broker.hivemq.com"; // Public broker or use your own
const int mqtt_port = 1883;
const char* mqtt_client_id = "AuraLink_ESP32_001";

// MQTT Topics
const char* topic_sensor_data = "auralink/sensor/data";      // Publish sensor readings
const char* topic_ai_response = "auralink/ai/response";      // Subscribe to AI outputs

// DHT22 Sensor Configuration
#define DHTPIN 4           // DHT22 data pin connected to GPIO 4
#define DHTTYPE DHT22      // DHT22 sensor type
DHT dht(DHTPIN, DHTTYPE);

// OLED Display Configuration (I2C)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// RGB LED Pins (Common Cathode)
#define LED_RED 25
#define LED_GREEN 26
#define LED_BLUE 27

// Timing Configuration
const unsigned long SENSOR_READ_INTERVAL = 10000;  // Read sensor every 10 seconds
const unsigned long DISPLAY_UPDATE_INTERVAL = 5000; // Update display every 5 seconds

// ======================== GLOBAL VARIABLES ========================
WiFiClient espClient;
PubSubClient mqtt_client(espClient);

unsigned long lastSensorRead = 0;
unsigned long lastDisplayUpdate = 0;

// Sensor data
float temperature = 0.0;
float humidity = 0.0;

// AI-generated content
String currentQuote = "Initializing AuraLink...";
String emailSummary = "Waiting for data...";
String urgencyLevel = "normal";  // normal, advisory, critical

// Display state
int displayPage = 0;  // 0 = Quote, 1 = Email Summary

// ======================== SETUP FUNCTION ========================
void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n\n==================================");
  Serial.println("AuraLink IoT Device Starting...");
  Serial.println("==================================\n");
  
  // Initialize RGB LED pins
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  setLEDColor(0, 0, 255);  // Blue during initialization
  
  // Initialize DHT22 sensor
  Serial.println("Initializing DHT22 sensor...");
  dht.begin();
  delay(2000);  // DHT22 needs time to stabilize
  Serial.println("DHT22 sensor ready!");
  
  // Initialize OLED display
  Serial.println("Initializing OLED display...");
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("ERROR: OLED display initialization failed!");
    for (;;);  // Halt execution
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("AuraLink");
  display.println("Initializing...");
  display.display();
  Serial.println("OLED display ready!");
  
  // Connect to WiFi
  connectToWiFi();
  
  // Configure MQTT
  mqtt_client.setServer(mqtt_server, mqtt_port);
  mqtt_client.setCallback(mqttCallback);
  mqtt_client.setBufferSize(1024);  // Increase buffer for longer messages
  
  // Connect to MQTT broker
  connectToMQTT();
  
  // Set LED to green (ready state)
  setLEDColor(0, 255, 0);
  
  Serial.println("\n==================================");
  Serial.println("AuraLink Ready!");
  Serial.println("==================================\n");
  
  // Initial display
  updateDisplay();
}

// ======================== MAIN LOOP ========================
void loop() {
  // Maintain MQTT connection
  if (!mqtt_client.connected()) {
    connectToMQTT();
  }
  mqtt_client.loop();
  
  // Read sensor data periodically
  unsigned long currentMillis = millis();
  if (currentMillis - lastSensorRead >= SENSOR_READ_INTERVAL) {
    lastSensorRead = currentMillis;
    readAndPublishSensorData();
  }
  
  // Update display periodically
  if (currentMillis - lastDisplayUpdate >= DISPLAY_UPDATE_INTERVAL) {
    lastDisplayUpdate = currentMillis;
    displayPage = (displayPage + 1) % 2;  // Toggle between pages
    updateDisplay();
  }
  
  // Update LED based on urgency
  updateUrgencyLED();
}

// ======================== WiFi FUNCTIONS ========================
void connectToWiFi() {
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);
  
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Connecting WiFi...");
  display.display();
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 30) {
    delay(500);
    Serial.print(".");
    attempts++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi Connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    Serial.print("Signal Strength (RSSI): ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
    
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("WiFi Connected!");
    display.print("IP: ");
    display.println(WiFi.localIP());
    display.display();
    delay(2000);
  } else {
    Serial.println("\nWiFi Connection Failed!");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("WiFi Failed!");
    display.println("Check credentials");
    display.display();
    delay(5000);
    ESP.restart();  // Restart and try again
  }
}

// ======================== MQTT FUNCTIONS ========================
void connectToMQTT() {
  while (!mqtt_client.connected()) {
    Serial.print("Connecting to MQTT broker: ");
    Serial.println(mqtt_server);
    
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Connecting MQTT...");
    display.display();
    
    if (mqtt_client.connect(mqtt_client_id)) {
      Serial.println("MQTT Connected!");
      
      // Subscribe to AI response topic
      mqtt_client.subscribe(topic_ai_response);
      Serial.print("Subscribed to: ");
      Serial.println(topic_ai_response);
      
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("MQTT Connected!");
      display.display();
      delay(1000);
    } else {
      Serial.print("MQTT Connection Failed! State: ");
      Serial.println(mqtt_client.state());
      Serial.println("Retrying in 5 seconds...");
      
      display.clearDisplay();
      display.setCursor(0, 0);
      display.println("MQTT Failed!");
      display.println("Retrying...");
      display.display();
      
      delay(5000);
    }
  }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.println("\n--- MQTT Message Received ---");
  Serial.print("Topic: ");
  Serial.println(topic);
  
  // Convert payload to string
  String message = "";
  for (unsigned int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.print("Payload: ");
  Serial.println(message);
  
  // Parse JSON response from backend
  StaticJsonDocument<1024> doc;
  DeserializationError error = deserializeJson(doc, message);
  
  if (error) {
    Serial.print("JSON parsing failed: ");
    Serial.println(error.c_str());
    return;
  }
  
  // Extract data from JSON
  if (doc.containsKey("quote")) {
    currentQuote = doc["quote"].as<String>();
    Serial.print("Quote: ");
    Serial.println(currentQuote);
  }
  
  if (doc.containsKey("email_summary")) {
    emailSummary = doc["email_summary"].as<String>();
    Serial.print("Email Summary: ");
    Serial.println(emailSummary);
  }
  
  if (doc.containsKey("urgency")) {
    urgencyLevel = doc["urgency"].as<String>();
    Serial.print("Urgency: ");
    Serial.println(urgencyLevel);
  }
  
  Serial.println("-----------------------------\n");
  
  // Immediately update display with new content
  updateDisplay();
}

// ======================== SENSOR FUNCTIONS ========================
void readAndPublishSensorData() {
  Serial.println("\n--- Reading Sensor Data ---");
  
  // Read temperature and humidity
  float newTemp = dht.readTemperature();
  float newHumidity = dht.readHumidity();
  
  // Check if readings are valid
  if (isnan(newTemp) || isnan(newHumidity)) {
    Serial.println("ERROR: Failed to read from DHT sensor!");
    return;
  }
  
  temperature = newTemp;
  humidity = newHumidity;
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  // Create JSON payload
  StaticJsonDocument<256> doc;
  doc["device_id"] = mqtt_client_id;
  doc["temperature"] = temperature;
  doc["humidity"] = humidity;
  doc["timestamp"] = millis();
  
  // Serialize JSON to string
  String jsonString;
  serializeJson(doc, jsonString);
  
  // Publish to MQTT
  if (mqtt_client.publish(topic_sensor_data, jsonString.c_str())) {
    Serial.println("Sensor data published successfully!");
    Serial.print("Published to: ");
    Serial.println(topic_sensor_data);
  } else {
    Serial.println("ERROR: Failed to publish sensor data!");
  }
  
  Serial.println("---------------------------\n");
}

// ======================== DISPLAY FUNCTIONS ========================
void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  
  if (displayPage == 0) {
    // Display Quote Page
    display.println("=== AuraLink ===");
    display.println();
    display.println("Quote:");
    display.println();
    
    // Word wrap the quote
    display.setTextSize(1);
    printWrappedText(currentQuote, 0, 28, 128, 1);
    
  } else {
    // Display Email Summary Page
    display.println("=== Emails ===");
    display.println();
    display.println("Summary:");
    display.println();
    
    // Word wrap the email summary
    display.setTextSize(1);
    printWrappedText(emailSummary, 0, 28, 128, 1);
  }
  
  // Display sensor data at bottom
  display.setTextSize(1);
  display.setCursor(0, 56);
  display.print(temperature, 1);
  display.print("C ");
  display.print(humidity, 0);
  display.print("%");
  
  display.display();
}

void printWrappedText(String text, int x, int y, int maxWidth, int textSize) {
  display.setTextSize(textSize);
  int charWidth = 6 * textSize;  // Approximate character width
  int charsPerLine = maxWidth / charWidth;
  int cursorX = x;
  int cursorY = y;
  
  int wordStart = 0;
  for (int i = 0; i <= text.length(); i++) {
    if (i == text.length() || text[i] == ' ') {
      String word = text.substring(wordStart, i);
      int wordLength = word.length() * charWidth;
      
      if (cursorX + wordLength > maxWidth) {
        cursorX = x;
        cursorY += 8 * textSize;
      }
      
      if (cursorY + 8 * textSize > SCREEN_HEIGHT) {
        break;  // Stop if we exceed screen height
      }
      
      display.setCursor(cursorX, cursorY);
      display.print(word);
      cursorX += wordLength + charWidth;  // Add space
      wordStart = i + 1;
    }
  }
}

// ======================== LED FUNCTIONS ========================
void setLEDColor(int red, int green, int blue) {
  analogWrite(LED_RED, red);
  analogWrite(LED_GREEN, green);
  analogWrite(LED_BLUE, blue);
}

void updateUrgencyLED() {
  if (urgencyLevel == "critical") {
    // Red - Critical urgency
    setLEDColor(255, 0, 0);
  } else if (urgencyLevel == "advisory") {
    // Yellow - Advisory urgency
    setLEDColor(255, 255, 0);
  } else {
    // Green - Normal
    setLEDColor(0, 255, 0);
  }
}

// ======================== END OF CODE ========================
