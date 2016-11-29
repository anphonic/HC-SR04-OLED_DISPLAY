#include <Servo.h>

const int servo1 = 5;
const int servo2 = 10;
int servoVal;
int jsx = 0;
int jsy = 1;
int jsz = 3;

Servo msrv1;
Servo msrv2;
void setup() {
  // put your setup code here, to run once:
  pinMode(jsz,INPUT);
  msrv1.attach(servo1);
  msrv2.attach(servo2);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 joystickOutput();
  int x,y,z;
  for (int xRead = 0;xRead <11;xRead++){
    x += analogRead(jsx);
  y += analogRead(jsy);
   }
   x = x/10;
   y = y/10;
   z = digitalRead(jsz);
  servoVal = map(x,0,1023,0,180);
  msrv1.write(servoVal);
  servoVal = map(y,0,1023,0,180);
  msrv2.write(servoVal);
  delay(30);
 

}

void joystickOutput(){
    Serial.print(analogRead(jsx),DEC);
  Serial.print(", ");
  Serial.print(analogRead(jsy),DEC);
  Serial.print(", ");
  Serial.println(digitalRead(jsz),DEC);
}

