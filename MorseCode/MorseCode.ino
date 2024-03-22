//testing examples

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

const int ledPin = 2;

BluetoothSerial SerialBT;

void dot(){
  digitalWrite (ledPin, HIGH);
  delay(300);
  digitalWrite (ledPin, LOW);
  delay(300);
}

void dash(){
  digitalWrite (ledPin, HIGH);
  delay(1000);
  digitalWrite (ledPin, LOW);
  delay(300);
}

void select(char x){
  switch (x) {
  case 'a':
    dot();
    dash();
    break;
  case 'b':
    dash();
    dot();
    dot();
    break;
  case 'c':
    dash();
    dot();
    dash();
    dot();
    break;
  case 'd':
    dash();
    dot();
    break;
  case 'e':
    dot();
    break;
  case 'f':
    dot();
    dot();
    dash();
    dot();
    break;
  case 'g':
    dash();
    dash();
    dot();
    break;
  case 'h':
    dot();
    dot();
    dot();
    dot();
    break;
  case 'i':
    dot();
    dot();
    break;
  case 'j':
    dot();
    dash();
    dash();
    dash();
    break;
  case 'k':
    dash();
    dot();
    dash();
    dot();
    break;
  case 'l':
    dot();
    dash();
    dot();
    dot();
    break;
  case 'm':
    dash();
    dash();
    break;
  case 'n':
    dash();
    dot();
    break;
  case 'o':
    dash();
    dash();
    dash();
    break;
  case 'p':
    dot();
    dash();
    dash();
    dot();
    break;
  case 'q':
    dash();
    dash();
    dot();
    dash();
    break;
  case 'r':
    dot();
    dash();
    dot();
    break;
  case 's':
    dot();
    dot();
    dot();
    break;
  case 't':
    dash();
    break;
  case 'u':
    dot();
    dot();
    dash();
    break;
  case 'v':
    dot();
    dot();
    dot();
    dash();
    break;
  case 'w':
    dot();
    dash();
    dash();
    break;
  case 'x':
    dash();
    dot();
    dot();
    dash();
    break;
  case 'y':
    dash();
    dot();
    dash();
    dash();
    break;
  case 'z':
    dash();
    dash();
    dot();
    dot();
    break;
  default:
    digitalWrite (ledPin, LOW);
    delay(1500);
    break;
  }
}

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_OMAR");
  Serial.println("Device Connected.");
  pinMode (ledPin, OUTPUT);
}
void loop() {
  if (SerialBT.available()) {
    select(tolower(SerialBT.read()));
  }
}