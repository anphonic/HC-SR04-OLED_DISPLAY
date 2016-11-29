const int motorIn1 = 9;
const int motorIn2 = 10;
void setup()
{

	/* add setup code here */

	pinMode(motorIn1, OUTPUT);
	pinMode(motorIn2, OUTPUT);
}

void loop()
{
  /* add main program code here */
	clockwise(200);
		delay(1000);
		counterclockwise(300);
		delay(1000);
}
void clockwise(int Speed){
	analogWrite(motorIn1, Speed);
	analogWrite(motorIn2, 0);
}
void counterclockwise(int Speed){
	analogWrite(motorIn1, 0);
	analogWrite(motorIn2, Speed);
}