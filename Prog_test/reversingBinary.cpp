// Write a program to convert the number into binary number, 
//then print the reversing of binary number.

#include <iostream>
#include <algorithm>  // Include this for reverse function
using namespace std;

// Function to convert decimal to binary and return as a string
string decimalToBinary(int num) {
    string binary = "";
    while (num > 0) {
        binary += (num % 2) + '0';  // Convert remainder to '0' or '1'
        num /= 2;
    }
    reverse(binary.begin(), binary.end()); // Reverse to get correct binary order
    return binary;
}

// Function to reverse the binary string
string reverseBinary(string binary) {
    reverse(binary.begin(), binary.end());
    return binary;
}

int main() {
    int num;
    system("cls");
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    // Convert to binary
    string binary = decimalToBinary(num);
    cout << "Binary representation: " << binary << endl;

    // Reverse the binary representation
    string reversedBinary = reverseBinary(binary);
    cout << "Reversed Binary: " << reversedBinary << endl;

    return 0;
}

