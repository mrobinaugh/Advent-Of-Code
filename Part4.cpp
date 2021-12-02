#include <iostream>
#include <fstream>
#include <string>

int main(){

    int depth = 0;
    int position = 0;
    int aim = 0;
    int val = 0;
    std::string direction;

    std::fstream directions;
    directions.open("inputPart3.txt");

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

    std::cout << depth << "\n" << position << "\n" << depth * position << "\n";

    return 0;
}