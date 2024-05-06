#define BLYNK_TEMPLATE_ID "Template ID from blynk.cloud"
#define BLYNK_TEMPLATE_NAME "Template name from blynk.cloud"
#define BLYNK_PRINT Serial

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_ESP32_DEV_MODULE
//#define USE_ESP32C3_DEV_MODULE
//#define USE_ESP32S2_DEV_KIT
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7
//#define USE_TTGO_T_OI

#include "BlynkEdgent.h"
const int pinGPIO1 = 32; // GPIO pin connected to V0
const int pinGPIO2 = 33; // GPIO pin connected to V1

const int sensorPin = 34; //  V2
void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();

  pinMode(pinGPIO1, OUTPUT);
  pinMode(pinGPIO2, OUTPUT);
  pinMode(sensorPin,INPUT);
}

void loop() {
  BlynkEdgent.run();
  int newVal;
  int sensorValue = digitalRead(sensorPin);
  if( sensorValue == 1)
  {
    newVal = 0;
  }
  else 
  {
    newVal = 1;
  }
  Blynk.virtualWrite(V2, newVal);
  
}
BLYNK_WRITE(V0) {
  int value = param.asInt();
  digitalWrite(pinGPIO1, value);
  //Serial.print("GPIO 1 status: ");
  //Serial.println(value);
}

BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(pinGPIO2, value);
  //Serial.print("GPIO 2 status: ");
  //Serial.println(value);
}
