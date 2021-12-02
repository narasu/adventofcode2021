#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    int hPos = 0;
    int depth = 0;
    int aim = 0;

    std::ifstream input;
    input.open("input.txt", std::ifstream::in);
    if (input.is_open()) {

        while (input.good()) {
            std::string line;
            getline(input, line);


            std::stringstream ss(line);
            std::string direction;
            getline(ss, direction, ' ');
            int value;
            ss >> value;

            if (direction == "up") {
                //depth -= value;
                aim -= value;
            }
            else if (direction == "down") {
                //depth += value;
                aim += value;
            }
            else if (direction == "forward") {
                hPos += value;
                depth += aim * value;
            }
        }
    }
    else {
        std::cout << "Unable to open file";
    }
    std::cout << "hPos = " << hPos << std::endl;
    std::cout << "depth = " << depth << std::endl;

    std::cout << "hPos * depth = " << hPos * depth << std::endl;
    return 0;
}
