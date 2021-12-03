#include <iostream>
#include <fstream>
#include <sstream>


int main() {
    std::ifstream input;
    input.open("input.txt", std::ifstream::in);
    int bits[1000][12];

    // read numbers from file and store them in 2D array bits
    if (input.is_open()) {
        int i = 0;
        while (input.good()) {
            std::string line;
            getline(input, line);
            std::stringstream ss(line);
            for (size_t j = 0; j < line.size(); j++) {
                bits[i][j] = (int)line[j]-48;
            }
            i++;
        }
    }
    else {
        std::cout << "Unable to open file";
    }

    //output of bits array test
//    for (int i = 0; i < 1000; i ++) {
//        for (int j = 0; j < 12; j++) {
//            std::cout << bits[i][j];
//        }
//        std::cout << std::endl;
//    }

    int count[12] = {};

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 12; j++) {
            if (bits[i][j] == 1) {
                count[j]++;

            }
            else if (bits[i][j] == 0){
                count[j]--;
            }
            //std::cout << bits[i][j];
        }
    }

    int gammaArray[12] = {};
    int epsilonArray[12] = {};

    for (int i = 0; i < 12; i++) {
        if (count[i] > 0) {
            gammaArray[i] = 1;
            epsilonArray[i] = 0;
        }
        else if (count[i] < 0) {
            gammaArray[i] = 0;
            epsilonArray[i] = 1;
        }

    }
    //test gamma & epsilon array output
    for (const auto& e : gammaArray) {
        std::cout << e;
    }
    std::cout << std::endl;
    for (const auto& e : epsilonArray) {
        std::cout << e;
    }
    std::cout << std::endl;

//    std::stringstream ss;
//    for (int i : gammaArray) ss << i;
//    ss >> gamma;


    return 0;
}
