int ledPin = 7;
int inputPin = 2;
int pirState = LOW;
int val = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
pinMode(inputPin,INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin);
    if (val==HIGH){
      digitalWrite(ledPin,HIGH);
      if(pirState == LOW){
        Serial.println("motion");
        pirState = HIGH;
      }
    } else {
      digitalWrite(ledPin, LOW);
      Serial.println("no motion");
      pirState = LOW;
      }
}

