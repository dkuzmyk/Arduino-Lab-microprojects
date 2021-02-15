/*  Dmytro Kuzmyk, 
 *  UIN 670920511
 *  NetID Dkuzmy3
 *  Lab 3 - lcd scrolling message
 *  The code is supposed to make use of a LCD to display the user's name and a quote
 *  on choice that is above 16 letters so that the message would scroll. the name is not
 *  supposed to scroll.
 */

// include the library code:
#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);            // initializing lcd pins

void setup(){
  lcd.begin(16,2);                              // setting up lcd screen
  //lcd.print("Dmytro Kuzmyk");
}

void loop(){ 
  /*lcd.setCursor(0,0);
  lcd.print("Dmytro Kuzmyk");
  
  lcd.setCursor(0,1);
  lcd.print("Die with memories, not dreams.");
  delay(500);*/
  
  for(int i=0; i<15; i++){                      // loop for the srolling message
    lcd.scrollDisplayLeft();                    // set to scroll left
    lcd.setCursor(1,1);                         // set cursor to 1,1
    lcd.print("Die with memories, not dreams.");// the message to be scrolled    
    lcd.setCursor(i+1,0);                       // move the cursor so the message slides
    lcd.print("Dmytro Kuzmyk");                 // user name that gets printed on top
    delay(300);                                 // delay
  }
  delay(1500);                                  // delay at the end of the scrolling
  lcd.clear();                                  // clear screen and start over
}
