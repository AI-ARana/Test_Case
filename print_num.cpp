/* Write a program that prints the numbers from 1 to 100. 
But for multiples of three, print “AI” instead of the number, 
and multiples of five, print “ML”. For numbers that are multiples 
of both three and five, print “AIML”.*/
#include <iostream>

int main() {
    for (int i = 1; i <= 100; ++i) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "AIML ";
        } else if (i % 3 == 0) {
            std::cout << "AI ";
        } else if (i % 5 == 0) {
            std::cout << "ML ";
        } else {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
