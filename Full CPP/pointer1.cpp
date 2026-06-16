//
//  pointer1.cpp
//  
//
//  Created by Shubham Jana on 16/06/26.
//
#include <iostream>
void understanding_pointers(){
    std::string name = "Shubham";
    std::string *Pname = &name;
    std::cout << *Pname << std::endl;
    
    int age = 19;
    int *page = &age;
    std::cout << *page << std::endl;
}
void remove_exe(){
    remove("pointer1");
}
int main(){
    understanding_pointers();
    remove_exe();
    return 0;
}
