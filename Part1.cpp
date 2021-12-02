#include <iostream>
#include <fstream>

int main(){
    
    int prevVal = 0;
    int currVal = 0;
    int numIncrease = 0;

    std::ifstream depths;
    depths.open("day1TextFile");

    if (depths.is_open()){
        std::cout << "is open \n";
        while(depths.good()){
            depths >> currVal;
            if (currVal > prevVal){
                numIncrease++;
            }
            prevVal = currVal;
        }
    }

    std::cout << numIncrease - 1 << "\n";

    return 0;
}