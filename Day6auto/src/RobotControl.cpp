#include "../include/RobotControl.h"

#include <iostream>
#include <ncurses/ncurses.h>

	RobotControl* RobotControl::transferPointer ;

	RobotControl::RobotControl():motorR(500,1850,0,0.04),motorL(500,1850,0,0.04){
		interface.Initialize(0.04);
		interface.SetTimerfunction(0, 0.04, &transferfunction);
		transferPointer = this;

		bIsActive = false;
	}
	RobotControl::~RobotControl(){

	}
	void RobotControl::transferfunction(){
		transferPointer->step();
	}
	bool RobotControl::isActive(){
		return bIsActive;
	}
	void RobotControl::step(){

			double* pInput = interface.GetInput();
			isVelocity[0] = pInput[0];
			isVelocity[1] = pInput[1];

			if(maneuver.isRunning()==false){
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
			//printw("\n Links PWM: %d us \n", iMicros[0]);
			//printw("Rechts PWM %d us \n", iMicros[1]);

			//printw("\n Links speed: %.3f m/s", isVelocity[0]);
		//	printw("Rechts speed %.3f m/s", isVelocity[1]);

		}
	void RobotControl::Communicate(){
		//get parameter
		double radius,speed;
		char maneuverType;
		std::cout << "give the radius pls:"<<std::endl;
		std::cin>>radius;
		std::cout << "give the speed pls:"<<std::endl;
		std::cin>>speed;
		std::cout << "give the maneuverType pls('C' for circle, 'E' for eight):"<<std::endl;
		std::cin>>maneuverType;
		//create maneuver
		if(maneuverType=='C'||maneuverType=='c'){
			maneuver.CalcCircle(radius,speed,0.04);
		}else if(maneuverType=='E'||maneuverType=='e'){
			maneuver.CalcEight(radius,speed,0.04);
		}else{
			std::cout << "unavailable input, "<<std::endl;
		}
		//reset position
//		sigprocmask(SIG_UNBLOCK,&interface.mask,nullptr);
		//get parameter
		posEstimation.Reset();
		//start ncurses
		initscr();
		nodelay(stdscr,TRUE);
		noecho();
		curs_set(0);

		//manuver control
		bool quitLoop = false;
		while(!quitLoop){

			mvprintw(0,0,"s-start; p-stop; o-proceed; q-quit");
			mvprintw(2,0,"Status:%s",maneuver.isRunning()? "works":"stop" );
			refresh();

			int key = getch();
			switch(key){
			case 's':
				maneuver.Start();
				break;
			case 'p':
				maneuver.Stop();
				break;
			case 'o':
				maneuver.Proceed();
				break;
			case 'q':
				maneuver.Stop();
				quitLoop=true;
				break;
			}
		}
		endwin();
//		sigprocmask(SIG_BLOCK,&interface.mask,nullptr);
	}
