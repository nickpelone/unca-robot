
int spiderPinFR = 6;
int spiderPinFL = 7;
int spiderPinRR = 8;
int spiderPinRL = 9;  //input pins for spider legs


void setup()  {
  pinMode(spiderPinFR, INPUT);
  pinMode(spiderPinFL, INPUT);
  pinMode(spiderPinRR, INPUT);
  pinMode(spiderPinRL, INPUT);
  digitalWrite(spiderPinFR, HIGH);
  digitalWrite(spiderPinRR, HIGH);
  digitalWrite(spiderPinFL, HIGH);
  digitalWrite(spiderPinRL, HIGH); 
  delay(100);
  Serial.begin(9600);
}

void loop()  {
  detectEdge();
 delay(500);

}

void detectEdge()  {    //Tests "spider legs." If leg goes off edge, input is HIGH.  
                        //Otherwise, input is pulled down to ground.  
 if (digitalRead(spiderPinFR) == HIGH) backoffFR();
 else if (digitalRead(spiderPinFL) == HIGH) backoffFL();
 else if (digitalRead(spiderPinRR) == HIGH) backoffRR();
 else if (digitalRead(spiderPinRL) == HIGH) backoffRL();
 else Serial.println("All is well!");
}

void backoffFR() {
  //Front Right Leg just went over the edge
 Serial.println("Front Right leg!");
}

void backoffFL() {
  //Front Left Leg just went over the edge
 Serial.println("Front Left leg!");
}

void backoffRR() {
  //Rear Right Leg went over the edge
  //Optional code
 Serial.println("Rear Right leg!");
}

void backoffRL() {
  //Rear Left Leg went over the edge
  //Optional code
 Serial.println("Rear Left leg!");
}


