/*
  Character analysis operators

  Examples using the character analysis operators.
  Send any byte and the sketch will tell you about it.

  created 29 Nov 2010
  modified 2 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/CharacterAnalysis
*/

String thisChar;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.print("Input text:");
}

void loop() {
  // get any incoming bytes:
  if (Serial.available() > 0) {

    thisChar = Serial.readString();
    Serial.println(thisChar);

    for(int i=0; i<thisChar.length(); i++){
      switch(thisChar[i]){
        case '0':
          Serial.println(thisChar[i]);
          break;
        case '1':
          Serial.println(thisChar[i]);
          break;
        case '2':
          Serial.println(thisChar[i]);
          break;
        case '3':
          Serial.println(thisChar[i]);
          break;
        case '4':
          Serial.println(thisChar[i]);
          break;
        case '5':
          Serial.println(thisChar[i]);
          break;
        case '6':
          Serial.println(thisChar[i]);
          break;
        case '7':
          Serial.println(thisChar[i]);
          break;
        case '8':
          Serial.println(thisChar[i]);
          break;
        case '9':
          Serial.println(thisChar[i]);
          break;
      }
    }
  }
}
