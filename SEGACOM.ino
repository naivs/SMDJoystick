#include "SMDjoystick.h"

SMDjoystick first(A0, A1, A2, A3, A4, A5, 9);
SMDjoystick second(2, 3, 4, 5, 6, 7, 8);

void setup() {
  Serial.begin(9600);
}

void loop() {
    Serial.print(first.read(1));
    Serial.print(" ");
    Serial.println(second.read(2));
  
    delay(10);
}

