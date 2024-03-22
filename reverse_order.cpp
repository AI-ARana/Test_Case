/*Write a function to reverse the order of words with punctuation and 
keep the punctuation in place that runs at 0(n) time.*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

bool isPunctuation(char c) {
    return ispunct(c) || isspace(c);
}

std::string reverseWordsWithPunctuation(const std::string& s) {
    std::string reversedString = s;

    // Step 1: Reverse the entire string
    std::reverse(reversedString.begin(), reversedString.end());

    // Step 2: Reverse each word in the reversed string
    int start = 0;
    for (int i = 0; i <= reversedString.size(); ++i) {
        if (isPunctuation(reversedString[i]) || i == reversedString.size()) {
            std::reverse(reversedString.begin() + start, reversedString.begin() + i);
            start = i + 1;
        }
    }

    // Step 3: Restore the original positions of the punctuation marks
    std::reverse(reversedString.begin(), reversedString.end());

    return reversedString;
}

int main() {
    std::string s = "Programming Test.";
    std::cout << "Original string: " << s << std::endl;
    std::string reversed = reverseWordsWithPunctuation(s);
    std::cout << "Reversed string with punctuation in place: " << reversed << std::endl;
    return 0;
}
