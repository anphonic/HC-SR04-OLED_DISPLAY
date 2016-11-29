
const int inputPin = 9;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int sensorValue = digitalRead(inputPin);
 // do {     
      Serial.println(sensorValue);
      delay(100);
       Serial.println("I DO DO DO DO!\t");
   // }
  //  while ( sensorValue > 0);
   // if (sensorValue <1) {
   // Serial.println("NO NO NO");
//};//end-if;
  }
