#include <iostream>

int main(){
	double a ,b;
	char op;
	
	std::cout<<"Taschenrechner starten"<< std::endl;
	
	std::cout<<"please give the fist number"<<std::endl;
	std::cin>>a;
	
	std::cout<<"please give the operater(+ - * /)"<<std::endl;
	std::cin>>op;

	std::cout<<"please give the second number"<<std::endl;
	std::cin>>b;
	
	switch(op){
		case '+':
			std::cout<<"the result is"<<"\t"<<a+b<<std::endl;
			break;
			
		case '-':
			std::cout<<"the result is"<<"\t"<<a-b<<std::endl;
			break;
			
		case '*':
			std::cout<<"the result is"<<"\t"<<a*b<<std::endl;
			break;
			
		case '/':
		
			if(b==0)
				std::cout<<"cannot be 0"<<std::endl;
			else
				std::cout<<"the result is:"<<"\t"<<a/b<<std::endl;
			break;
		default:
				std::cout<<"not available operater"<<std::endl;
			
	};
	
	return 0;
}
