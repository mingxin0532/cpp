#include <iostream>

int main(){
	int a;
	std::cout<<"please give a number"<<std::endl;
	std::cin>>a;

	if(a==0){
		std::cout<<"<<Zahl in Zehnersystem:"<<"\t"<<a<<std::endl;
		std::cout<<"<<Zahl in Zwanzigersystem:	0"<<std::endl;
	}

	std::string zwanzig = "";
	int zahl =a;

	while (zahl>0){
		int rest = zahl%20;
		char zeichen;

		if (rest<10)
			zeichen='0'+rest;
		else
			zeichen='A'+(rest-10);

		zwanzig = zeichen + zwanzig;
		zahl /=20;
	}

	std::cout<<"<<Zahl in Zehnersystem:"<<"\t"<<a<<std::endl;
	std::cout<<"<<Zahl in Zwanzigersystem:"<<"\t"<<zwanzig<<std::endl;

	return 0;
}
