// const int po = 2;
int pi = A7;


void setup() {
  // put your setup code here, to run once:
  pinMode(pi,INPUT);
Serial.begin(9600);
//digitalWrite(po,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
pi = analogRead(pi);
Serial.println(pi);
delay(100);
}
