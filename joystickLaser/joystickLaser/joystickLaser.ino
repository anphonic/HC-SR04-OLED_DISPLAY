#include <Servo.h>

const int servo1 = 11;
const int servo2 = 10;
const int laserPin = 12;
int servoVal;
int jsx = 0;
int jsy = 1;
int jsz = 3;
int z, servx, servy,xReadMax=50, xRead;

Servo msrv1;
Servo msrv2;
void setup() {
  // put your setup code here, to run once:
  pinMode(jsz, INPUT);
  pinMode(laserPin, OUTPUT);
  msrv1.attach(servo1);
  msrv2.attach(servo2);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int x, y;
    x = analogRead(jsx);
    y = analogRead(jsy);
    x =abs(x);
    y = abs(y);
//  Serial.print("TotX: ");
//  Serial.print(x);
//  Serial.print(",TotY: ");
//  Serial.println(y);
//  delay(500);
  z = digitalRead(jsz);
  servoVal = map(x, 0, 1020, 0, 180);
  servx = servoVal;
  msrv1.write(servx);
  servoVal = map(y, 0, 1020, 0, 180);
  servy = servoVal;
  msrv2.write(servy);
  joystickOutput(servx, servy, x, y);
  delay(100);


}

void lightLaser(int pwn) {
  digitalWrite(laserPin, pwn);
}
void joystickOutput(int servx, int servy, int x, int y) {
  Serial.print(analogRead(jsx), DEC);
  Serial.print(", ");
  Serial.print(analogRead(jsy), DEC);
  Serial.print(", ");
  Serial.print(digitalRead(jsz), DEC);
  Serial.print(",sX: ");
  Serial.print(servx);
  Serial.print(",sY: ");
  Serial.println(servy);

  if (z == 1) {
    lightLaser(1);
  }
  else {
    lightLaser(0);
  }
}

