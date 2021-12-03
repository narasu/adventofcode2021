#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string convertToString(char* a, int size)
{
    int i;
    std::string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

void filterVector(std::vector<std::string>& v, int stringPos, bool common) {

    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].at(stringPos) == '1') {
            count++;
        }
        else if (v[i].at(stringPos) == '0') {
            count--;
        }
    }
    char bitToRemove;
    if (count >= 0) {
        if (common) {bitToRemove = '1';}
        else { bitToRemove = '0'; }
    }
    else {
        if (common) {bitToRemove = '0';}
        else { bitToRemove = '1'; }
    }

    auto it = v.begin();
    while (it != v.end()) {
        auto s = *it;
        if (s.at(stringPos) == bitToRemove) {
            it = v.erase(it);
        }
        else {
            it++;
        }
    }

    if (v.size() == 1) {
        std::cout << "final number: " << v[0] << std::endl;
        return;
    }
}

int main() {
    std::ifstream input;
    input.open("input.txt", std::ifstream::in);
    char bits[1000][12];
    std::vector<std::string> oxygenVector;
    std::vector<std::string> co2Vector;
    // read numbers from file and store them in 2D array bits
    if (input.is_open()) {
        int i = 0;
        while (input.good()) {
            std::string line;
            getline(input, line);
            oxygenVector.push_back(line);
            co2Vector.push_back(line);
            std::stringstream ss(line);
            for (size_t j = 0; j < line.size(); j++) {
                bits[i][j] = line[j];
            }
            i++;
        }
    }
    else {
        std::cout << "Unable to open file";
    }


    for (int pos = 0; pos < 12; pos++) {
        filterVector(oxygenVector, pos, true);
        filterVector(co2Vector, pos, false);
    }
    unsigned long long oxygenDecimal = std::stoull(oxygenVector[0], 0, 2);
    unsigned long long co2Decimal = std::stoull(co2Vector[0], 0, 2);
    std::cout << "oxygen * co2 = " << oxygenDecimal * co2Decimal << std:: endl;
//    char gammaArray[12] = {};
//    char epsilonArray[12] = {};
//    int count[12] = {};
//    std::cout << oxygenVector.size() << std::endl;
//    for (int i = 0; i < 1000; i++) {
//        for (int j = 0; j < 12; j++) {
//            if (bits[i][j] == '1') {
//                count[j]++;
//
//            }
//            else if (bits[i][j] == '0'){
//                count[j]--;
//            }
//        }
//    }
//    for (int i = 0; i < 12; i++) {
//        if (count[i] > 0) {
//            gammaArray[i] = '1';
//            epsilonArray[i] = '0';
//        }
//        else if (count[i] < 0) {
//            gammaArray[i] = '0';
//            epsilonArray[i] = '1';
//        }
//    }

//    std::string gamma = convertToString(gammaArray, 12);
//    std::string epsilon = convertToString(epsilonArray, 12);
//    unsigned long long gammaDecimal = std::stoull(gamma, 0, 2);
//    unsigned long long epsilonDecimal = std::stoull(epsilon, 0, 2);
//    std::cout << "gamma decimal: " << gammaDecimal << std:: endl;
//    std::cout << "epsilon decimal: " << epsilonDecimal << std:: endl;
//    std::cout << "gamma * epsilon = " << gammaDecimal * epsilonDecimal << std:: endl;


    return 0;
}