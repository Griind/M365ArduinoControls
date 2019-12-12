#include <Metro.h>

const int LeftTurnPinIn =  9;
const int LeftTurnOut = 3;
const int RightTurnPinIn =  10;
const int RightTurnOut = 4; 
const int RearLeftRedLightOut = 5;
//const int LightPinIn =  11;
const int RearRightRedLightOut = 6;
const int HornPinIn =  12;
const int HornOut = 2;



int leftButtonState = 0;
int RigthButtonState = 0;
int LightButtonState = 0;
int HornButtonState = 0;
boolean blinkState = false;

Metro blink1Metro = Metro(200);
void setup() {

  pinMode(LeftTurnPinIn, INPUT);
  pinMode(LeftTurnOut, OUTPUT);
  pinMode(RightTurnPinIn, INPUT);
  pinMode(RightTurnOut, OUTPUT);
  //pinMode(LightPinIn, INPUT);
  pinMode(HornPinIn, INPUT);
  pinMode(HornOut, OUTPUT);
  pinMode(RearLeftRedLightOut, OUTPUT);
  pinMode(RearRightRedLightOut, OUTPUT);

  digitalWrite(LeftTurnOut, LOW);
  digitalWrite(RightTurnOut, LOW);
  digitalWrite(HornOut, LOW);
  digitalWrite(RearLeftRedLightOut, HIGH);
  digitalWrite(RearRightRedLightOut, HIGH);

}
void blink(bool left) {
  if (blink1Metro.check())
  {
    blinkState = !blinkState;
    digitalWrite(left ? LeftTurnOut : RightTurnOut, blinkState);
    digitalWrite(left ? RearLeftRedLightOut : RearRightRedLightOut, !blinkState);
  }
}
void loop() {
  leftButtonState = digitalRead(LeftTurnPinIn);
  RigthButtonState = digitalRead(RightTurnPinIn);
  HornButtonState = digitalRead(HornPinIn);

  if (HornButtonState == HIGH) {
    digitalWrite(HornOut, HIGH);
  } else {
    digitalWrite(HornOut, LOW);
  }

  if (leftButtonState == HIGH) {
    blink(true);
  } else {
    digitalWrite(LeftTurnOut, LOW);
    digitalWrite(RearLeftRedLightOut, HIGH);
  }

  if (RigthButtonState == HIGH) {
    blink(false);
  } else {
    digitalWrite(RightTurnOut, LOW);
    digitalWrite(RearRightRedLightOut, HIGH);
  }
}
