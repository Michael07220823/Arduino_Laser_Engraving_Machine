
// Defines pins numbers
const int x_stepPin = 2;
const int x_dirPin = 3; 
const int y_stepPin = 4; 
const int y_dirPin = 5; 
const int laserPin = 6;
const int bzPin = 7;
const int ledPin = 8;

// Defines xy axis num.
const int x_step = 20;
const int y_step = 50;
int x_axis_count = 0;
int y_axis_count = 0;

//  Laser parameters
const int laserPower = 10; 
const int laserPoweroff = 0; 

// String array
String textBox="";


void setup() {
    Serial.begin(9600);
    Serial.println("Init Serial...");
    Serial.print("Please input number from 0 to 9:");
    
    // Settings pin status.
    pinMode(x_stepPin, OUTPUT); 
    pinMode(x_dirPin, OUTPUT);
    pinMode(y_stepPin, OUTPUT); 
    pinMode(y_dirPin, OUTPUT);
    
    pinMode(laserPin, OUTPUT);
    pinMode(bzPin, OUTPUT); 
    pinMode(ledPin, OUTPUT);

    // Testing step motor.
    digitalWrite(x_dirPin, HIGH); // Enables the motor to move in a particular direction
    digitalWrite(y_dirPin, LOW); // Enables the motor to move in a particular direction
    // Makes 300 pulses for making one full cycle rotation
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
    digitalWrite(y_dirPin, HIGH); //Changes the rotations direction
    // Makes 300 pulses for making two full cycle rotation
    for(int x = 0; x < 300; x++) {
        digitalWrite(x_stepPin, HIGH);
        digitalWrite(y_stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(x_stepPin, LOW);
        digitalWrite(y_stepPin, LOW);
        delayMicroseconds(500);
    }

    // Testing laser、bz、led.
    analogWrite(laserPin, laserPower);
    digitalWrite(bzPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(500);
    analogWrite(laserPin, laserPoweroff);
    digitalWrite(bzPin, LOW);
    digitalWrite(ledPin, LOW);
}

void loop() {
    if (Serial.available() > 0) {
        digitalWrite(ledPin, HIGH);
        
        textBox = Serial.readString();
        Serial.println(textBox);
  
        for(int i=0; i<textBox.length(); i++){
            switch(textBox[i]){
                case 'b':
                    goBack();
                    break;
                case '0':
                    Serial.print(textBox[i]);
                    zero();
                    break;
                case '1':
                    Serial.print(textBox[i]);
                    one();
                    break;
                case '2':
                    Serial.print(textBox[i]);
                    two();
                    break;
                case '3':
                    Serial.print(textBox[i]);
                    three();
                    break;
                case '4':
                    Serial.print(textBox[i]);
                    four();
                    break;
                case '5':
                    Serial.print(textBox[i]);
                    five();
                    break;
                case '6':
                    Serial.print(textBox[i]);
                    six();
                    break;
                case '7':
                    Serial.print(textBox[i]);
                    seven();
                    break;
                case '8':
                    Serial.print(textBox[i]);
                    eight();
                    break;
                case '9':
                    Serial.print(textBox[i]);
                    nine();
                    break;
            }
            delay(500);
            // x axis reset.
            x_axis_count=0;
        }
    // Machine status.
    digitalWrite(ledPin, LOW);
    digitalWrite(bzPin, HIGH);
    delay(500);
    digitalWrite(bzPin, LOW);

    // y axis reset.
    return_y(y_axis_count);
    y_axis_count=0;
    }
}

void zero()
{
    line();
    line();
    line();
    line();
    line();
    return_x(x_axis_count);
    nextline();
}

void one()
{
    point();
    line();
    line();
    line();
    line();
    return_x(x_axis_count);
    nextline();
}

void two()
{
    point();
    point();
    line();
    line();
    line();
    return_x(x_axis_count);
    nextline();
}

void three()
{
    point();
    point();
    point();
    line();
    line();
    return_x(x_axis_count);
    nextline();
}

void four()
{
    point();
    point();
    point();
    point();
    line();
    return_x(x_axis_count);
    nextline();
}

void five()
{
    point();
    point();
    point();
    point();
    point();
    return_x(x_axis_count);
    nextline();
}

void six()
{
    line();
    point();
    point();
    point();
    point();
    return_x(x_axis_count);
    nextline();
}

void seven()
{
    line();
    line();
    point();
    point();
    point();
    return_x(x_axis_count);
    nextline();
}

void eight()
{
    line();
    line();
    line();
    point();
    point();
    return_x(x_axis_count);
    nextline();
}

void nine()
{
    line();
    line();
    line();
    line();
    point();
    return_x(x_axis_count);
    nextline();
}

int point()
{
    analogWrite(laserPin, laserPower);
    delay(1000);
    analogWrite(laserPin, laserPoweroff);
    delay(800);

    digitalWrite(x_dirPin, HIGH);
    for(int x = x_step; x > 0; x--)
    {
        digitalWrite(x_stepPin, HIGH); 
        delayMicroseconds(500); 
        digitalWrite(x_stepPin, LOW);  
        delayMicroseconds(500);
    }
    delay(500);
    x_axis_count++;
}


int line()
{
    analogWrite(laserPin, laserPower);

    digitalWrite(x_dirPin, HIGH);
    // 邊雷射邊移動
    for(int x = x_step*2; x > 0; x--) {
        digitalWrite(x_stepPin, HIGH); 
        delay(10); 
        digitalWrite(x_stepPin, LOW);  
        delay(10);
    }
      analogWrite(laserPin, laserPoweroff);
      delay(1000);
    
    // 空一格 
    for(int x = x_step; x > 0; x--) 
     {
        digitalWrite(x_stepPin, HIGH); 
        delayMicroseconds(500); 
        digitalWrite(x_stepPin, LOW);  
        delayMicroseconds(500);
     }
     delay(500);
    x_axis_count += 3;
}


void return_x(int count)
{
    digitalWrite(x_dirPin, LOW);
    for(int x = 0; x < x_step*count; x++) 
    {
        digitalWrite(x_stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(x_stepPin, LOW);
        delayMicroseconds(500);
    }
}


void return_y(int count)
{
    digitalWrite(y_dirPin, HIGH);
    for(int y = 0; y < y_step*count; y++) 
    {
        digitalWrite(y_stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(y_stepPin, LOW);
        delayMicroseconds(500);
    }
}


void nextline()
{
    digitalWrite(y_dirPin, LOW);
    for(int y = y_step; y > 0; y--) 
    {
        digitalWrite(y_stepPin, HIGH); 
        delay(10); 
        digitalWrite(y_stepPin, LOW);  
        delay(10);
    }
    y_axis_count++;
}

void goBack(){
    digitalWrite(x_dirPin, HIGH); // Enables the motor to move in a particular direction
    digitalWrite(y_dirPin, LOW); // Enables the motor to move in a particular direction
    // Makes 300 pulses for making one full cycle rotation
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
    digitalWrite(y_dirPin, HIGH); //Changes the rotations direction
    // Makes 300 pulses for making two full cycle rotation
    for(int x = 0; x < 300; x++) {
        digitalWrite(x_stepPin, HIGH);
        digitalWrite(y_stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(x_stepPin, LOW);
        digitalWrite(y_stepPin, LOW);
        delayMicroseconds(500);
    }
}