//
//  g++ -std=c++17 factorial.cpp -o factorial.exe && ./factorial.exe
//
//
//  Created by Shubham Jana on 01/07/26.
//
#include <iostream>
class calculate{
public:
    int get_num(){
        int num = 0;
        std::cout << "Enter the number: ";
        std::cin >> num;
        return num;
    }
    int factorial_calculation(int num){
        if(num<=1){
            return num;
        }
        return num * factorial_calculation(num - 1);
    }
};
int main(){
    calculate f1;
    int n = f1.get_num();
    std::cout <<"The factorial of " << n <<" is: " << f1.factorial_calculation(n) << std::endl;
}

