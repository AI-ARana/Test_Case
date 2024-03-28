/*Create a function that takes an integer and outputs 
an “n x n” square solely consisting of the integer n.*/
#include <iostream>
#include <vector>

void printSquare(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n = 5; // Change this value to any desired integer
    printSquare(n);
    return 0;
}
