#include "../include/PIDController.h"

PIDcontroller::PIDcontroller(double Kp,double Ki,double Kd,double Ta)
:dKp(Kp),dKi(Ki),dKd(Kd),dTa(Ta){
	 dEsum=0;
	 deold=0;
	 dU=0;
}

PIDcontroller::~PIDcontroller(){
}
PIDcontroller::PIDcontroller(){}
void PIDcontroller::CalculateU(double dW,double dY){
	double e_k=dW-dY;
	dEsum+= e_k;
	double e_diff = (e_k-deold)/dTa;
	dU = dKp*e_k + dKi*dTa*dEsum + dKd*e_diff;
	deold = e_k;

}

double PIDcontroller::GetU(){
	return dU;
}


