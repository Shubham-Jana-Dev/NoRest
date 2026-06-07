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
    std::cout<<"Please Enter the Balance: ";
    std::cin>>balance;
    std::cout<<std::endl;
    return balance;
}
void display_bal(double balance_x){
    std::cout<<"Your current Balance is " << balance_x <<std::endl;
}
double withdrawal(double c_bal){
    double amount;
    std::cout<<"Enter the amount of withdrawal: ";
    std::cin>>amount;
    std::cout<<std::endl;
    double final_balance = c_bal - amount;
    return final_balance;
}
void display_final_balance(double f_bal){
    std::cout<<"Your final balance is "<<f_bal<<std::endl;
}

void ask_for_request(double curent_bal){
    std::cout<<"Press 1 for amount withdrawal: ";
    int ask;
    std::cin>>ask;
    std::cout<<std::endl;
    if(ask == 1){
        double final_bal = withdrawal(curent_bal);
        display_final_balance(final_bal);
    }
    else{
        std::cout<<"Please chose a valid option.";
    }
}
int main(){
    
    std::string user = get_name();
    
    double bal = get_balance();
    
    wellcome_user(user);
    
    display_bal(bal);
    
    ask_for_request(bal);
    
    return 0;
}
