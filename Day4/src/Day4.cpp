//============================================================================
// Name        : Day4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

#include "../includes/KeyboardControl.h"
#include "../includes/PIDController.h"


int main() {
	KeyboardControl controller;
	controller.Communicate();

//	PIDController pidController(1000, 10, 0.1, 0.5);
//
//	std::ifstream inputFile("../PIDControllerInput.txt");
//	double desiredValue, realValue;
//
//	while (inputFile>>desiredValue>>realValue){
//		pidController.CalculateU(desiredValue, realValue);
//		double u = pidController.GetU();
//		std::cout << u <<std::endl;
//	}
//
//	inputFile.close();
	return 0;
}
