int greenLed = 13;
int yellowLed = 12;
int redLed = 8;
int inputPin = 2;
int pirState = LOW;
int val = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(redLed, OUTPUT);
pinMode(yellowLed, OUTPUT);
pinMode(greenLed, OUTPUT);
pinMode(inputPin,INPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
        digitalWrite(redLed    ,HIGH);
       digitalWrite(yellowLed,HIGH);
        digitalWrite(greenLed,HIGH);
  val = digitalRead(inputPin);
    if (val==HIGH){
      digitalWrite(redLed    ,HIGH);
       digitalWrite(yellowLed,HIGH);
        digitalWrite(greenLed,HIGH);
      if(pirState == LOW){
        Serial.println("motion");
        pirState = HIGH;
      }
    } else {
         analogWrite(redLed,LOW);
       analogWrite(yellowLed,LOW);
        analogWrite(greenLed,LOW);
      Serial.println("no motion");
      pirState = LOW;
      }
}

