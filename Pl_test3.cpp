/*Given an array of strings words and an integer k, return the k most frequent strings.
Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

Example 1:
Input:
words = ["i", "love", "brainmentors", "i", "love", "coding"], k = 2
Output:
["i", "love"]

Example 2:
Input:
words = ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output:
["the", "is", "sunny", "day"]*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k) {
    // Step 1: Count the frequency of each word
    std::unordered_map<std::string, int> freqMap;
    for (const std::string& word : words) {
        freqMap[word]++;
    }
    
    // Step 2: Create a vector of pairs (word, frequency) from the map
    std::vector<std::pair<std::string, int>> freqVec(freqMap.begin(), freqMap.end());
    
    // Step 3: Sort the vector by frequency and lexicographical order
    std::sort(freqVec.begin(), freqVec.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first; // Lexicographical order
        }
        return a.second > b.second; // Descending frequency order
    });
    
    // Step 4: Extract the top k elements
    std::vector<std::string> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(freqVec[i].first);
    }
    
    return result;
}

int main() {
    int n;
    std::cout << "Enter the number of words: ";
    std::cin >> n;
    
    std::vector<std::string> words(n);
    std::cout << "Enter the words: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> words[i];
    }

    int k;
    std::cout << "Enter the value of k: ";
    std::cin >> k;

    std::vector<std::string> result = topKFrequent(words, k);
    std::cout << "Top " << k << " frequent words: ";
    for (const std::string& word : result) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
