// Write a program to calculate the sum of first and last digit. Exp 5674= 5+4=9)	

#include <iostream>
using namespace std;

// Function to find the sum of the first and last digit
int sumFLD(int n) {
    int lD = n % 10; // Extract the last digit
    int fD = n;

    // Extract the first digit by continuously dividing by 10
    while (fD >= 10) {
        fD /= 10;
    }

    return fD + lD;
}

int main() {
    int n;
    system("cls");
    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a positive number." << endl;
        return 1;
    }

    int sum = sumFLD(n);
    cout << "Sum of first and last digit: " << sum << endl;

    return 0;
}
