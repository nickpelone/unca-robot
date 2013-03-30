int irPin1 = 50;  //Front IR pin
int irPin2 = 51;  //Rear IR pin

void setup() {
  Serial.begin(9600);
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);
  digitalWrite(irPin1, HIGH);
  digitalWrite(irPin2, HIGH);
}

void loop() {
  checkIRs();
}

void checkIRs() {
  //Checks the IRs at the pickup area to see if the bot is in place to pick up 
  //a block
    if ((digitalRead(irPin1) != 1) && (digitalRead(irPin2) != 1))   {
    slightBackup();
  }
  else if (digitalRead(irPin1) != 1) {
    slightForward();
  }
  else if (digitalRead(irPin2) != 1) {
    slightBackup();
  }
  else Serial.println("no move needed.");  
  delay(1000);
}

void slightBackup()  {
 //backup robot slightly 
 Serial.println("Backing up slightly");
  
}

void slightForward()  {
  //go forward slightly
  Serial.println("Moving Forward slightly");
  
}

