#include <Arduino.h>
#include <Keyboard.h>

#define key_out 2
#define key_in 3
#define btn_count 3

unsigned long time_ms = millis();
unsigned long last_time = millis();

void setup() {
  // put your setup code here, to run once:
  pinMode(key_in, INPUT_PULLUP);
  pinMode(key_out, OUTPUT);
  digitalWrite(key_out, LOW);
  Keyboard.begin();
}

void loop() {
  if(digitalRead(key_in) == LOW)
  {
    Keyboard.press('a');
    Keyboard.releaseAll();
  }
  // put your main code here, to run repeatedly:
}