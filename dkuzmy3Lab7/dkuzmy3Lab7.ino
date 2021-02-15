#include <LiquidCrystal.h>
int BUTTON = 2;
int LED = 3;
bool LedON = false;
char c;

LiquidCrystal lcd(7,6,11,10,9,8);

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(BUTTON,INPUT);
  pinMode(LED, OUTPUT);
}

void loop(){ 
  c = Serial.read();                                  // read incoming commands
  
  if(digitalRead(BUTTON) == HIGH){                    // if button is pressed
    lcd.setCursor(0,1);
    lcd.print("Button Pressed");                      // lcd debug
    Serial.write('1');                                // send signal 1
    while(digitalRead(BUTTON) == HIGH){}
  }
  
  if(c == '1'){                                       // if received signal 1
    if(!LedON){                                       // if led is off
        digitalWrite(LED, HIGH);                      // set led to high
        LedON = true;                                 // set led to on
        
      }
    else if (LedON){                                  // else if led is on
        digitalWrite(LED, LOW);                       // turn off led
        LedON = false;                                // set led to off   
      }
  }
}
