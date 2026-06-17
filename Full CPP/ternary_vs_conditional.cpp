#include <iostream>
//  g++ ternary_vs_conditional.cpp -o ternary_vs_conditional && ./ternary_vs_conditional

void standard_conditional(int num1, int num2){
    if (num1>num2){
        std::cout<<num1<<" the greater."<<std::endl;
    } else {
        std::cout<< num2 <<" the greater."<<std::endl;
    }
}
void ternary_conditional(int num1, int num2 ){
    (num1 > num2) ? std::cout << num1 <<" is greater."<<std::endl : std::cout << num2 <<" is greater."<<std::endl;
}
void swap(float &num1, float &num2){
    std::cout << "first number = " << num1 <<std::endl;
    std::cout << "second number = " << num2 << std::endl;
    
    float temp;
    temp = num2;
    num2 = num1;
    num1 = temp;
    std::cout << "first number = " << num1 <<std::endl;
    std::cout << "second number = " << num2 << std::endl;
}
int main(){
    int a = 20;
    int b = 50;
    standard_conditional(a,b);
    ternary_conditional(a,b);
    
    float a1 = 100;
    float b2 = 300;
    swap(a1,b2);
    std::cout << "a1 = "<< a1 << std::endl;
    std::cout << "b2 = "<< b2 << std::endl;
    remove("ternary_vs_conditional");
    return 0;
}

