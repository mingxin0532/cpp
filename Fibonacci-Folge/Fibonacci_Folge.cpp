#include<iostream>
unsigned long long fibonacci(int n){
	if(n<0){
		std::cout<< "fehler"<<std::endl;
		return 0;
	}
	if(n==2||n==1){
		return 1;
	}
	return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
	std::cout<<"give a number:"<<std::endl;
	int n;
	std::cin>>n;
	std::cout<<"result:"<<fibonacci(n)<<std::endl;
	std::cout<<"first 15 result:"<<std::endl;
	for(int i=1;i<=15;i++){
		std::cout<<"result of:"<<n<<" is: "<<fibonacci(i)<<std::endl;
	}
}
