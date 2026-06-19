//
//  palindrome.cpp
//  
//
//  Created by Shubham Jana on 18/06/26.
// g++ palindrome.cpp -o palindrome && ./palindrome

#include <iostream>
#include <string>
void check_palindrome(){
    std::string variable;
    std::cout << "Please Enter the word or the number: ";
    std::getline(std::cin, variable);
    //std::cin >> variable;
    int count = variable.length();
    std::string reversed_variable;
    for (int i = count-1; i >= 0; i--){
            reversed_variable = reversed_variable + variable[i];
    }
    
    if (variable == reversed_variable){
        std::cout << variable << " is a palindrome."<<std::endl;
    } else{
        std::cout << variable << " is not a palindrome." << std::endl;
    }
    
}
int main(){
    check_palindrome();
    remove("palindrome");
}
