#include <Keypad.h>
#include <LiquidCrystal.h>

// Items
int items[] = {1, 1, 1, 1, 1, 1, 1, 1};
// 8 items in array, 1 means it's available
// another way to do this
// make an array which has count of how many items
// there are: [1, 2, 3] 
// means 1 item 1, 2 item 2s, 3 item 3s, etc...

// Keypad
const byte numRows= 3; //number of rows on the keypad
const byte numCols= 3; //number of columns on the keypad
int keypressed;
//char msg[30];

// LCD
const int RS = 8, // register select PIN
      En = 9, // Enable pin
      D4 = 13, D5 = 12, D6 = 11, D7 = 10;

LiquidCrystal lcd(RS, En, D4, D5, D6, D7);
// Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3'}, 
{'4', '5', '6'}, 
{'7', '8', '9'},
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {7,6,5}; //Rows 0 to 3
byte colPins[numCols]= {4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  lcd.setCursor(0, 0);
  keypressed = myKeypad.getKey();
  //Serial.println(keypressed);
  if (keypressed)
  {
    keypressed -= '0';
    if (keypressed >= 1 && keypressed <= 8)
    {
      Serial.println("correct");
      // correct key
      if (items[keypressed-1] == 1)
      {
        //char msg[30];
        //sprintf(msg, "%d YES", keypressed);
        //Serial.println("available");
        lcd.clear();
        lcd.print("available");
        items[keypressed-1] = 0;
      }
      else
      {
       char msg[30];
       //sprintf(msg, "%d NO", keypressed);
       //Serial.println("not available");
       lcd.clear();
       lcd.print("not available");
      }
    }
    else
    {
      lcd.clear();
      lcd.print("press b/w 1 & 8");
      //Serial.println("Error - key pressed must be b/w 1 & 8");
    }
  }
  delay(100);
}
