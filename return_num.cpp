/*Write a function that returns all numbers less than or equal
 to N with the maximum product of digits.*/
#include <iostream>
#include <vector>

// Function to calculate the product of digits of a number
int productOfDigits(int num) {
    int product = 1;
    while (num != 0) {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

// Function to return all numbers less than or equal to N with maximum product of digits
std::vector<int> maxProductNumbers(int N) {
    int maxProduct = 0;
    std::vector<int> result;

    for (int i = 1; i <= N; ++i) {
        int product = productOfDigits(i);
        if (product > maxProduct) {
            maxProduct = product;
            result.clear(); // Reset result vector since we found a new max product
            result.push_back(i);
        } else if (product == maxProduct) {
            result.push_back(i); // Add to result vector if product equals maxProduct
        }
    }

    return result;
}

int main() {
    int N = 100; // Change N as needed
    std::vector<int> result = maxProductNumbers(N);

    std::cout << "Numbers less than or equal to " << N
              << " with maximum product of digits: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
