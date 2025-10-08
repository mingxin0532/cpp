#include <iostream>
#include <fstream>
#include <string>

void read_file(std::string filename){
	std::ifstream file(filename);
	if(file.is_open()){
		std::cout<<"file:"<<filename<<"as follow:"<<std::endl;
		std::string line;
		
		while(std::getline(file,line)){
		std::cout<<line<<std::endl;
		}
		std::cout<<"------"<<std::endl;
		file.close();
	}
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
std::cout<<"--read file--"<<std::endl;
read_file(filename);
write_file(filename);

std::cout<<"--check file--"<<std::endl;
read_file(filename);

return 0;
}

