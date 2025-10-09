#include "../includes/PIDController.h"

PIDController::PIDController(double Kp, double Ki, double Kd, double Ta){
		dKp = Kp;
		dKi = Ki;
		dKd = Kd;
		dTa = Ta;
		dEsum = 0.0;
		deold = 0.0;
		dU = 0.0;
};

void PIDController::CalculateU(double dW, double dY){
	double e = dW - dY;
	dEsum += e;

	dU = dKp * e + dKi * dTa * dEsum + dKd * (e - deold)/dTa;

	deold = e;

}

double PIDController::GetU(){
	return dU;
}
