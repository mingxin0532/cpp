//============================================================================
// Name        : SpeicherUndArrays.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style


//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	int m = 0, n = 100;

	srand(time(nullptr));

	int* a = new int[100000];
	int count = 0;

	std::cout<<"100,000 random number from 0 to 100"<<std::endl;

	for(int i=0; i<10000; i++){
		a[i] = rand()%n + m;
		if(a[i]%3 == 0)
			++count;
	}

	std::cout<<"the amount of number which are evenly divisible by 13;"<<std::endl;
	std::cout<<count<<std::endl;


	delete[] a;
	return 0;
}
