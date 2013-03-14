/**Bluetooth Transmitter for the UNCA 2013 IEEE SouthEastCon robot
  @author Nick Pelone<npelone@unca.edu>
  **/

void setup(){
  /**
  Baud rates: These need to be different based on what kind of device we are sending our data to.
  Computers seem to work well at 115200.
  "It is written" that you must use 9600 for Android; this remains to be tested **/
  
  //set the baud rate to a computer-compatible value
  Serial1.begin(115200);
}
void loop(){
  Serial1.println("Hello, world!");
 
  delay(1000);
  Serial1.println("butt");
}
