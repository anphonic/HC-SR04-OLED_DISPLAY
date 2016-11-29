l
const int ledPin = 9;

void setup()
{

  /* add setup code here */
	Serial.begin(9600);
	pinMode(ledPin, OUTPUT);

}

void loop()
{

  /* add main program code here */
  for (int i=0;i<=254;i++){
    
    analogWrite(ledPin, i);
    Serial.println(i);
    delay(100);
  }	
  delay(1500);
	  for (int i=254;i>=0;i--){
    
    analogWrite(ledPin, i);
    Serial.println(i);
    delay(100);

  }
delay(1500);

}
