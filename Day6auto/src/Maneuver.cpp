/*
 * Maneuver.cpp
 *
 *  Created on: 10.10.2025
 *      Author: pi
 */

#include "../include/Maneuver.h"
#include <fstream>


Maneuver::Maneuver() :
		bIsRunning(false), dMaxSpeed(0.5), dPosDifference(0.0) {
	adWishSpeed[0] = 0.0;
	adWishSpeed[1] = 0.0;
}

void Maneuver::CalcCircle(double Radius, double speed, double dt) {
	Coordlist.clear();

//	double T = 2.0 * M_PI * Radius / speed;
//	int num_counter = static_cast<int> (T/dt);

	for (int counter = 1;
			counter < (int) ((2 * M_PI) / ((speed / Radius) * dt)); ++counter) {
		Coord point;
		point.dX = Radius * std::sin(counter * speed / Radius * dt);
		point.dY = Radius * (1 - std::cos(counter * speed / Radius * dt));
		point.dV = speed;

		Coordlist.push_back(point);
	}
}

void Maneuver::CalcEight(double Radius, double speed, double dt) {
	Coordlist.clear();

//	double T = 2.0 * M_PI * Radius / speed;
//	int num_counter = static_cast<int> (T/dt);

	for (int counter = 1;
			counter < (int) ((2 * M_PI) / ((speed / Radius) * dt)); ++counter) {
		Coord point;
		point.dX = Radius * std::sin(counter * speed / Radius * dt);
		point.dY = Radius * (1 - std::cos(counter * speed / Radius * dt));
		point.dV = speed;

		Coordlist.push_back(point);
	}

	for (int counter = 1;
			counter < (int) ((2 * M_PI) / ((speed / Radius) * dt)); ++counter) {
		Coord point;
		point.dX = Radius * std::sin(counter * speed / Radius * dt);
		point.dY = -Radius * (1 - std::cos(counter * speed / Radius * dt));
		point.dV = speed;

		Coordlist.push_back(point);
	}
}
bool Maneuver::isRunning() {
	return bIsRunning;
}

void Maneuver::Stop() {
	bIsRunning = false;
}

void Maneuver::Start() {
	iter = Coordlist.begin();
	bIsRunning = true;
}

void Maneuver::Proceed() {
	bIsRunning = true;
}
void Maneuver::LogList(std::string sDatei) {
	std::ofstream LogFile(sDatei);

	if (LogFile.is_open()) {

		for (const Coord& coord : Coordlist) {
			LogFile << coord.dX << "\t" << coord.dY << "\n";
		}
		LogFile.close();
		std::cout << sDatei << "\tData logged" << std::endl;
	} else {
		std::cout << "Unable to open file" << sDatei << std::endl;
	}
}

void Maneuver::CalcManeuverSpeed(double dX, double dY, double dW) {

	double x_akt = dX;
	double y_akt = dY;
	double w_akt = dW;

	double x_soll = iter->dX;
	double y_soll = iter->dY;

	double e_x = x_soll - x_akt;
	double e_y = y_soll - y_akt;

	dPosDifference = sqrt(e_x * e_x + e_y * e_y);

	//1.
	if (dPosDifference < 0.04) {
		iter++;
	}
	if (iter == Coordlist.end()) {
		Stop();
	} else {

		//3.
		double phi = std::atan2(e_y, e_x);
		//4.
		double e_phi = phi - w_akt;
		//5.
		while (e_phi > M_PI) {
			e_phi -= 2.0 * M_PI;
		}
		while (e_phi <= -M_PI) {
			e_phi += 2.0 * M_PI;
		}
		//6.
		int factor = 2;
		double dRot = e_phi * factor;

		if (dRot > 0.5)
			dRot = 0.5;
		if (dRot < -0.5)
			dRot = -0.5;

		//7.
		double dTra = iter->dV;

		//8.
		if (dTra * dRot > 0.0) {
			if (dTra + dRot > dMaxSpeed) {
				dTra = dMaxSpeed - dRot;
			}
			if (dTra + dRot < -dMaxSpeed) {
				dTra = -dMaxSpeed - dRot;
			}
		} else if (dTra * dRot < 0.0) {
			if (dTra - dRot > dMaxSpeed) {
				dTra = dMaxSpeed + dRot;
			}
			if (dTra - dRot < -dMaxSpeed) {
				dTra = -dMaxSpeed + dRot;
			}
		}

		//9.
		adWishSpeed[0] = dTra + dRot;
		adWishSpeed[1] = dTra - dRot;
	}
}

double* Maneuver::GetManeuverSpeed() {
	return adWishSpeed;
}

