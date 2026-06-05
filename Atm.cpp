#include <iostream>
#include <string>

std::string get_name(){
    std::string user_name;
    std::cout<<"Please enter your name: ";
    getline(std::cin,user_name);
    return user_name;
}
void wellcome_user(std::string user){
    std::cout<<"Well come "<<user<<std::endl;
}
int main(){
    std::string user = get_name();
    wellcome_user(user);
    return 0;
}
