/*Create a function that takes two numbers as arguments (num, length) 
and returns an array of multiples of “num” until the array length reaches
 “length”.*/
#include <iostream>
#include <vector>

std::vector<int> multiplesOfNum(int num, int length) {
    std::vector<int> result;
    for (int i = 1; result.size() < length; ++i) {
        result.push_back(num * i);
    }
    return result;
}

int main() {
    int num = 5;
    int length = 7;
    std::vector<int> result = multiplesOfNum(num, length);
    
    std::cout << "Multiples of " << num << " until array length reaches " << length << ":" << std::endl;
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
