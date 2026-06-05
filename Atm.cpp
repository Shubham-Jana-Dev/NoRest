#include <iostream>
#include <string>

void get_name(std::string user_name){
    std::cout<<"Please enter your name: ";
    std::cin>>user_name;
    std::cout<<std::endl;
    std::cout<<"Well come "<<user_name<<std::endl;
}
int main(){
    std::string user;
    get_name(user);
    return 0;
}
