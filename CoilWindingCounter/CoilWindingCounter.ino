/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogReadSerial
*/
#include "TM1638plus.h"

const int DigitalPin = 8;     // the number of the pushbutton pin
const int StatusPin =  13;      // the number of the LED pin
bool LastDigialSensorValue = false;
int count = 0;

#define  STROBE_TM 4  // strobe = GPIO connected to strobe line of module
#define  CLOCK_TM 6  // clock = GPIO connected to clock line of module
#define  DIO_TM 7 // data = GPIO connected to data line of module

TM1638plus tm(STROBE_TM, CLOCK_TM , DIO_TM, false);

void setup() {

  tm.displayBegin();
  // initialize the LED pin as an output:
  pinMode(StatusPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(DigitalPin, INPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  bool DigialSensorValue = digitalRead(DigitalPin);
  
  
  if ((DigialSensorValue == true) && (LastDigialSensorValue == false))
  {
    digitalWrite(StatusPin, HIGH);
    count++;
    Serial.print("Got change state to true, count =");   
    Serial.println(count);   

    tm.displayIntNum(count, true); 
  }
  else if (DigialSensorValue)
  {
     digitalWrite(StatusPin, LOW);     
  }
  LastDigialSensorValue = DigialSensorValue;
  delay(1);        // delay in between reads for stability
}
