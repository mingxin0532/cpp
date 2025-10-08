#include<iostream>
#include<list>
#include<random>
#include<iomanip>

struct coord{
	float x;
	float y;
	coord(float init_x,float init_y):x(init_x),y(init_y){}
};

void printlist(const std::list<coord>* list_ptr){
	std::cout<<std::fixed<<std::setprecision(1);
	for(const auto& c:*list_ptr){
		std::cout<<"X:"<<c.x<<",Y:"<<c.y<<std::endl;
	}

}
void delcoords(std::list<coord>* coord_list){

	auto it=coord_list->begin();
	while(it!=coord_list->end()){
		if(it->x <it->y){
			it=coord_list->erase(it);
		}else{
			it++;
		}
	}
}

int main(){

std::list<coord> my_list;
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<float> dis(0.0f,10.0f);

for(int i=0;i<10;i++){
	float rand_x =dis(gen);
	float rand_y =dis(gen);
	my_list.push_back(coord(rand_x,rand_y));
}
std::cout<< "--- list ---"<<std::endl;
printlist(&my_list);

std::list<coord> my_list_raw=my_list;
std::cout<< "---changed list ---"<<std::endl;
delcoords(&my_list);
printlist(&my_list);


return 0;


}
