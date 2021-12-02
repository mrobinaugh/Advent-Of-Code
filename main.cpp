#include <iostream>
#include <fstream>
#include <string>


int main(){
    
    int Val1 = 0;
    int Val2 = 0;
    int Val3 = 0;
    int prevVal = 0;
    int currVal = 0;
    int numIncrease = 0;
    int i = 0;

    std::ifstream depths;
    depths.open("day1TextFile");

    if (depths.is_open()){
        std::cout << "is open \n";
        depths >> currVal;
        Val1 = currVal;
        ++i;
        depths >> currVal;
        Val1 += currVal;
        Val2 += currVal;
        ++i;
        depths >> currVal;
        Val1 += currVal;
        Val2 += currVal;
        Val3 += currVal;
        ++i;
        while(depths.good()){
            depths >> currVal;
            if ((i % 3) == 0) {
                if (Val1 > prevVal){
                    numIncrease++;
                }
                prevVal = Val1;
                Val1 = currVal;
                Val2 += currVal;
                Val3 += currVal;
                ++i;
            } else if ((i-1) % 3 == 0){
                if (Val2 > prevVal){
                    numIncrease++;
                }
                prevVal = Val2;
                Val1 += currVal;
                Val2 = currVal;
                Val3 += currVal;
                ++i;
            } else {
                if (Val3 > prevVal){
                    numIncrease++;
                }
                prevVal = Val3;
                Val1 += currVal;
                Val2 += currVal;
                Val3 = currVal;
                ++i;
            }
        }
    }

    std::cout << numIncrease - 1 << "\n";

    return 0;
}

int countIncreasing(){
    int prevVal = 0;
    int currVal = 0;
    int numIncrease = 0;

    std::ifstream depths;
    depths.open("day1TextFile.txt");

    if (depths.is_open()){
        while(depths.good()){
            depths >> currVal;
            if (currVal > prevVal){
                numIncrease++;
            }
        }
    }

    return numIncrease;
}