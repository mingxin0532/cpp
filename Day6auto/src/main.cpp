#include "../include/RobotControl.h"
int main(){
	RobotControl robot;
	do{
		robot.Communicate();
	}while(robot.isActive());

	return 0;
}
