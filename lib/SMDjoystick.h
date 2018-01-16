#ifndef _SMDJOYSTICK_H_
#define _SMDJOYSTICK_H_
#include <Arduino.h>
/**
SegaMegaDrive gamepad arduino library by AsGreyWolf
**/

enum {
	SMD_A=0,
	SMD_B,
	SMD_C,
	SMD_X,
	SMD_Y,
	SMD_Z,
	SMD_UP,
	SMD_DOWN,
	SMD_LEFT,
	SMD_RIGHT,
	SMD_START,
	SMD_MODE
};

class SMDjoystick {

	public:
		SMDjoystick(int upPin,int downPin,int leftPin,int rightPin,int aPin,int selectPin,int startPin);
		uint16_t read(int player);
	private:
		int up;
		int down;
		int left;
		int right;
		int a;
		int select;
		int start;
};

#endif
