#include <iostream>
#include <string>
//  g++ Atm.cpp -o Atm && ./Atm

std::string get_name(){
    std::string user_name;
    std::cout<<"Please enter your name: ";
    getline(std::cin,user_name);
    return user_name;
}
void wellcome_user(std::string user){
    std::cout<<"Well come "<<user<<std::endl;
}
double get_balance(){
    double balance;
    std::cout<<"Please Enter the Balance: "<<std::endl;
    std::cin>>balance;
    std::cout<<std::endl;
    return balance;
}
void display_bal(double balance_x){
    std::cout<<"Your current Balance is " <<balance_x<<std::endl;
}
int main(){
    std::string user = get_name();
    double bal = get_balance();
    wellcome_user(user);
    
    display_bal(bal);
    return 0;
}
