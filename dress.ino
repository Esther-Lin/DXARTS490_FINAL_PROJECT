int led = 6; // connect to led
int sensor = A2; // connect to sensor
int sensorValue = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT_PULLUP);

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A2:
  int sensorValue = analogRead(sensor);
  // int freq = map(sensorValue, 0, 950, 80, 2000);
  //int dur = map(sensorValue, 0, 950, 100, 500);

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
  }
