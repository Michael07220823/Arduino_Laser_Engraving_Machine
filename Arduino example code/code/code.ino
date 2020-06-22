
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
const int y_step = 20;
int x_axis_count = 0;
int y_axis_count = 0;


// String array
char box[10];

void setup() {
    Serial.begin(9600);

    pinMode(x_stepPin, OUTPUT); 
    pinMode(x_dirPin, OUTPUT);
    pinMode(y_stepPin, OUTPUT); 
    pinMode(y_dirPin, OUTPUT);
    
    pinMode(laserPin, OUTPUT);
    pinMode(bzPin, OUTPUT); 
    pinMode(ledPin, OUTPUT);

    // Testing hardwares.
    digitalWrite(x_dirPin, HIGH);
    digitalWrite(y_dirPin, HIGH);
    digitalWrite(x_stepPin, HIGH);
    digitalWrite(y_stepPin, HIGH);
    delay(500);
    digitalWrite(y_stepPin, LOW);
    digitalWrite(x_stepPin, LOW);

    digitalWrite(laserPin, HIGH);
    digitalWrite(bzPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(laserPin, LOW);
    digitalWrite(bzPin, LOW);
    digitalWrite(ledPin, LOW);
}

void loop() {
    if (Serial.avaiable() > 0){
        char
    }
}


void one()
{
    digitalWrite(ledPin, HIGH);
    x_axis_count = point(x_axis_count);
    x_axis_count = line(x_axis_count);
    x_axis_count = line(x_axis_count);
    x_axis_count = line(x_axis_count);
    x_axis_count = line(x_axis_count);
    return_x(x_axis_count);
    nextline();
    digitalWrite(ledPin, HIGH);
}


int point(int count)
{
    digitalWrite(laserPin, HIGH);
    delay(2000);
    digitalWrite(laserPin, LOW);

    digitalWrite(x_dirPin, HIGH);
    for(int x = x_step; x > 0; x--)
    {
        digitalWrite(x_stepPin, HIGH); 
        delayMicroseconds(500); 
        digitalWrite(x_stepPin, LOW);  
        delayMicroseconds(500);
    }
    count++;
    return count ;
}


int line(int count)
{
    digitalWrite(laserPin, HIGH);
    delay(2000);

    digitalWrite(x_dirPin, HIGH);
    for(int x = 40; x > 0; x--) {
        digitalWrite(x_stepPin, HIGH); 
        delayMicroseconds(500); 
        digitalWrite(x_stepPin, LOW);  
        delayMicroseconds(500);
    }
      digitalWrite(laserPin, LOW);
    for(int x = x_step; x > 0; x--) 
     {
        digitalWrite(x_stepPin, HIGH); 
        delayMicroseconds(500); 
        digitalWrite(x_stepPin, LOW);  
        delayMicroseconds(500);
     }
    count = count + 3;
    return count;
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
    digitalWrite(y_dirPin, LOW);
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
    for(int y = y_step; y > 0; y--) 
    {
        digitalWrite(y_stepPin, HIGH); 
        delayMicroseconds(500); 
        digitalWrite(y_stepPin, LOW);  
        delayMicroseconds(500);
    }
}
