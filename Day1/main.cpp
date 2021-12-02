#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::vector<int> numberList;
    int increaseCount = 0;
    std::ifstream input;
    input.open("numbers.txt", std::ifstream::in);
    if (input.is_open()) {
        int n;
        while (input.good() && input >> n) {
            numberList.push_back(n);
        }
    }
    else {
        std::cout << "Unable to open file";
    }

    int setA=0;
    int setB=0;
    for (std::size_t i = 0; i < numberList.size(); ++i) {
        if (i<numberList.size()-2) {
            setA = setB;
            setB = numberList[i] + numberList[i+1] + numberList[i+2];
            if (i > 0 && setB > setA) {
                ++increaseCount;
            }
//            if (i > 0) {
//                if (numberList[i] > numberList[i-1]) {
//                    //std::cout << "increase" << std::endl;
//                    ++increaseCount;
//                }
//            }
        }

        //std::cout << i << std::endl;
    }
    std::cout << increaseCount;

//    for (auto it = std::begin(numberList); it != std::end(numberList); ++it) {
//        if (std::distance(numberList, it) > 0) {
//
//        }
//
//        std::cout << *it << std::endl;
//    }

//    for (int n : numberList) {
//
//        std::cout << n << std::endl;
//
//    }


    return 0;
}
