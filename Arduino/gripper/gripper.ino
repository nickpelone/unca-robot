#include <Servo.h>

Servo myservo1;  // small servo
             
Servo myservo2;   // large servo

 int inpin = 7;  // Press Sensor Pin
 int val = 0;    // Variable to store the read value
 int pos1 = 0;    // variable to store the small servo position
 int pos2 = 0;    // variable to store the big servo position

void setup()
{
  Serial.begin(9600);
  pinMode(inpin, INPUT); // Pin 7 is connected to press sensor
  // Press sensor attaches to pin 7 and to ground
  myservo1.attach(9);  // attaches the small servo on pin 9
  myservo2.attach(8);  // attaches the large servo on digital pin 8
  digitalWrite(inpin, HIGH);
}


void loop()
{
  int i;
  //  Once bot is in position to pick up block
  
   lowerarm();           // Lower the arm to the block
 
   closesmallservo();      //  Close gripper
   delay(500);
 
   liftarm();             // Lift the gripper arm

   delay(1000);          // Hold block while traveling around
  
   lowerarm();            // Lower the gripper arm
 
   opensmallservo();      // Release block
  
    delay(500);
  
  liftarm();            // Raise the gripper arm out of the way
  
  delay(1000);           // waits one second for other servo to lift arm            
}

void opensmallservo()
{
//  Serial.print("Opening Gripper. Final Position: ");
//  myservo2.write(pos2);
   for(pos1 = 90; pos1 > 20; pos1--)  // small servo opens 
 {                                  // in steps of 1 degree
  myservo1.write(pos1);              // tell servo to go to position in variable 'pos'
   delay(15);                       // waits 15ms for the servo to reach the position
  }
//   myservo2.write(pos2);
//   delay(15);
//  Serial.println(pos1);
}

void closesmallservo()
{
//  Serial.print("Closing Gripper. ");
//  Serial.println();
    // Pull Press Sensor input up
   pos1 = 30;           // inititalize small servo position
   while(pos1 < 90)
   {                
      myservo1.write(pos1);          // tell servo to go to position in variable 'pos'
      delay(15);                     // waits 15ms for the servo to reach the position
      if (digitalRead(inpin)==LOW) {
     //  Serial.print("Final closed Position: ");  // Monitor the last position of the servo
     //  Serial.println(pos1);
       break;
      }
      pos1++;
   }
 //   Serial.print("Final Position: ");  // Monitor the last position of the servo
 // Serial.println(pos1);       //  Add language to show size of block based on pos1 value
if ((pos1>=40)&&(pos1<=46)) Serial.println("Rail block");
else if ((pos1>=55)&&(pos1<=65)) Serial.println("Sea block");
else if ((pos1>=80)&&(pos1<=89)) Serial.println("Air block");
else Serial.println("ERROR");

}

void liftarm()
{
//  Serial.print("Lifting Arm");
//  Serial.println();
   for(pos2 = 7; pos2 < 100; pos2 += 1)  // big servo lifts arm
  {                                  // in steps of 1 degree
    myservo2.write(pos2);              // tell big servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void lowerarm()
{
//  Serial.print("Lowering Arm");
//  Serial.println();
  for(pos2 = 100; pos2>=7; pos2-=1)     // big servo lowers arm
  {
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

