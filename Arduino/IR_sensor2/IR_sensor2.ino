int irPin1 = 50;  //Front IR pin
int irPin2 = 51;  //Rear IR pin
boolean irStatus = false; //Are we in position via IR? true means stop

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
  }else{
  michaelRobot.debugPrintLn("no move needed.");
  irstatus = true;
  delay(1000);
}

void slightBackup()  {
 //backup robot slightly 
 michaelRobot.debugPrintLn("Backing up slightly");
 while(irStatus == false){
   //we are not in position
   
   //move forward super slow
   michaelRobot.setSpeed(0,false, int(60*0.96));
   michaelRobot.setSpeed(0,false,60)
   
   delay(1500);
   checkIRS();
   
  
  }
}

void slightForward()  {
  //go forward slightly
  michaelRobot.debugPrintLn("Moving Forward slightly");
    while(irStatus == false){
      michaelRobot.setSpeed(0,true, int(60*0.96));
      michaelRobot.setSpeed(1,true,60);
      delay(1500);
      checkIRS();
    }
}

