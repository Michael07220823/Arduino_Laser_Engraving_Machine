/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */

// defines pins numbers
const int x_stepPin = 2;
const int x_dirPin = 5; 
const int y_stepPin = 3; 
const int y_dirPin = 6; 

void setup() {
  // Sets the two pins as Outputs
  pinMode(x_stepPin, OUTPUT); 
  pinMode(x_dirPin, OUTPUT);
  pinMode(y_stepPin, OUTPUT); 
  pinMode(y_dirPin, OUTPUT);
}

void loop() {
  digitalWrite(x_dirPin, HIGH); // Enables the motor to move in a particular direction
  digitalWrite(y_dirPin, HIGH); // Enables the motor to move in a particular direction
  
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 300; x > 0; x--) {
    digitalWrite(x_stepPin, HIGH); 
    digitalWrite(y_stepPin, HIGH); 
    delayMicroseconds(500); 
    digitalWrite(x_stepPin, LOW); 
    digitalWrite(y_stepPin, LOW); 
    delayMicroseconds(500); 
  }
  delay(1000); // One second delay

  digitalWrite(x_dirPin, LOW); //Changes the rotations direction
  digitalWrite(y_dirPin, LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 300; x++) {
    digitalWrite(x_stepPin, HIGH);
    digitalWrite(y_stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(x_stepPin, LOW);
    digitalWrite(y_stepPin, LOW);
    delayMicroseconds(500);
  }
  delay(1000);
}
