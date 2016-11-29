
int intPin = 9;
int outPin = 5;
int voltage = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(intPin, INPUT);
pinMode(outPin, OUTPUT);
//digitalWrite(outPin, HIGH);

Serial.begin(9600);
Serial.println("Beginning program");
delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(outPin,HIGH);
  voltage = digitalRead(intPin);
  Serial.print("Read \t");
  Serial.println(voltage);
  delay(100);
  //analogWrite(A5,0);
  //digitalWrite(outPin, LOW);
  // voltage = analogRead(intPin);
  // Serial.print("LOW \t");
   //Serial.println(voltage);
  // delay(500);
  

}
