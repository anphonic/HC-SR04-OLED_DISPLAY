// Pins
const int TRIG_PIN = 11;
const int ECHO_PIN = 12;
int laserPin = 3;


// Anything over 400 cm (23200 us pulse) is "out of range"
const unsigned int MAX_DIST  = 23200, MIN_DIST = 5500;
float avgDist = 0, dist, cm,inches;
int pingCount,avgCount;
unsigned long pulse_width;

void setup() {

  //lcd.Begin(16,2)
  // The Trigger pin will tell the sensor to range find
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(laserPin,OUTPUT);

  // We'll use the serial monitor to view the sensor output
  Serial.begin(9600);
}

void loop() {

  unsigned long t1;
  unsigned long t2;
  

  // Hold the trigger pin high for at least 10 us
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Wait for pulse on echo pin
 // while ( digitalRead(ECHO_PIN) == 0 );
 pulse_width = pulseIn(ECHO_PIN,HIGH);

  // Calculate distance in centimeters and inches. The constants
  // are found in the datasheet.
  cm = (pulse_width*0.034)/2;// / 58.0;
  inches = (pulse_width*0.0133)/2; // 148.0;
  pingCount++;
  //set average distance and reset it every x pings
  if(pingCount>5){
     dist=inches;
     pingCount= 1;
  }
  else {
  dist= dist+inches++;
  avgDist = dist/pingCount;
  }
  if(pingCount==5){
  lightLaser();
  }
  if (avgDist < 10){
   // playTone(); //previously had it play tones over a piezo based on distance from the sensor
  }
  else {
   // noTone(piezo);
    }

  // Wait at least 60ms before next measurement
  delay(60);
}
void lightLaser()
{
    // Print out results
  if ( pulse_width > MAX_DIST ) {
    digitalWrite(laserPin,LOW);
  } 
  else if (pulse_width <MIN_DIST) { 
      Serial.print(pulse_width);
      Serial.println(":  Object to close!!") ;
      digitalWrite(laserPin,HIGH);

    }
  else  {
    Serial.print(pingCount);
    Serial.print(" pc \t");
    Serial.print(avgDist);
    Serial.print(" avgInch \t");
    Serial.print(cm);
    Serial.print(" cm \t");
    Serial.print(inches);
    Serial.println(" in");
digitalWrite(laserPin,LOW);       
  }
  delay(1000);
}

