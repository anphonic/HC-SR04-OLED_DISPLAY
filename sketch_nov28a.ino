#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// Pins
const int TRIG_PIN = 11;
const int ECHO_PIN = 12;


// Anything over 400 cm (23200 us pulse) is "out of range"
const unsigned int MAX_DIST  = 23200, MIN_DIST = 150;
float avgDist = 0, dist, cm,inches;
int pingCount,avgCount;
unsigned long pulse_width;

void setup() {

  //lcd.Begin(16,2)
  // The Trigger pin will tell the sensor to range find
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);

  // We'll use the serial monitor to view the sensor output
  Serial.begin(9600);
    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
  
  // draw a single pixel
  display.drawPixel(10, 10, WHITE);
  // Show the display buffer on the hardware.
  // NOTE: You _must_ call display after making any drawing commands
  // to make them visible on the display hardware!
  display.display();
  delay(2000);
  display.clearDisplay();
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
  if(pingCount>10){
     dist=inches;
     pingCount= 1;
  }
  else {
  dist= dist+inches++;
  avgDist = dist/pingCount;
  }
  if(pingCount==10){
  printReadings();
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
void printReadings()
{
    // Print out results
  if ( pulse_width > MAX_DIST ) {
    Serial.println("Out of range");
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Out of range");
    display.display();  
  } 
  else if (pulse_width <MIN_DIST) { 
    display.print(pulse_width);
    Serial.println("Object to close!!") ;
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Object to close!!");
    display.display();
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
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print(pingCount);
    display.print(" pc \t");
    display.print(avgDist);
    display.print(" avgInch \t");
    display.print(cm);
    display.print(" cm \t");
    display.print(inches);
    display.println(" in");
    display.display();        
  }
  delay(1000);
  display.clearDisplay();
}

