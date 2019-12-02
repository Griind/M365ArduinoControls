#include <Metro.h>

const int LeftTurnPinIn =  9;
const int LeftTurnOut = 3;
const int RightTurnPinIn =  10;
const int RightTurnOut = 4; 
const int RearRedLightPositiveOut = 5;
const int LightPinIn =  11;
const int LightOut = 5;
const int HornPinIn =  12;
const int HornOut = 2;



int leftButtonState = 0;
int RigthButtonState = 0;
int LightButtonState = 0;
int HornButtonState = 0;
boolean blinkState = false;

Metro blink1Metro = Metro(500);
void setup() {

  pinMode(LeftTurnPinIn, INPUT);
  pinMode(LeftTurnOut, OUTPUT);
  pinMode(RightTurnPinIn, INPUT);
  pinMode(RightTurnOut, OUTPUT);
  pinMode(LightPinIn, INPUT);
  pinMode(LightOut, OUTPUT);
  pinMode(HornPinIn, INPUT);
  pinMode(HornOut, OUTPUT);

  digitalWrite(LeftTurnOut, LOW);
  digitalWrite(RightTurnOut, LOW);
  digitalWrite(LightOut, LOW);
  digitalWrite(HornOut, LOW);

}
void blink(bool left) {
  if (blink1Metro.check())
  {
    blinkState = !blinkState;
    digitalWrite(left ? LeftTurnOut : RightTurnOut, blinkState);
  }
}
void loop() {
  leftButtonState = digitalRead(LeftTurnPinIn);
  RigthButtonState = digitalRead(RightTurnPinIn);
  LightButtonState = digitalRead(LightPinIn);
  HornButtonState = digitalRead(HornPinIn);

  if (HornButtonState == HIGH) {
    digitalWrite(HornOut, HIGH);
  } else {
    digitalWrite(HornOut, LOW);
  }

  if (LightButtonState == HIGH) {
    digitalWrite(LightOut, HIGH);
  } else {
    digitalWrite(LightOut, LOW);
  }

  if (leftButtonState == HIGH) {
    blink(true);
  } else {
    digitalWrite(LeftTurnOut, LOW);
  }

  if (RigthButtonState == HIGH) {
    blink(false);
  } else {
    digitalWrite(RightTurnOut, LOW);
  }
}
