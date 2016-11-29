
const int xPin = A0;
const int yPin = A1;
const int zPin = A2;


int x=0,y=0,z=0;


void setup() {

  Serial.begin(9600);
}

void loop() { 
  // put your main code here, to run repeatedly:
x = analogRead(xPin);
y = analogRead(yPin);
z = analogRead(zPin);


float zero_G = 512.0;
float scale = 102.4;
Serial.print("X = " + String(x) +"\t");
Serial.print("Y = " + String(y) +"\t");
Serial.print("Z = " + String(z) + "\n");
Serial.print(((float)x - 331.5)/65*9.8 ); 
Serial.print("\t");
Serial.print(((float)y - 329.5)/68.5*9.8 ); 
Serial.print("\t");
Serial.print(((float)z - 340)/68*9.8 ); 
Serial.print("\n");
delay(500);
}
