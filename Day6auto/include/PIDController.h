#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H
class PIDcontroller {
private:
	double dKp;
	double dKi;
	double dKd;
	double dTa;
	double dEsum;
	double deold;
	double dU;
public:
	PIDcontroller();
	PIDcontroller(double Kp,double Ki,double Kd,double Ta);
	~PIDcontroller();
	void CalculateU(double dW,double dY);
	double GetU();


};
#endif
