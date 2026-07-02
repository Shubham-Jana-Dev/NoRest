//
// g++ -std=c++17  persentaile.cpp -o persentaile.exe && ./persentaile.exe
//
//
//  Created by Shubham Jana on 01/07/26.
//
#include <iostream>
#include <vector>
class statics{
public:
    std::vector<int> theArrayCreation(){
        std::vector<int> myArray = { };
        int sizeOfArray = 0;
        std::cout << "Enter the size of the array: ";
        std::cin >> sizeOfArray;
        for (int i = 0; i < sizeOfArray; i++){
            int arrayElement = 0;
            std::cout << "Enter the element: ";
            std::cin >> arrayElement;
            myArray.push_back(arrayElement);
        }
        return myArray;
       
    }
    double persentaile_calculation(const std::vector<int>& array){
        if (array.empty()) return 0.0;
        double num = 0;
        std::cout << "Enter the score: ";
        std::cin >> num;
        int count = 0;
        for (int i : array){
            if ( i < num){
                count ++;
            }
        }
         return (count*100.0)/(array.size());
    }
    std::vector <int> Sort_array(std::vector<int> theArray){
        int aSize = theArray.size();
        int temp = 0;
        for (int i = 0; i<aSize; i++){
            for(int j = i+1; j <aSize; j++){
                if(theArray[i] > theArray[j]){
                    temp = theArray[i];
                    theArray[i] = theArray[j];
                    theArray[j] = temp;
                }
            }
        }
        return theArray;
    }
};
int main() {
    statics s1;
    std::vector<int> usersArray = s1.theArrayCreation();
    std::vector<int> sortedArray = s1.Sort_array(usersArray);
    double percentile = s1.persentaile_calculation(sortedArray);
    std::cout << "the percentile of the given dataset is " << percentile << std::endl;
    return 0;
}
