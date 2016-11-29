void setup()
{

  /* add setup code here */
	Serial.begin(9600);

}

void loop()
{

  /* add main program code here */
	int sensorValue = analogRead(A0);
	Serial.println(sensorValue);
	delay(1);

}
