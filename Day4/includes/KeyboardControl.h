#ifndef KEYBOARD_CONTROL_H
#define KEYBOARD_CONTROL_H
#include "InterfaceSIM.h"
#include "PIDController.h"


class KeyboardControl{
	double _sollVelocity[2];
	double _isVelocity[2];
	InterfaceSIM _interface;
	int _iMicros[2];
	PIDController leftPID,rightPID;


public:
	static KeyboardControl* transferPointer;

	KeyboardControl();

	void Communicate();
	void Step();
	void LimmitVelocity();
	int SpeedToMicros(double speed);
	static void transferFunction();
};

#endif
