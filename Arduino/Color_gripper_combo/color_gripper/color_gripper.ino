#include <Servo.h>

Servo myservo1;  // small servo
             
Servo myservo2;   // large servo

 int inpin = 7;  // Press Sensor Pin
 int val = 0;    // Variable to store the read value
 int pos1 = 0;    // variable to store the small servo position
 int pos2 = 0;    // variable to store the big servo position

int S0 = 8;//pinB  don't use this pin
int S1 = 29;//pinA
int S2 = 32;//pinE
int S3 = 31;//pinF
int out = 30;//pinC
int LED = 27;//pinD
void setup()

{
  TCS3200setup();
  Serial.begin(9600);   //Change this number 
  Serial.print("\n\n\nready\n\n\n");
  delay(100);
  
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
if ((pos1>=40)&&(pos1<=46))
{color();
Serial.println("Rail block");}
else if ((pos1>=55)&&(pos1<=65))
{color();
Serial.println("Sea block");}
else if ((pos1>=80)&&(pos1<=89))
{color();
Serial.println("Air block");}
else Serial.println("Shit");

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



//I tweaked  the numbers a little bit for better performance on the end of the gripper arm.

//here it is....




/*
reibot.org 
 Demo program for TCS3200 from parallax and the parallax daughterboard 
 Call detectColor(out) where 'out' is pinC on the daughterboard. The detectColor will return a 0 if there is nothing color in front of sensor,
 1 if red is in front, 2 if blue is in front, or 3 if blue is in front. You can comment out all the serial.print. 
 If you're tight on pins, remove the taosMode(int) method and all references to it. Remove pins from the TCS3200setup too.
 If these wires are disconnected the TCS3200 will run on the highest frequency due to internal pullup resistors on S0 and S1 
 If you have multiple TCS3200 you may tie all the pins together except the outputs (pinC). Then just use detectColor(TCS3200's output) to 
 detect color on the selected TCS3200's output pin. 
 7/6/2011 works on arduino 0022
 Taos pins connect to arduino pins 8-13. There is no order and should work on any digital i/o
 */

//b.short--  I chaged pin 13 to 7 in the previous line due to a dead pin (no. 13) on the arduino

void color() {
  Serial.print(detectColor(out));
  //need to have statement here to detect again if no color is undetermined
  //define integer in void color scope.
  Serial.print("\n\n\n");
  delay(1000);
}
int detectColor(int taosOutPin){
  //isPresentTolerance will need to be something small if used in high light environment, large if used in dark environment.
  //the color detection will work either way, but the larger isPresentTolerance is, 
  //the closer the object will need to be in front of sensor
  double isPresentTolerance = 3;
  double isPresent = colorRead(taosOutPin,0,0)/colorRead(taosOutPin,0,1);//number gets large when something is in front of sensor. 
  //Serial.print("isPresent:");
  //Serial.println(isPresent,2);
  //Serial.print("isPresentTolerance currently set to:");
  //Serial.println(isPresentTolerance,2);
  if(isPresent < isPresentTolerance){
    Serial.println("nothing is in front of sensor");
    return 0;
  }
  double red,blue,green;
  double white = colorRead(taosOutPin,0,1);
  red = white/colorRead(taosOutPin,1,1)*255;
  blue = white/colorRead(taosOutPin,2,1)*255;
  green = white/colorRead(taosOutPin,3,1)*255;

  //Prints out RBG value right here.
 Serial.print("red ");
  Serial.println(red);
  Serial.print("blue ");
  Serial.println(blue);
  Serial.print("green ");
  Serial.println(green);

if(red > 175 && red < 205 && blue > 45 && blue < 62 && green > 30 && green < 45){
    Serial.println("Red Detected");
    return 1;
  }

  if(red > 175 && red < 205 && blue > 38 && blue < 53 && green > 35 && green < 50){
    Serial.println("Orange Detected");
    return 2;
  }

  if(red > 65 && red < 80 && blue > 80 && blue < 100 && green > 90 && green < 120){
    Serial.println("Green Detected");
    return 3;
  }

  if(red > 118 && red < 145 && blue > 65 && blue < 83 && green > 59 && green < 75){
    Serial.println("Brown Detected");
    return 4;
  }

  if(red > 20 && red < 45 && blue > 150 && blue < 170 && green > 70 && green < 90){
    Serial.println("Blue Detected");
    return 5;
  }

  if(red > 115 && red < 138 && blue > 40 && blue < 60 && green > 80 && green < 100){
    Serial.println("Yellow Detected");
    return 6;
  }
}
/*
This method will return the pulseIn reading of the selected color.
 Since frequency is proportional to light intensity of the selected color filter, 
 the smaller pulseIn is, the more light there is of the selected color filter.  
 It will turn on the sensor at the start taosMode(1), and it will power off the sensor at the end taosMode(0)
 color: 0=white, 1=red, 2=blue, 3=green
 if LEDstate is 0, LED will be off. 1 and the LED will be on.
 taosOutPin is the ouput of the TCS3200. If you have multiple TCS3200, all wires can be combined except the out pin
 */
double colorRead(int taosOutPin, int color, boolean LEDstate){
  //make sure that the pin is set to input
  pinMode(taosOutPin, INPUT);
  //turn on sensor with highest frequency settingtaosMode(1);
  //delay to let the sensor sit before taking a reading. Should be very small with this sensor
  int sensorDelay = 1;
  //set the pins to select the color  
  if(color == 0){//white
    digitalWrite(S3, LOW); //S3
    digitalWrite(S2, HIGH); //S2
    // Serial.print(" w");
  }
  else if(color == 1){//red
    digitalWrite(S3, LOW); //S3
    digitalWrite(S2, LOW); //S2
    // Serial.print(" r");
  }
  else if(color == 2){//blue
    digitalWrite(S3, HIGH); //S3
    digitalWrite(S2, LOW); //S2 
    // Serial.print(" b");
  }
  else if(color == 3){//green
    digitalWrite(S3, HIGH); //S3
    digitalWrite(S2, HIGH); //S2 
    // Serial.print(" g");
  }
  double readPulse;
  if(LEDstate == 0){
    digitalWrite(LED, LOW);
  }
  if(LEDstate == 1){
    digitalWrite(LED, HIGH);
  }
  delay(sensorDelay);
  readPulse = pulseIn(taosOutPin, LOW, 80000);
  //if the pulseIn times out, it returns 0 and that throws off numbers. just cap it at 80k if it happens
  if(readPulse < .1){
    readPulse = 80000;
  }
  //turn off color sensor and white LED to save power 
  taosMode(0);
  return readPulse;
}
//setting mode to zero will put taos into low power mode. taosMode(0);
void taosMode(int mode){
  if(mode == 0){
    //power OFF
    digitalWrite(LED, LOW);
    digitalWrite(S0, LOW); //S0
    digitalWrite(S1, LOW); //S1
    //  Serial.println("mOFFm");
  }
  else if(mode == 1){
    //this will put in 1:1
    digitalWrite(S0, HIGH); //S0
    digitalWrite(S1, HIGH); //S1
    // Serial.println("m1:1m");
  }
  else if(mode == 2){
    //this will put in 1:5
    digitalWrite(S0, HIGH); //S0
    digitalWrite(S1, LOW); //S1
    //Serial.println("m1:5m");
  }
  else if(mode == 3){
    //this will put in 1:50
    digitalWrite(S0, LOW); //S0
    digitalWrite(S1, HIGH); //S1 
    //Serial.println("m1:50m");
  }
  return;
}
void TCS3200setup(){
  //initialize pins
  pinMode(LED,OUTPUT); //LED pinD
  //color mode selection
  pinMode(S2,OUTPUT); //S2 pinE
  pinMode(S3,OUTPUT); //s3 pinF
  //color response pin (only actual input from taos)
  pinMode(out, INPUT); //out pinC
  //communication freq output divider
  pinMode(S0,OUTPUT); //S0 pinB
  pinMode(S1,OUTPUT); //S1 pinA 
  return;
}

