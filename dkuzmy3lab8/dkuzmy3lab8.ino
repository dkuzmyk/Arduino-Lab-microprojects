/*  Name: Dmytro Kuzmyk
 *  NetID: dkuzmy3
 *  Description: This program uses an LCD and two buttons to switch between stages using an interrupt system.
 *  The lcd shows the time while on stage 0, and switches to another prompt when on stage 1, time is continuously
 *  running in the background.
 *  
 */ 


#include <LiquidCrystal.h>

const int stage1 = 2;                                               // declaring the pins for the buttons
const int stage2 = 3;
volatile boolean state = false;                                     // stage state, I use false for 0 and true for 1

LiquidCrystal lcd (12,11,7,6,5,4);                                  // declare lcd

void setup() {
  //pinMode(stage1, INPUT);                                         // useless
  //pinMode(stage2, INPUT);
  attachInterrupt(digitalPinToInterrupt(stage1), button1, RISING);  // setup the stage interrupts with the individual functions and buttons 
  attachInterrupt(digitalPinToInterrupt(stage2), button2, RISING);  // can setup on current jump between RISING, CHANGE, FALLING
  lcd.begin(16,2);                                                  // lcd size
}

void loop() {
   int timeCount = millis()/1000;                                   // get time and store into variable, divided by 1k because in ms

   if(!state){                                                      // for stage 0
     lcd.setCursor(0,0);                                            // lcd setup
     lcd.print("Waited for ");
     lcd.print(timeCount);
     lcd.print("s"); 
   }

   else{                                                            // for stage 1
     lcd.setCursor(0,0);
     lcd.print("Interrupt");
     lcd.setCursor(1,1);
     lcd.print("Activated!");
   }
  lcd.clear();                                                      // refresh lcd
}

void button1(){                                                     // change state 1
  state = true;
}                                                        

void button2(){                                                     // change stage 0
  state = false;
}
