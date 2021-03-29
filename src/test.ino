/*
Copyright (C) 2021 Lucas Walter
 */

#include <avr/io.h>
// #include <avr/sleep.h>
#include <util/delay.h>

unsigned long start_time = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("init test");
  // PB7
  pinMode(LED_BUILTIN, OUTPUT);
  start_time = millis();
}

int count = 0;
int count2 = 0;

void loop() {
  // int value = analogRead(A0);
  // Serial.println(count);
  count += 1;
  // even with cpulimit -l 2 this goes about 10x real time, what should
  // be 10 second intervals is close to 1 second.
  if (count >= 100) {
    // TODO(lucasw) millis doesn't work in qemu?
    unsigned long cur_t = millis();
    unsigned long elapsed_t = cur_t - start_time;
    // Serial.println(cur_t);
    // Serial.println(elapsed_t);
    // TODO(lucasw) add serial interaction,
    // use python as the client.
    Serial.print("loop ");
    Serial.println(count2);
    count2 += 1;
    count = 0;
  }

  int buf_size = 32;
  char buffer[buf_size];
  int ind = 0;
  while ((Serial.available() > 0) && (ind < buf_size - 1)) {
    buffer[ind] = Serial.read();
    ind += 1;
  }
  buffer[ind] = 0;
  if (ind > 0) {
    Serial.print("rx ");
    Serial.print(ind - 1);
    Serial.print(" chars: ");
    Serial.println(buffer);
  }
  // This does delay, but emulating faster than real time.
  _delay_ms(1000);
  // This doesn't delay at all in qemu
  // delayMicroseconds(10000);
  // This locks up qemu
  // delay(1);        // delay in between reads for stability
}
