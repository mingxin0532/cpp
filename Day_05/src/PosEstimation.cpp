#include "../includes/PosEstimation.h"
#include <cmath>

PosEstimation::PosEstimation(){
	Reset();
}
PosEstimation::~PosEstimation(){}

void PosEstimation::Reset(){
	x[0]=0.0;
	x[1]=0.0;
	x[2]=0.0;
	dVelAverage=0.0;
}

void PosEstimation::PredictPosition(double dSpeedR,double dSpeedL,double dTimestep){
	double sin(double x);
	double cos(double x);
	x[0] += dVelAverage*dTimestep*cos(x[2]);
	x[1] += dVelAverage*dTimestep*sin(x[2]);

	double winkle;
	winkle =  x[2]+dTimestep*((dSpeedR-dSpeedL)/0.23);
	winkle = fmod(winkle,2*M_PI);
	if(winkle>M_PI){
		winkle-=2.0*M_PI;
	}else if(winkle< -M_PI){
		winkle+=2.0*M_PI;
	}
	x[2]=winkle;
	dVelAverage = (dSpeedR+dSpeedL)/2;
}
double* PosEstimation::GetPosition(){
	return x;
}
