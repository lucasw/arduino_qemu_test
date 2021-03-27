/*
Copyright (C) 2021 Lucas Walter
 */

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin 0:
  // int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println("TEST1");
  Serial.println("FOO");
  delay(1);        // delay in between reads for stability
}
