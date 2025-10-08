#include <iostream>


unsigned int factorialIter (int n){
	if(n<0){
		std::cout<< "fehler"<<std::endl;
	}
	int result = 1;
	int i;
	for(i=1;i<=n;i++){
		result*=i;
	}
	return result;
}
unsigned int factorialRec (int n){
	if(n<0){
		std::cout << "fehler"<<std::endl;
	}
	int result ;
	if(n==0||n==1){
		return result=1;
	}

	result = n*factorialRec(n-1);
	return result;
}
int main (){
	int test[]={1,2,5};
	for(int n:test){
		std::cout<< n<< std::endl;
		std::cout<< "Interativ:"<< std::endl;
		std::cout<< factorialIter(n)<< std::endl;
		std::cout<< "rekusiv"<< std::endl;
		std::cout<< factorialRec(n)<< std::endl;
		std::cout<< "----------------"<< std::endl;
	}
}
