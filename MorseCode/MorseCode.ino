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

void doMorse(char *x){
  int i=0;
  while(x[i]!='\0'){
    if(x[i]== '.'){
      dot();
    }
    else if(x[i]== '-'){
      dash();
    }
    else{
      Serial.println("ERROR, skipping.");
    }
    i++;
  }
}

void select(char x){
  switch (x) {
  case 'a':
    doMorse(".-");
    break;
  case 'b':
    doMorse("-...");
    break;
  case 'c':
    doMorse("-.-.");
    break;
  case 'd':
    doMorse("-..");
    break;
  case 'e':
    doMorse(".");
    break;
  case 'f':
    doMorse("..-.");
    break;
  case 'g':
    doMorse("--.");
    break;
  case 'h':
    doMorse("....");
    break;
  case 'i':
    doMorse("..");
    break;
  case 'j':
    doMorse(".---");
    break;
  case 'k':
    doMorse("-.-");
    break;
  case 'l':
    doMorse(".-..");
    break;
  case 'm':
    doMorse("--");
    break;
  case 'n':
    doMorse("-.");
    break;
  case 'o':
    doMorse("---");
    break;
  case 'p':
    doMorse(".--.");
    break;
  case 'q':
    doMorse("--.-");
    break;
  case 'r':
    doMorse(".-.");
    break;
  case 's':
    doMorse("...");
    break;
  case 't':
    doMorse("-");
    break;
  case 'u':
    doMorse("..-");
    break;
  case 'v':
    doMorse("...-");
    break;
  case 'w':
    doMorse(".--");
    break;
  case 'x':
    doMorse("-..-");
    break;
  case 'y':
    doMorse("-.--");
    break;
  case 'z':
    doMorse("--..");
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