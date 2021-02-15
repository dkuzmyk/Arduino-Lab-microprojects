/*  Dmytro Kuzmyk, 
 *  UIN 670920511
 *  NetID Dkuzmy3
 *  Lab 1 - Blink
 *  The code is supposed to cycle through 3 leds, one of which is the onboard led (led 13).
 *  The code has been set up with a delay of 1 second on the pins 13, 12 and 11. 
 *  Led 13 has to not be connected to anything, it triggers the internal LED 
 *  Led 12 to be connected to a red led, led 11 to a green led.
 */

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);  // setting up the three leds to be usable by the arduino
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);   // powering led 13, which is the onboard led
  delay(1000);              // wait for 1 second, the led is still on
  digitalWrite(13, LOW);    // turn off the on board led
  digitalWrite(12, HIGH);   // turn on the red led
  delay(1000);              // wait for 1 second
  digitalWrite(12, LOW);    // turn off the red led
  digitalWrite(11, HIGH);   // turn on the green led
  delay(1000);              // wait for 1 second
  digitalWrite(11, LOW);    // turn off gree led
                            // repeat
}
