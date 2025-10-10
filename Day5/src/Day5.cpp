//============================================================================
// Name        : Day5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../includes/Maneuver.h"

using namespace std;

int main() {

	Maneuver robotManeuver;

	double R_circle = 2.0;
	double v_circle = 0.3;
	double dt_circle = 0.04;

	std::string fileCircle = "LogFileCircle.txt";

	robotManeuver.CalcCircle(R_circle, v_circle, dt_circle);
	robotManeuver.LogList(fileCircle);

	std::string file8 = "LogFileEight.txt";

	double R_8 = 5.0;
	double v_8 = 1.0;
	double dt_8 = 10;

	robotManeuver.CalcEight(R_8,v_8,dt_8);
	robotManeuver.LogList(file8);

	return 0;
}
