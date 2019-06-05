/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/

int led = 5; // connect to led
int sensor = A2; // connect to sensor

int led2 = 6; // connect to led
int sensor2 = A4; // connect to sensor

int sensorValue = 0;
int sensorValue2 = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT_PULLUP);
  pinMode(led2, OUTPUT);
  pinMode(sensor2, INPUT_PULLUP);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A2:
  int sensorValue = analogRead(sensor);

  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability

  //  int brightness = map(sensorValue, 400, 15, 0, 255);

  if (sensorValue < 200) {
    for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(led, fadeValue);
      // wait for 30 milliseconds to see the dimming effect
      delay(20);
    }
      // fade out from max to min in increments of 5 points:
      for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
        // sets the value (range from 0 to 255):
        analogWrite(led, fadeValue);
        // wait for 30 milliseconds to see the dimming effect
        delay(20);
      }
    }
    else {
      digitalWrite(led, LOW);
    }

   

  // print out the value you read:
  int sensorValue2 = analogRead(sensor2);
  Serial.println(sensorValue2);
  delay(1);        // delay in between reads for stability

  //  int brightness = map(sensorValue, 400, 15, 0, 255);

  if (sensorValue2 < 200) {
    for (int fadeValue2 = 0 ; fadeValue2 <= 255; fadeValue2 += 5) {
      // sets the value (range from 0 to 255):
      analogWrite(led2, fadeValue2);
      // wait for 30 milliseconds to see the dimming effect
      delay(20);
    }
      // fade out from max to min in increments of 5 points:
      for (int fadeValue2 = 255 ; fadeValue2 >= 0; fadeValue2 -= 5) {
        // sets the value (range from 0 to 255):
        analogWrite(led2, fadeValue2);
        // wait for 30 milliseconds to see the dimming effect
        delay(20);
      }
    }
    else {
      digitalWrite(led2, LOW);
  }
}
