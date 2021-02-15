/*  Dmytro Kuzmyk, 
 *  UIN 670920511
 *  NetID Dkuzmy3
 *  Lab 4 - photoresistor and lcd display
 *  This project is supposed to use an lcd to display the value of light caught by the
 *  photoresistor.
 */
// include the library code:
#include <LiquidCrystal.h>                      // lcd library

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);            // initializing lcd pins
int value;                                      // variable for photoresistor index
const int pr = A1;                              // photoresistor input setup


void setup(){
  lcd.begin(16,2);                              // setting up lcd screen
  pinMode(pr, INPUT);                           // photoresistor pin setup
}

void loop(){ 
  value = analogRead(pr);                       // read the value from the photoresistor

  //debug                                       // useful for debugging ;)
  //lcd.setCursor(0,1);
  //lcd.print("Light: ");
  //lcd.print(value);

  lcd.setCursor(0,0);                           // set the lcd cursor to 0,0
  
  if(value<= 30){                               // condition for the text on lcd
    lcd.print("Dark");                          // these greatly vary based on the setup
  }                                             // the resistors etc..

  if((30 < value) && (value <= 45)){
    lcd.print("Partially Dark");    
  }

  if((45 < value) && (value <= 55)){
    lcd.print("Medium");    
  }

  if((55 < value) && (value <= 70)){
    lcd.print("Partially Light");    
  }

  if(70 <= value){
    lcd.print("Fully Light");    
  }
  
  delay(300);                                   // delay  
  lcd.clear();                                  // clear screen and start over
}
