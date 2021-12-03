#include <iostream>
#include <fstream>
#include <sstream>

std::string convertToString(char* a, int size)
{
    int i;
    std::string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}


int main() {
    std::ifstream input;
    input.open("input.txt", std::ifstream::in);
    char bits[1000][12];

    // read numbers from file and store them in 2D array bits
    if (input.is_open()) {
        int i = 0;
        while (input.good()) {
            std::string line;
            getline(input, line);
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
    char gammaArray[12] = {};
    char epsilonArray[12] = {};

    int count[12] = {};

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 12; j++) {
            if (bits[i][j] == '1') {
                count[j]++;

            }
            else if (bits[i][j] == '0'){
                count[j]--;
            }
        }
    }
    for (int i = 0; i < 12; i++) {
        if (count[i] > 0) {
            gammaArray[i] = '1';
            epsilonArray[i] = '0';
        }
        else if (count[i] < 0) {
            gammaArray[i] = '0';
            epsilonArray[i] = '1';
        }
    }
    for (const auto& e : gammaArray) {
        std::cout << e;
    }
    std::cout << std::endl;
    for (const auto& e : epsilonArray) {
        std::cout << e;
    }
    std::cout << std::endl;

    std::string gamma = convertToString(gammaArray, 12);
    std::string epsilon = convertToString(epsilonArray, 12);
    unsigned long long gammaDecimal = std::stoull(gamma, 0, 2);
    unsigned long long epsilonDecimal = std::stoull(epsilon, 0, 2);
    std::cout << "gamma decimal: " << gammaDecimal << std:: endl;
    std::cout << "epsilon decimal: " << epsilonDecimal << std:: endl;
    std::cout << "gamma * epsilon = " << gammaDecimal * epsilonDecimal << std:: endl;
    return 0;
}

