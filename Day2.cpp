#include <iostream>
#include <fstream>
#include <string>

void star3(){
    int depth = 0;
    int position = 0;
    int val = 0;
    std::string direction;

    std::fstream directions;
    directions.open("inputDay2.txt");

    if (directions.is_open()){
        while (directions.good()){
            directions >> direction;
            directions >> val;
            if (direction == "forward"){
                position += val;
            } else if (direction == "up"){
                depth -= val;
            } else if (direction == "down"){
                depth += val;
            }
            val = 0;
        }
    }

    directions.close();

    std::cout << depth * position << "\n";
}

void star4(){
    int depth = 0;
    int position = 0;
    int aim = 0;
    int val = 0;
    std::string direction;

    std::fstream directions;
    directions.open("inputDay2.txt");

    if (directions.is_open()){
        while (directions.good()){
            directions >> direction;
            directions >> val;
            if (direction == "forward"){
                position += val;
                depth += aim * val;
            } else if (direction == "up"){
                aim -= val;
            } else if (direction == "down"){
                aim += val;
            }
            val = 0;
        }
    }

    directions.close();

    std::cout << depth * position << "\n";
}


int main(){
    
    star3();
    star4();   

    return 0;
}