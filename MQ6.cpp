#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk credentials
char auth[] = "";  // Replace with your Blynk Auth Token
char ssid[] = "No internet";         // Replace with your WiFi SSID
char pass[] = "1234567809";     // Replace with your WiFi Password

// Pin definitions
#define MQ6_PIN A0   // Analog pin for MQ-6 sensor
#define BUZZER_PIN D1 // Digital pin for buzzer

// Threshold gas level
const int gasThreshold = 400;  // Adjust based on your gas sensor's calibration

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);

  // Setup pin modes
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // Debug message
  Serial.println("System Initialized");
}

void loop() {
  // Run Blynk
  Blynk.run();

  // Read gas level from MQ-6 sensor
  int gasLevel = analogRead(MQ6_PIN);
  Serial.print("Gas Level: ");
  Serial.println(gasLevel);

  // Send gas level to Blynk
  Blynk.virtualWrite(V1, gasLevel);

  // Check for gas leak
  if (gasLevel > gasThreshold) {
    // Trigger buzzer
    digitalWrite(BUZZER_PIN, HIGH);

    // Send notification to Blynk
    Blynk.notify("Warning! Gas leak detected!");

    // Optional: Add a small delay to prevent spamming notifications
    delay(5000);
  } else {
    // Turn off buzzer if gas level is safe
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Add a small delay for stability
  delay(100);
}
