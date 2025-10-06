#include <iostream>
#include <string>

int main(){
	std::string word;
	std::cout << "give a word"<<std::endl;
	std::cin>> word;
	std::cout << "confirm:"<<word<<std::endl;
	int left=0;
	int right=word.size()-1;
	bool isTrue=true;
	while(left<right){
		if(word[left]!=word[right]){
			isTrue=false;
			break;
		}

		left++;
		right--;
	}

	if(isTrue){
		std::cout << "its a palindrome word"<<std::endl;
	}
	else
	{
		std::cout << "its not a palindrome word, pls give a new word"<<std::endl;
	}


}
