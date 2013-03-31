#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(5,6);

void setup(){
  bluetoothSerial.begin(115200);
  Serial.begin(115200);
  bluetoothSerial.println("$$$");
  bluetoothSerial.write("F,1");
}

void loop(){
  bluetoothSerial.println("hello world");
  Serial.println("hello this is serial");
  delay(1000);
}

