#include <avr/wdt.h>

void setup()
{
  Serial.begin(57600); // Match the speed expected by the bootloader
}

void loop(){
  if (Serial.available() > 0){    
    char cmd = Serial.read();
    if (cmd == 'R'){ // When the host sends an 'R' enable the Watchdog timer

      wdt_enable(WDTO_15MS); // This is the smallest interval that can be set
    }
  }
}  
