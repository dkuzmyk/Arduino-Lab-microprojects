// Name: Dmytro Kuzmyk
// NetID: dkuzmy3
// Desc: this program takes analog input from the arduino and uses processing
// to draw the graph of the values that the analog inputs. 

// A0 = thermoresistor
// A1 = photoresistor
// A2 = potentiometer

void setup() {
  Serial.begin(9600);                 // activate the serial port
}

void loop() {
 Serial.println(analogRead(A0));      // read the A0 analog pin
 delay(50);
 Serial.println(analogRead(A1));      // read the A1 analog pin
 delay(50);
 Serial.println(analogRead(A2));      // read the A2 analog pin
 delay(50);
}
