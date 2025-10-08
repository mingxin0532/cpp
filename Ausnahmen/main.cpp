#include <iostream>
#include <fstream>
#include <string>
#include <exception>

class nofileException : public std::exception{
public:
	virtual const char* what() const noexcept override{
		return "Die Datei existiert nicht";
	}
};

void read_file(std::string filename){
	std::ifstream file(filename);
	if(!file.is_open()){
		throw nofileException();
	}
		std::cout<<"file:"<<filename<<"as follow:"<<std::endl;
		std::string line;
		
		while(std::getline(file,line)){
		std::cout<<line<<std::endl;
		}
		std::cout<<"------"<<std::endl;
		file.close();

}

void write_file(std::string filename){
	std::ofstream file(filename,std::ios::app);
	if(file.is_open()){

		std::cout<<"give your input:('exit' to end)"<<std::endl;
		std::string inputline;
		while(std::getline(std::cin,inputline)){
		if(inputline=="exit"){
		break;
		}
		file<<inputline<<std::endl;
		}
		file.close();
	}

}

int main(){
std::cout<<"--give filename pls--"<<std::endl;
std::string filename;
std::getline(std::cin,filename);

try{
	std::cout<<"read data:"<<std::endl;
	read_file(filename);
}
catch(const std::exception& e){
	std::cerr<<"there is a mistake!"<<std::endl;
	std::cerr<<e.what()<<std::endl;
}

//std::cout<<"--read file--"<<std::endl;
//read_file(filename);
//write_file(filename);

//std::cout<<"--check file--"<<std::endl;
//read_file(filename);

return 0;
}

