#include <Key.h>


#include <Keypad.H>

const byte numRows = 4;
const byte numCols = 4;

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols] =
{
	{ '1', '2', '3', 'A' },
	{ '4', '5', '6', 'B' },
	{ '7', '8', '9', 'C' },
	{ '*', '0', '#', 'D' }
};

byte rowPins[numRows] = { 6, 7, 8, 9 }; // row 0-3
byte colPins[numCols] = { 5, 4, 3, 2 };//cols 0-3


Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
void setup()
{

  /* add setup code here */
	Serial.begin(9600);  

}


//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 
//(this means no key is pressed during the whole keypad scan process
void loop()
{
  char pinNum = ' ';
  if (pinNum ==char(' ')) {
    Serial.println("Please enter a pin: ");
    pinNum = myKeypad.getKey();
    Serial.println(pinNum);
  }
  
	char keypress = myKeypad.getKey();
	if (keypress != NO_KEY){
    if (keypress != pinNum){
     Serial.println(keypress + " is an incorrect pin number"); 
    }
    else {
      Serial.println("Welcome! That was the correct pin number: " + keypress);
    }
		
	}
  
}
