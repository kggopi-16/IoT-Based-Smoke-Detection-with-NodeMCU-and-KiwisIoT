/*
* IoT Smoke Detection with KiwisIoT
* Platform: KiwisIoT
* Board:    NodeMCU 1.0 (ESP-12E Module)
* Sensor:   MQ-2 on A0
* Outputs:  Buzzer on D5, Red LED on D6
* License:  MIT
*
* Channel 1 -> Smoke level (0-100%)   [Gauge]
* Channel 2 -> Alert status (0/1)     [Status / LED]
*/
#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
const char* ssid  = "YOUR_WIFI_NAME";
const char* pass  = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
KiwisIoT kiwisiot(ssid, pass, topic);
#define MQ2_PIN     A0
#define BUZZER_PIN  D5
#define LED_PIN     D6
const int SMOKE_DANGER_THRESHOLD = 450;
const int SMOKE_SAFE_THRESHOLD   = 350;
int  smokeRaw     = 0;
int  smokePercent = 0;
bool alertActive  = false;
void setup() {
Serial.begin(115200);
pinMode(BUZZER_PIN, OUTPUT);
pinMode(LED_PIN, OUTPUT);
digitalWrite(BUZZER_PIN, LOW);
digitalWrite(LED_PIN, LOW);
Serial.println("IoT Smoke Detection - KiwisIoT");
Serial.println("MQ-2 warming up (30 seconds)...");
for (int i = 30; i > 0; i--) {
Serial.print(".");
delay(1000);
}
Serial.println("\nSensor ready. Connecting to Wi-Fi...");
kiwisiot.begin();
Serial.println("KiwisIoT connected. Monitoring smoke...");
}
void loop() {
kiwisiot.run();
smokeRaw = analogRead(MQ2_PIN);
smokePercent = map(smokeRaw, 0, 1023, 0, 100);
smokePercent = constrain(smokePercent, 0, 100);
if (smokeRaw > SMOKE_DANGER_THRESHOLD && !alertActive) {
alertActive = true;
digitalWrite(LED_PIN, HIGH);
tone(BUZZER_PIN, 2000);
Serial.println(">>> SMOKE DETECTED! Buzzer ON <<<");
}
else if (smokeRaw < SMOKE_SAFE_THRESHOLD && alertActive) {
alertActive = false;
digitalWrite(LED_PIN, LOW);
noTone(BUZZER_PIN);
Serial.println("--- Air clear. Buzzer OFF ---");
}
kiwisiot.send("1", String(smokePercent));
kiwisiot.send("2", alertActive ? "1" : "0");
Serial.print("Smoke: ");
Serial.print(smokeRaw);
Serial.print(" (");
Serial.print(smokePercent);
Serial.print("%) | Alert: ");
Serial.println(alertActive ? "SMOKE DETECTED" : "SAFE");
delay(2000);
}
