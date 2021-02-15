
  import processing.serial.*;

  Serial myPort;        // The serial port
  int xPos = 1;         // horizontal position of the graph
  float inByte = 0;

  void setup () {
    size(600, 600);                                          // size of the screen
    println(Serial.list());                                  // read the serial input

    myPort = new Serial(this, Serial.list()[1], 9600);      //  setup the serial port and the COM to read

    myPort.bufferUntil('\n');                                // end line on newline

    background(0);                                          // background color
  }

  void draw () {
    stroke(255, 0, 0);                                        // stroke color
    line(xPos, height, xPos, height - inByte);                // line height

    if (xPos >= width) {                                      // new page
      xPos = 0;
      background(0);
    } else {
      xPos++;
    }
  }

  void serialEvent (Serial myPort) {                           
    String inString = myPort.readStringUntil('\n');

    if (inString != null) {
      inString = trim(inString);
      inByte = float(inString);
      println(inByte);
      inByte = map(inByte, 0, 1023, 0, height);
    }
  }
