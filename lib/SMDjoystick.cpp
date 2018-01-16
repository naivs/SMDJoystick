#include "SMDjoystick.h"

SMDjoystick::SMDjoystick(int upPin, 
			 int downPin, 
			 int leftPin, 
			 int rightPin,
			 int aPin,
			 int selectPin,
			 int startPin):
				up(upPin), 
 				down(downPin), 
 				left(leftPin), 
 				right(rightPin), 
 				a(aPin), 
 				select(selectPin), 
 				start(startPin) 
{
	pinMode(up,INPUT);
	pinMode(down,INPUT);
	pinMode(left,INPUT);
	pinMode(right,INPUT);
	pinMode(a,INPUT);
	pinMode(start,INPUT);
	pinMode(select,OUTPUT);
}

uint16_t SMDjoystick::read(int player) {

	uint16_t data=0;

	switch(player) {
		case 1:
			digitalWrite(select,LOW);
			data+=!digitalRead(a)<<SMD_A;
			data+=!digitalRead(start)<<SMD_START;
			data+=!digitalRead(up)<<SMD_UP;
			data+=!digitalRead(down)<<SMD_DOWN;
			delayMicroseconds(1200);

			digitalWrite(select,HIGH);
			data+=!digitalRead(left)<<SMD_LEFT;
			data+=!digitalRead(right)<<SMD_RIGHT;
			data+=!digitalRead(a)<<SMD_B;
			data+=!digitalRead(start)<<SMD_C;
			digitalWrite(select,LOW);
			delayMicroseconds(1200);

			digitalWrite(select,HIGH);
			digitalWrite(select,LOW);
			digitalWrite(select,HIGH);
			data+=!digitalRead(up)<<SMD_Z;
			data+=!digitalRead(down)<<SMD_Y;
			data+=!digitalRead(left)<<SMD_X;
			data+=!digitalRead(right)<<SMD_MODE;
			digitalWrite(select,LOW);
			digitalWrite(select,HIGH);
		break;

		case 2:
			digitalWrite(select,LOW);
			data+=!digitalRead(a)<<SMD_A;
			data+=!digitalRead(start)<<SMD_START;
			data+=!digitalRead(up)<<SMD_UP;
			data+=!digitalRead(down)<<SMD_DOWN;
			delayMicroseconds(1200);

			digitalWrite(select,HIGH);
			data+=!digitalRead(left)<<SMD_LEFT;
			data+=!digitalRead(right)<<SMD_RIGHT;
			data+=!digitalRead(a)<<SMD_B;
			data+=!digitalRead(start)<<SMD_C;
			digitalWrite(select,LOW);
			delayMicroseconds(1200);

			digitalWrite(select,HIGH);
			digitalWrite(select,LOW);
			digitalWrite(select,HIGH);
			data+=!digitalRead(up)<<SMD_Z;
			data+=!digitalRead(down)<<SMD_Y;
			data+=!digitalRead(left)<<SMD_X;
			data+=!digitalRead(right)<<SMD_MODE;
			digitalWrite(select,LOW);
			digitalWrite(select,HIGH);
		break;
	}
	return data;
}
