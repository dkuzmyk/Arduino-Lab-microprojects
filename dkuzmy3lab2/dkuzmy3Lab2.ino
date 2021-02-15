/*  Dmytro Kuzmyk, 
 *  UIN 670920511
 *  NetID Dkuzmy3
 *  Lab 2 - Binomial counter
 *  The code is supposed to take a button as input to increment the binary number and display it with 3 led lights.
 *  A second button can decrement the bonary number. 
 *  This code has been designed to rest the bit count when the bit value goes above 7
 *  This code also limits the minimum number of bit to 0, as the bit counter could go negative when down button is spammed
 */

int BitsValue = 0;  // a counter number for the bits

int ButtonUP = 3;   // button to increment the number, pin 3
int ButtonDown = 4; // button to decrement the number, pin 4

int LED1 = 12;      // leds on pins 12, 11, 10
int LED2 = 11;
int LED3 = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);              // set up leds as output
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  pinMode(ButtonUP, INPUT);           // set up buttons as input to the arduino
  pinMode(ButtonDown, INPUT);
}

void loop() {
  if(digitalRead(ButtonUP) == HIGH){  // when the arduino detects the button up is pressed
    BitsValue++;                      // we increment the value of the counter variable
    if(BitsValue%2 > 0){              // if the value with a reminder 2 is more than 0
      digitalWrite(LED1, HIGH);}      // we light up the led value 1
    else{digitalWrite(LED1, LOW);}    // else, we don't. lol
  
    if(BitsValue%4 > 1){              // if the value with the reminder 4 is more than 1
      digitalWrite(LED2, HIGH);}      // we light up the led value 2
    else{digitalWrite(LED2, LOW);}  
  
    if(BitsValue%8 > 3){              // if the value with a reminder 8 is more than 3
      digitalWrite(LED3, HIGH);}      // we light up the led value 4
    else{digitalWrite(LED3, LOW);}
    delay(100);                       // delay

    while(digitalRead(ButtonUP) == HIGH){// this is made to stop the loop until the button is unpressed
    }
  }
  if(digitalRead(ButtonDown) == HIGH){// same goes for the decrement button, we just decrement the counter number
    BitsValue--;                      // and implement the same method

    if(BitsValue%2 > 0){
      digitalWrite(LED1, HIGH);}
    else{digitalWrite(LED1, LOW);}
  
    if(BitsValue%4 > 1){
      digitalWrite(LED2, HIGH);}
    else{digitalWrite(LED2, LOW);}
  
    if(BitsValue%8 > 3){
      digitalWrite(LED3, HIGH);}
    else{digitalWrite(LED3, LOW);}
    delay(100);

    while(digitalRead(ButtonDown) == HIGH){// this is made to stop the loop until the button is unpressed
    }
    }
  if(BitsValue < 0 || BitsValue > 7){BitsValue = 0;}// if the down button is pressed, we won't allow the bits to go below 0
                                                    // if the value of bits goes over 7, the value is reset
  
/*
  if(BitsValue%2 > 0){
    digitalWrite(LED1, HIGH);}
  else{digitalWrite(LED1, LOW);}

  if(BitsValue%4 > 0){
    digitalWrite(LED2, HIGH);}
  else{digitalWrite(LED2, LOW);}

  if(BitsValue%8 > 0){
    digitalWrite(LED3, HIGH);}
  else{digitalWrite(LED3, LOW);}
*/
  //delay(150);
}
