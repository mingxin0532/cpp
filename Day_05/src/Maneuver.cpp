/*
 * Maneuver.cpp
 *
 *  Created on: 10.10.2025
 *      Author: pi
 */

#include "../includes/Maneuver.h"

Maneuver::Maneuver():
	bIsRunning(false),
	dMaxSpeed(0.5),
	dPosDifference(0.0)
{
	adWishSpeed[0]= 0.0;
	adWishSpeed[1]= 0.0;
}

void Maneuver::CalcCircle(double Radius, double speed, double dt){
	Coordlist.clear();

//	double T = 2.0 * M_PI * Radius / speed;
//	int num_counter = static_cast<int> (T/dt);

	for (int counter = 1; counter < (int)((2*M_PI)/((speed/Radius)*dt)); ++counter){
		Coord point;
		point.dX = Radius * std::sin(counter * speed/Radius * dt);
		point.dY = Radius * (1 - std::cos(counter * speed/Radius * dt));
		point.dV = speed;

		Coordlist.push_back(point);
	}
}

void Maneuver::CalcEight(double Radius, double speed, double dt){
	Coordlist.clear();

//	double T = 2.0 * M_PI * Radius / speed;
//	int num_counter = static_cast<int> (T/dt);

	for (int counter = 1; counter < (int)((2*M_PI)/((speed/Radius)*dt)); ++counter){
		Coord point;
		point.dX = Radius * std::sin(counter * speed/Radius * dt);
		point.dY = Radius * (1 - std::cos(counter * speed/Radius * dt));
		point.dV = speed;

		Coordlist.push_back(point);
	}


	for (int counter = 1; counter < (int)((2*M_PI)/((speed/Radius)*dt)); ++counter){
		Coord point;
		point.dX = Radius * std::sin(counter * speed/Radius * dt);
		point.dY = - Radius * (1 - std::cos(counter * speed/Radius * dt));
		point.dV = speed;

		Coordlist.push_back(point);
	}
}
bool Maneuver::isRunning(){
	return bIsRunning;
}

void Maneuver::Stop(){
	bIsRunning = false;
}

void Maneuver::Start(){
	if(!Coordlist.empty()){

	iter = Coordlist.begin();
	bIsRunning = true;
	}else{
	bIsRunning = false;
	}

}

void Maneuver::Proceed(){
	bIsRunning = true;
}
void Maneuver::LogList(std::string sDatei){
	std::ofstream LogFile(sDatei);

	if(LogFile.is_open()){

		for(const auto& coord : Coordlist){
			LogFile<< coord.dX <<"\t"<<coord.dY<<"\n";
		}
		LogFile.close();
		std::cout<< sDatei << "\tData logged"<<std::endl;
	}
	else{
		std::cout<< "Unable to open file"<< sDatei<<std::endl;
	}
}



