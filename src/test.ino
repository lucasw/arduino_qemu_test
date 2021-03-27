/*
Copyright (C) 2021 Lucas Walter
 */

// #include <avr/sleep.h>
#include <util/delay.h>

unsigned long start_time = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("init test");
  start_time = millis();
}

int count = 0;
int count2 = 0;

void loop() {
  // int value = analogRead(A0);
  // Serial.println(count);
  count += 1;
  if (count > 100) {
    // TODO(lucasw) millis doesn't work in qemu?
    unsigned long cur_t = millis();
    unsigned long elapsed_t = cur_t - start_time;
    // Serial.println(cur_t);
    // Serial.println(elapsed_t);
    Serial.println("loop");
    Serial.println(count2);
    count2 += 1;
    count = 0;
    /*
    cli();
    sleep_enable();
    sleep_cpu();
    */
  }
  // delayMicroseconds(10000);
  _delay_ms(1000);
  // delay(1);        // delay in between reads for stability
}
