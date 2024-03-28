/*Write two functions:
1. One to retrieve all unique substrings that start and end with a vowel.
2. One to retrieve all unique substrings that start and end with a consonant.
The resulting array should be sorted in lexicographic ascending order (same order as a dictionary).
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

std::vector<std::string> getUniqueSubstringsStartEndWithVowel(const std::string& s) {
    std::set<std::string> substrings;

    for (size_t i = 0; i < s.length(); ++i) {
        if (isVowel(s[i])) {
            for (size_t j = i + 1; j < s.length(); ++j) {
                if (isVowel(s[j])) {
                    substrings.insert(s.substr(i, j - i + 1));
                }
            }
        }
    }

    return std::vector<std::string>(substrings.begin(), substrings.end());
}

bool isConsonant(char c) {
    return !isVowel(c);
}

std::vector<std::string> getUniqueSubstringsStartEndWithConsonant(const std::string& s) {
    std::set<std::string> substrings;

    for (size_t i = 0; i < s.length(); ++i) {
        if (isConsonant(s[i])) {
            for (size_t j = i + 1; j < s.length(); ++j) {
                if (isConsonant(s[j])) {
                    substrings.insert(s.substr(i, j - i + 1));
                }
            }
        }
    }

    return std::vector<std::string>(substrings.begin(), substrings.end());
}

int main() {
    std::string input = "hello";
    std::cout << "Unique substrings that start and end with a vowel:" << std::endl;
    std::vector<std::string> vowelSubstrings = getUniqueSubstringsStartEndWithVowel(input);
    std::sort(vowelSubstrings.begin(), vowelSubstrings.end());
    for (const auto& substring : vowelSubstrings) {
        std::cout << substring << std::endl;
    }

    std::cout << "\nUnique substrings that start and end with a consonant:" << std::endl;
    std::vector<std::string> consonantSubstrings = getUniqueSubstringsStartEndWithConsonant(input);
    std::sort(consonantSubstrings.begin(), consonantSubstrings.end());
    for (const auto& substring : consonantSubstrings) {
        std::cout << substring << std::endl;
    }

    return 0;
}


/*The first function getUniqueSubstringsStartEndWithVowel 
retrieves all unique substrings that start and end with a vowel by 
iterating through the string and forming substrings that meet the criteria.
 It stores the substrings in a set to automatically eliminate duplicates.
The second function getUniqueSubstringsStartEndWithConsonant works 
similarly but retrieves substrings that start and end with a consonant.
In the main function, we provide an example input string "hello", 
call both functions, sort the resulting substrings lexicographically,
 and print them out for demonstration.*/