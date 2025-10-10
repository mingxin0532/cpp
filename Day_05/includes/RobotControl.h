#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H
#include "InterfaceSIM.h"
#include "Maneuver.h"
#include "PosEstimation.h"
#include "PIDController.h"


class RobotControl {
private:
	InterfaceSIM interface;
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
