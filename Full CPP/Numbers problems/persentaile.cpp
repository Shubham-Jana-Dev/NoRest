//
// g++ -std=c++17  persentaile.cpp -o persentaile.exe && ./persentaile.exe
//
//
//  Created by Shubham Jana on 01/07/26.
//
#include <iostream>
#include <vector>
class statics{
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
    int persentaile_calculation(const std::vector<int>& array, int num){
        int count = 0;
        for (int i : array){
            if ( j < num){
                count ++;
            }
        }
        int persentaile = (count/(array.size())) * 100;
        return persentaile;
    }
    std::vector <int> Sort_array(std::vector<int> theArray){
        aSize = theArray.size();
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
    
    return 0;
}
