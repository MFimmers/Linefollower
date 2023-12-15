//Define the variable that contains the led
#define ledPin 7
int state = 0;
void setup() {
  //Setting the pin mode and initial LOW 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, 0);
  Serial1.begin(9600); // Default communication rate
}
void loop() {
  // Checks if the data is coming from the serial port
  if(Serial1.available() > 0){ 
    state = Serial1.read(); // Read the data from the serial port
 }
 //Deciding functions for LED on and off 
 if (state == '0') {
  digitalWrite(ledPin, 0); // Turn LED OFF
  // Send back, to the phone, the String "LED: ON"
  Serial1.println("LED: OFF"); 
  state = 0;
 }
 else if (state == '1') {
  digitalWrite(ledPin, 1);
  Serial1.println("LED: ON");;
  state = 0;
 } 
}
