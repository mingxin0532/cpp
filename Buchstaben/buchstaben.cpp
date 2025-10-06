#include <iostream>
#include <string>

std::string changeAlphabet (std::string word){
	char temp;
	for(int i=1; i< word.size()-2;i+=2){
		temp = word[i];
		word[i] = word[i+1];
		word[i+1] = temp;
	}
	return word;
}

std::string deletevokale (std::string word){
	std::string deletedword;
	for(int i=0; i<word.size();i++){
		if(word[i] != 'a' && word[i] != 'e'  && word[i] != 'i'  && word[i] != 'o'  && word[i] != 'u'){
			deletedword += word[i];
		}
	}
	return deletedword;
	}

int main(){
	std::string word;
	std::cout << "give a word"<<std::endl;
	std::cin>> word;
	std::cout << "confirm:"<<word<<std::endl;

	std::string changeword = changeAlphabet(word);
	std::cout << "output of changeAlphabet is:"<<changeword<<std::endl;

	std::string deleteword = deletevokale(word);
	std::cout << "output of deletevokale is::"<<deleteword<<std::endl;

	return 0;

}
