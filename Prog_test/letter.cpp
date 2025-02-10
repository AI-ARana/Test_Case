// Write a program to check English letter or not. 

#include <iostream>
using namespace std;

// Function to check if the character is an English letter
bool isEnglishLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int main() {
    char ch;
    system("cls");
    cout << "Enter a character: ";
    cin >> ch;

    if (isEnglishLetter(ch)) {
        cout << ch << " is an English letter." << endl;
    } else {
        cout << ch << " is NOT an English letter." << endl;
    }

    return 0;
}
