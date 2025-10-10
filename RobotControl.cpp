#include "../includes/RobotControl.h"

#include <iostream>
#include <ncurses.h>

	RobotControl* RobotControl::transferPointer = nullptr;

	RobotControl::RobotControl():{

	}
	RobotControl::~RobotControl(){

	}
	void RobotControl::transferfunction(){

	}
	bool RobotControl::isActive(){

	}
	void RobotControl::step(){
		double* pInput = interface.GetInput();
		double isVelocity[0] = pInput[0];
		double isVelocity[1] = pInput[1];

		if(maneuver.bIsRunning()==false){
			iMicros[0] = 1500;
			iMicros[1] = 1500;
		}

		else{
			posEstimation.PredictPosition(isVelocity[0], isVelocity[1], 0.04);
			double* A = posEstimation.GetPosition();
			maneuver.CalcManeuverSpeed(A[0] ,A[1], A[2]);
			double* adWishSpeed = maneuver.GetManeuverSpeed();

			sollVelocity[0] = adWishSpeed[0];
			sollVelocity[1] = adWishSpeed[1];

			motorL.CalculateU(sollVelocity[0],isVelocity[0]);
			motorR.CalculateU(sollVelocity[1],isVelocity[1]);

			iMicros[0] = motorL.GetU() + 1500;
			iMicros[1] = motorR.GetU() + 1500;

		}

		for(int i = 0; i<2; ++i){
			if (iMicros[i] > 2000) iMicros[i] = 2000;
				if (iMicros[i] < 1000) iMicros[i] = 1000;
		}

		interface.SetOutputs(iMicros);
		printw("\n Links PWM: %d us \n", iMicros[0]);
		printw("Rechts PWM %d us \n", iMicros[1]);

		printw("\n Links speed: %.3f m/s", isVelocity[0]);
		printw("Rechts speed %.3f m/s", isVelocity[1]);

	}
	void RobotControl::Communicate(){
		if(){

		}else{
			bIsActive = false;
		}
	}
