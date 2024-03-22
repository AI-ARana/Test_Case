/*Write a function that will print out all prime numbers in a given string.*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimeNumbers(const std::string& str) {
    std::string numStr;
    for (char ch : str) {
        if (isdigit(ch)) {
            numStr += ch;
        } else if (!numStr.empty()) {
            int num = std::stoi(numStr);
            if (isPrime(num)) {
                std::cout << num << " ";
            }
            numStr.clear();
        }
    }
    if (!numStr.empty()) {
        int num = std::stoi(numStr);
        if (isPrime(num)) {
            std::cout << num << " ";
        }
    }
}

int main() {
    std::string inputString = "abc123def456ghi789jkl";
    std::cout << "Prime numbers in the string: ";
    printPrimeNumbers(inputString);
    std::cout << std::endl;
    return 0;
}
