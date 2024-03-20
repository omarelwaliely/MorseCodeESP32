//testing examples

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

const int ledPin = 2;

BluetoothSerial SerialBT;


void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_OMAR");
  Serial.println("Device Connected.");
  pinMode (ledPin, OUTPUT);
}
void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  else if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  else{
    digitalWrite (ledPin, HIGH);
    delay(500);
    digitalWrite (ledPin, LOW);
    delay(500);
  }
}