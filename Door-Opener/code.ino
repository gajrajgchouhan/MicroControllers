#include <LiquidCrystal.h>

int no_of_persons = 0;
float duration, distance;

// HC-SR04 IR Sensor
const int trigPin = 13;
const int echoPin = 12;

// PIR Sensor
const int PIR_In = 2;
int pirState = LOW;

// LCD
const int RS = 3, // register select PIN
		  En = 4, // Enable pin
		  D4 = 5, D5 = 6, D6 = 7, D7 = 8;

LiquidCrystal lcd(RS, En, D4, D5, D6, D7);
// Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)

void setup()
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(PIR_In, INPUT); // PIR 
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("no of persons");
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW); // sound wave for 10 micro seconds.
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // how much time does it
  			// take for echo to go HIGH (in microseC)
  distance = (duration*.0343)/2; 
  if (distance < 100) {// if distance < 100 CM 
      // OPEN
      Serial.println("KHUL JA SIM SIM");
  }
  else {
    Serial.println("not opening");
  }
  int sensorState = digitalRead(PIR_In);
  if (sensorState == HIGH) {
    if (pirState == LOW) {
      no_of_persons += 1;
      pirState = HIGH;
    }
  }
  else {
    if (pirState == HIGH) {
      pirState = LOW;
    }
  }
  delay(1000); // 1 sec
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(no_of_persons);
}
