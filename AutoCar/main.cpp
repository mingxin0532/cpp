#include "PosEstimation.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::string filename = "PosEstimationInput.txt";
	std::ifstream infile;
	infile.open(filename);
	if (!infile.is_open()) {
		std::cout << "ERROR" << std::endl;
	}
	PosEstimation Estimation;
	double SpeedR;
	double SpeedL;
	double T;

	while (infile >> SpeedR >> SpeedL>> T) {
		Estimation.PredictPosition(SpeedR,SpeedL,T);

		double *result = Estimation.GetPosition();
		std::cout << "SpeedR:" << result[0]<< "  SpeedL:" << result[1] <<"  Winkel:" << result[2]<<std::endl;
	}
	infile.close();

	return 0;
}
