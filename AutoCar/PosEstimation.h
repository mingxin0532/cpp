#ifndef POSESTIMATION_H
#define POSESTIMATION_H

class PosEstimation{
private:
	double x[3];
	double dVelAverage;
public:
	PosEstimation();
	~PosEstimation();
	void Reset();
	void PredictPosition(double dSpeedR,double dSpeedL,double dTimestep);
	double* GetPosition();
};

#endif
