#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(5,6);

void setup(){
  bluetoothSerial.begin(115200);
  Serial.begin(115200);
}

void loop(){
  bluetoothSerial.println("Hey");
  Serial.println("hey");
}

