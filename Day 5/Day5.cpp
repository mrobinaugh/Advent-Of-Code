#include <iostream>
#include <fstream>


void part1(){
    int grid[1000][1000] = {};

    std::string x1s, y1s, x2s, y2s;
    int x1, y1, x2, y2;

    int total = 0;

    std::ifstream lines;
    lines.open("inputDay5.txt");

    if (lines.is_open()){
        while (lines.good()){
            getline(lines, x1s, ',');
            x1 = stoi(x1s);
            lines >> y1s;
            y1 = stoi(y1s);
            lines >> x2s;
            getline(lines, x2s, ',');
            x2 = stoi(x2s);
            lines >> y2s;
            y2 = stoi(y2s);

            //std::cout << x1 << ',' << y1 << ',' << x2 << ',' << y2 << '\n';

            if (x1 == x2){
                if (y1 <= y2){
                    for(int i = y1; i <= y2; ++i){
                        grid[i][x2] += 1;
                    }
                } else {
                    for(int i = y2; i <= y1; ++i){
                        grid[i][x2] += 1;
                    }
                }
            } else if (y1 == y2){
                if (x1 <= x2){
                    for(int i = x1; i <= x2; ++i){
                        grid[y1][i] += 1;
                    }
                } else {
                    for(int i = x2; i <= x1; ++i){
                        grid[y1][i] += 1;
                    }
                }
            }

            x1, x2, y1, y2 = 0;
        }
    }

    lines.close();

    for(int i = 0; i < 1000; ++i){
        for(int j = 0; j < 1000; ++j){
            if (grid[i][j] >= 2){
                ++total;
            }
        }
    } 
    
    std::cout << "Part 1: " << total << std::endl;

}

int main(){

    part1();

}