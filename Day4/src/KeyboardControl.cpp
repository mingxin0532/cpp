#include "../includes/KeyboardControl.h"
#include "../includes/InterfaceSIM.h"
#include "../includes/PIDController.h"


#include <ncurses.h>
#include <unistd.h>
#include <iostream>

KeyboardControl* KeyboardControl::transferPointer = nullptr;

KeyboardControl::KeyboardControl():leftPID(500.0, 1850.0, 0.0, 0.004),
			rightPID(500.0, 1850.0, 0.0, 0.004){
	_sollVelocity[0] = 0.0;
	_sollVelocity[1] = 0.0;
	_isVelocity[0] = 0.0;
	_isVelocity[1] = 0.0;
	_iMicros[0] = 0.0;
	_iMicros[1] = 0.0;

	_interface.Initialize(0.04, &transferFunction);
	transferPointer = this;
}


void KeyboardControl::LimmitVelocity(){

	for(int i =0; i<2; ++i){
		if (_sollVelocity[i] > 0.5)
			_sollVelocity[i] = 0.5;
		else if (_sollVelocity[i] < -0.5)
			_sollVelocity[i] = -0.5;
	}
}

int KeyboardControl::SpeedToMicros(double speed){
	if (speed > 0.5) speed = 0.5;
	if (speed < -0.5) speed = -0.5;

	return static_cast<int>(1500 + 1000 * speed);
}

void KeyboardControl::Communicate(){
	sigprocmask(SIG_UNBLOCK, &_interface.mask, nullptr);
	initscr();
	noecho();
	nodelay(stdscr,TRUE);
	curs_set(0);

	bool running = true;
	char lastKey = '\0';

	while(running){
		int ch = getch();

		switch (ch){
		case'w':
			_sollVelocity[0] += 0.1;
			_sollVelocity[1] += 0.1;
			break;

		case's':
			_sollVelocity[0] -= 0.1;
			_sollVelocity[1] -= 0.1;
			break;

		case'a':
			_sollVelocity[0] -= 0.005;
			_sollVelocity[1] += 0.005;
			break;

		case'd':
			_sollVelocity[0] += 0.005;
			_sollVelocity[1] -= 0.005;
			break;

		case'b':
			_sollVelocity[0] = 0.0;
			_sollVelocity[1] = 0.0;
			break;

		case'q':
			_sollVelocity[0] = 0.0;
			_sollVelocity[1] = 0.0;
			running = false;
			break;

		default:
			break;
		}

		LimmitVelocity();

		clear();
		printw("KeyboardControl \n");

		printw("Links cmd: %.3f m/s \n", _sollVelocity[0]);
		printw("Rechts cmd: %.3f m/s \n", _sollVelocity[1]);

		if(ch != ERR)
			lastKey = ch;

		usleep(100000);
	}

	while(_isVelocity[0] != 0.0 || _isVelocity[1] != 0 ){
		clear();
		refresh();
		usleep(200000);
	}


	sigprocmask(SIG_BLOCK, &_interface.mask, nullptr);

	endwin();

}

void KeyboardControl::Step(){
	double* pInput = _interface.GetInput();

	_isVelocity[0] = pInput[0];
	_isVelocity[1] = pInput[1];

	leftPID.CalculateU(_sollVelocity[0],_isVelocity[0]);
	rightPID.CalculateU(_sollVelocity[1],_isVelocity[1]);

//	_iMicros[0] = SpeedToMicros(_sollVelocity[0]);
//	_iMicros[1] = SpeedToMicros(_sollVelocity[1]);

	_iMicros[0] = leftPID.GetU() + 1500;
	_iMicros[1] = rightPID.GetU() + 1500;

	for(int i = 0; i<2; ++i){
		if (_iMicros[i] > 2000) _iMicros[i] = 2000;
			if (_iMicros[i] < 1000) _iMicros[i] = 1000;
	}


	_interface.SetOutputs(_iMicros);
	printw("\n Links PWM: %d us \n", _iMicros[0]);
	printw("Rechts PWM %d us \n", _iMicros[1]);

	printw("\n Links speed: %.3f m/s", _isVelocity[0]);
	printw("Rechts speed %.3f m/s", _isVelocity[1]);
}

void KeyboardControl::transferFunction(){
	transferPointer->Step();
};

