/*
 * Maneuver.h
 *
 *  Created on: 10.10.2025
 *      Author: pi
 */

#ifndef MANEUVER_H_
#define MANEUVER_H_

#include <string>
#include <list>
#include <cmath>
#include <iostream>
#include <fstream>

struct Coord{
	double dX;
	double dY;
	double dV;
};

class Maneuver{
	std::list <Coord> Coordlist;
	std::list <Coord>::iterator iter;
	bool bIsRunning;
	double adWishSpeed[2];
	double dMaxSpeed;
	double dPosDifference;

public:
	Maneuver();

	void CalcCircle(double Radius, double speed, double dt);

	void CalcEight(double Radius, double speed, double dt);

	void LogList(std::string sDatei);

	bool isRunning();

	void Start();

	void Stop();

	void Proceed();

	void CalcManeuverSpeed(double dX, double dY, double dW);

	double* GetManeuverSpeed();
};



#endif /* MANEUVER_H_ */
