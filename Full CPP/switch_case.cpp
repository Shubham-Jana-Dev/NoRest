//  g++ switch_case.cpp -o switch_case && ./switch_case
#include <iostream>

// Problem 1:
void simple_calculater(double num1, double num2, char sign){
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "\nEnter the second number: ";
    std::cin >> num2;
    std::cout << "\nEnter the Operator: ";
    std::cin >> sign;
    std::cout << std::endl;
    switch (sign){
        case '+': std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl; break;
        case '-': std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl; break;
        case '*': std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl; break;
        case '/': std::cout << num1 << " / " << num2 << " = " << num1 / num2 << std::endl; break;
        default: std::cout << "Please Enter a vaild input";
    }
}

// Problem 2
void Grade_Evaluator(int marks){
    std::cout<< "Enter your marks (0 to 100) : ";
    std::cin >> marks;
    for (int i = 0; i<10; i++){
        if (marks%10 != 0){
            marks = marks - 1;
        } else{
            break;
        }
    }
    switch(marks){
        case 100: std::cout << "Excellant." << std::endl;  break;
        case 90: std::cout << "Excellant." << std::endl; break;
        case 80: std::cout << "Good." << std::endl; break;
        case 70: std::cout << "Pass." << std::endl; break;
        case 60: std::cout << "Pass." << std::endl; break;
        default: std::cout << "Fail." << std::endl; break;
        
    }
    
}

// Problem 3:
void Traffic_Signal_Simulator(char light){
    std::cout << "Enter the first letter color of the light ('R','G','Y'): ";
    std::cin >> light;
    light = (char)toupper(light);
    switch (light){
        case 'G': std::cout << "Go!" << std::endl; break;
        case 'Y': std::cout << "Prepare to clear intersection!" << std::endl; break;
        case 'R': std::cout << "Stop!"<<std::endl; break;
        default: std::cout<<"Please enter a valid input."<< std::endl; break;
    }
}

int main(){
    double a;
    double b;
    char c;
    simple_calculater(a,b,c);
    Grade_Evaluator(a);
    Traffic_Signal_Simulator(c);
    remove("switch_case");
    return 0;
}
