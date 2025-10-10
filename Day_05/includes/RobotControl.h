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
