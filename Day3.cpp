#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void part1(){
    ifstream binaries;
    binaries.open("inputDay3.txt");

    string binary;

    string epsilonb, gammab = "Twelve Digit";
    long epsilon, gamma;

    vector<int> sums = {0,0,0,0,0,0,0,0,0,0,0,0};

    if (binaries.is_open()){
        while (binaries.good()){
            binaries >> binary;
            for (int i=0; i<12; ++i){
                sums[i] += binary[i] - '0';
            }
        }
        for (int i=0; i<12; ++i){
            if (sums[i] >= 500){
                gammab[i] = '1';
                epsilonb[i] = '0';
            } else {
                gammab[i] = '0';
                epsilonb[i] = '1';
            }
        }

    }

    gamma = stoi(gammab, 0, 2);
    epsilon = stoi(epsilonb, 0, 2);

    binaries.close();

    cout << "Part 1: " << gamma * epsilon << "\n";
}

void part2(){
    vector<string> allBinaries = {};
    vector<string> prevBinaries = {};
    vector<string> currBinaries1 = {};
    vector<string> currBinaries0 = {};

    ifstream binaries;
    binaries.open("inputDay3.txt");

    string binary;

    int mostCommon;
    int leastCommon;

    long ox, co2 = 0;

    if (binaries.is_open()){
        while(getline(binaries,binary)){
            allBinaries.push_back(binary);
        }
    }

    prevBinaries = allBinaries;

    for (int i=0; i<12; ++i){
        for (int j=0; j<prevBinaries.size(); ++j){
            if ((prevBinaries[j][i]-'0') == 1){
                currBinaries1.push_back(prevBinaries[j]);
            } else{
                currBinaries0.push_back(prevBinaries[j]);
            }
        }

        if (currBinaries1.size() >= currBinaries0.size()){
            prevBinaries = currBinaries1;
        } else{
            prevBinaries = currBinaries0;
        }

        if (prevBinaries.size() == 1){
            i = 12;
            ox = stoi(prevBinaries[0], 0, 2);
        }

        currBinaries1 = {};
        currBinaries0 = {};

    }

    prevBinaries = allBinaries;

    for (int i=0; i<12; ++i){
        for (int j=0; j<prevBinaries.size(); ++j){
            if ((prevBinaries[j][i]-'0') == 1){
                currBinaries1.push_back(prevBinaries[j]);
            } else{
                currBinaries0.push_back(prevBinaries[j]);
            }
        }

        if (currBinaries1.size() >= currBinaries0.size()){
            prevBinaries = currBinaries0;
        } else{
            prevBinaries = currBinaries1;
        }

        if (prevBinaries.size() == 1){
            i = 12;
            co2 = stoi(prevBinaries[0], 0, 2);
        }

        currBinaries1 = {};
        currBinaries0 = {};

    }
    cout << "Part 2: " << ox * co2 << "\n";

}


int main(){

    part1();
    part2();

    return 0;
}