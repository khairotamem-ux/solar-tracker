#include <Servo.h>

Servo horiz;   // يمين/يسار
Servo vert;    // فوق/تحت

int posH = 90;
int posV = 90;

const int tolerance = 30;

void setup() {
  horiz.attach(9);
  vert.attach(10);
  horiz.write(posH);
  vert.write(posV);
}

void loop() {
  int tl = analogRead(A0);
  int tr = analogRead(A1);
  int bl = analogRead(A2);
  int br = analogRead(A3);

  int top    = (tl + tr) / 2;
  int bottom = (bl + br) / 2;
  int left   = (tl + bl) / 2;
  int right  = (tr + br) / 2;

  int diffH = left - right;
  if (abs(diffH) > tolerance) {
    if (diffH > 0) posH++;
    else posH--;
  }

  int diffV = top - bottom;
  if (abs(diffV) > tolerance) {
    if (diffV > 0) posV++;
    else posV--;
  }

  posH = constrain(posH, 0, 180);
  posV = constrain(posV, 0, 180);

  horiz.write(posH);
  vert.write(posV);

  delay(20);
}
