#include <iostream>
#include<cstdlib>
#include<ctime>

void bubblesort(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

			}

		}
	}
}

void printa(int* arr, int size){
	for (int i = 0; i < size - 1; i++){
		std::cout<< arr[i]<<" "<<std::endl;
	}
}

int main() {
	const int size = 32;

	int m = 0, n = 100;
	srand(time(nullptr));
	int *a = new int[size];
	for(int i=0;i<size;i++){
		a[i]=rand()%n+m;


	}

	std::cout<< "raw data is:"<<std::endl;
	printa(a,size);

	bubblesort(a,size);
	std::cout<< "sortied data is:"<<std::endl;
	printa(a,size);

return 0;
}
