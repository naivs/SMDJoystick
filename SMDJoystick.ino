#include "SMDjoystick.h"

SMDjoystick first(A0, A1, A2, A3, A4, A5, 9);
SMDjoystick second(2, 3, 4, 5, 6, 7, 8);

int ENQ = 0x5;
int ACK = 0x6;
int STX = 0x2;
int NAK = 0x15;

int data;
bool isRunning = false;

void setup() {
  Serial.begin(19200);
  Serial.println("sega_ready");
}

void loop() {
  if (isRunning) {
    String out = String(first.read(1)) 
    + " "
    + String(second.read(2));
    Serial.println(out);
    //Serial.flush();
  }
  
  delay(10);
}

void serialEvent() {
    data = 0;

  while (Serial.available() > 0) {
    data = Serial.parseInt();
  }

  switch (data) {
    case 222:
      //echo beacon
      Serial.println("sega_ready");
      break;

    case 444:
      //start
      isRunning = true;
      Serial.println("started");
      break;

    case 666:
      //stop
      isRunning = false;
      Serial.println("stopped");
      break;

    default:
      //something else
      break;
  }

  Serial.flush();
}

