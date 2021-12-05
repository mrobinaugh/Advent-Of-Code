#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

void part1(){
    std::ifstream bingo;
    bingo.open("inputDay4.txt");

    std::string currNumber;

    std::vector<int> numbers= {};
    std::vector<int> board = {};
    std::vector<int> solvedPos = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    bool goodValueRow = true;
    bool goodValueColumn = true;

    int sumUnmarked = 0;

    std::vector<int> fastest = {100, 0};

    if (bingo.is_open()){
        for (int i=0; i<100; ++i){
            std::getline(bingo, currNumber, ',');
            numbers.push_back(stoi(currNumber));
        }
        std::getline(bingo, currNumber, '\n');
        while(bingo.good()){
            while (board.size() < 25){
                bingo >> currNumber;
                board.push_back(stoi(currNumber));            
            }
            for (int i=0; i<100; ++i){
                for (int j=0; j<25; ++j){
                    if (board[j] == numbers[i]){
                        solvedPos[j] = 1;
                        for (int k=0; k<5; ++k){
                            if (solvedPos[(j - j%5)+k]== 1){
                                goodValueRow = true;
                            } else{
                                goodValueRow = false;
                                k = 5;
                            }
                        }
                        for (int k=0; k<5; ++k){
                            if (solvedPos[(j%5)+k*5] == 1){
                                goodValueColumn = true;
                            } else{
                                goodValueColumn = false;
                                k = 5;
                            }
                        }
                        if (goodValueColumn || goodValueRow){
                            for (int k=0; k<25; ++k){
                                if(solvedPos[k] == 0){
                                    sumUnmarked += board[k];
                                }
                            }
                            j = 25;
                            if (i < fastest[0]){
                                fastest[0] = i;
                                fastest[1] = sumUnmarked;
                            }
                            solvedPos = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                            sumUnmarked = 0;
                            i = 100;
                        }
                        goodValueRow, goodValueColumn = true;
                    }
                }
                
            }
            board = {};
        }
    }

    std::cout << "Part 1: " << fastest[1]*numbers[fastest[0]] << "\n";
}

void part2() {
    std::ifstream bingo;
    bingo.open("inputDay4.txt");

    std::string currNumber;

    std::vector<int> numbers= {};
    std::vector<int> board = {};
    std::vector<int> solvedPos = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    bool goodValueRow = true;
    bool goodValueColumn = true;

    int sumUnmarked = 0;

    std::vector<int> slowest = {0, 0};

    if (bingo.is_open()){
        for (int i=0; i<100; ++i){
            std::getline(bingo, currNumber, ',');
            numbers.push_back(stoi(currNumber));
        }
        std::getline(bingo, currNumber, '\n');
        while(bingo.good()){
            while (board.size() < 25){
                bingo >> currNumber;
                board.push_back(stoi(currNumber));            
            }
            for (int i=0; i<100; ++i){
                for (int j=0; j<25; ++j){
                    if (board[j] == numbers[i]){
                        solvedPos[j] = 1;
                        for (int k=0; k<5; ++k){
                            if (solvedPos[(j - j%5)+k]== 1){
                                goodValueRow = true;
                            } else{
                                goodValueRow = false;
                                k = 5;
                            }
                        }
                        for (int k=0; k<5; ++k){
                            if (solvedPos[(j%5)+k*5] == 1){
                                goodValueColumn = true;
                            } else{
                                goodValueColumn = false;
                                k = 5;
                            }
                        }
                        if (goodValueColumn || goodValueRow){
                            for (int k=0; k<25; ++k){
                                if(solvedPos[k] == 0){
                                    sumUnmarked += board[k];
                                }
                            }
                            j = 25;
                            if (i > slowest[0]){
                                slowest[0] = i;
                                slowest[1] = sumUnmarked;
                            }
                            solvedPos = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                            sumUnmarked = 0;
                            i = 100;
                        }
                        goodValueRow, goodValueColumn = true;
                    }
                }
                
            }
            board = {};
        }
    }

    std::cout << "Part 2: " << slowest[1]*numbers[slowest[0]] << "\n";
}

int main(){

    part1();
    part2();

    return 0;
}