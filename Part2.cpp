#include <iostream>
#include <fstream>

int main(){
    
    int Val1 = 0;
    int Val2 = 0;
    int Val3 = 0;
    int prevSum = 0;
    int currSum = 0;
    int numIncrease = 0;

    std::ifstream depths;
    depths.open("day1TextFile");

    if (depths.is_open()){
        std::cout << "is open \n";
        
        depths >> Val1;
        depths >> Val2;
        depths >> Val3;
        prevSum = Val1 + Val2 + Val3;

        while(depths.good()){
            Val1 = Val2;
            Val2 = Val3;
            //Val3 = 0;
            depths >> Val3;
            currSum = Val1 + Val2 + Val3;
            if (currSum > prevSum) {
                ++numIncrease;
            }
            prevSum = currSum; 
        }
    }

    depths.close();

    std::cout << numIncrease << "\n";

    return 0;
}
