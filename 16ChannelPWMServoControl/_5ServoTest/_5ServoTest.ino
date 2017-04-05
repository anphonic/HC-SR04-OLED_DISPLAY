#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x40);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("5PWM Servo Test");

}

void loop() {
  // put your main code here, to run repeatedly:
  pwm1.begin();
 pwm1.setPWMFreq(60);  
 Serial.println("0");
 pwm1.setPWM(0,1024,3072);
  Serial.println("1");
 pwm1.setPWM(1,0,2048);
  Serial.println("2");
 pwm1.setPWM(2,512,3048);
  Serial.println("3");
 pwm1.setPWM(3,2048,4090);
}
