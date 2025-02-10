// Write a program check the year is leap year.

#include <iostream>
using namespace std;

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int main() {
    int year;
    system("cls");
    cout << "Enter a year: ";
    cin >> year;

    if (isLeapYear(year)) {
        cout << year << " is a Leap Year." << endl;
    } else {
        cout << year << " is NOT a Leap Year." << endl;
    }

    return 0;
}
