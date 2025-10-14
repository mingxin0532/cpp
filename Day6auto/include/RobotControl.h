#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H
#include "../include/InterfaceHW.h"
#include "../include/Maneuver.h"
#include "../include/PIDController.h"
#include "../include/PosEstimation.h"


class RobotControl {
private:
	InterfaceHW interface;
	Maneuver maneuver;
	PosEstimation posEstimation;
	PIDcontroller motorR;
	PIDcontroller motorL;

	int iMicros[2];
	double sollVelocity[2];
	double isVelocity[2];

	bool bIsActive;
public:
	static RobotControl* transferPointer;
	RobotControl();
	~RobotControl();
	static void transferfunction();
	bool isActive();
	void step();
	void Communicate();


};

#endif
