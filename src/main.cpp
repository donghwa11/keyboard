#include <Arduino.h>
#include <Keyboard.h>
#include <SoftwareSerial.h>

#define rxPin 0
#define txPin 1
SoftwareSerial bluetooth(rxPin,txPin);
#define yellowPin 4

#define key_out 2
#define key_in 3
#define btn_count 3

/*
chattering check counter value

unsigned long time_ms = millis();
unsigned long last_time = millis();
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(key_in, INPUT_PULLUP);
  pinMode(key_out, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  digitalWrite(yellowPin,HIGH);
  digitalWrite(key_out, LOW);
  Keyboard.begin();

  Serial.begin(115200);
  bluetooth.begin(115200);
}

void loop() {
  if(digitalRead(key_in) == LOW)
  {
    
    bluetooth.write(Keyboard.press('a'));
    Serial.println("BT a");
    
    Keyboard.press('a');
    Serial.println("USB a");
    Keyboard.releaseAll();
  }
  delay(500);
}