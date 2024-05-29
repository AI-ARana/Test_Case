/*There is a new alien language that uses the English alphabet. However, the order among the letters is unknown. You are given a list of strings words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of the letters in this language, and return it as a string. If the given input is invalid, return an empty string.
Example 1 : 
Input : 
words = { "caa", "aaa", "aab" }
Output : 
“CAB”
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.

Example 2:
Input:
words = { "z", "x", "z" }
Output: 
“” (Empty String )
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> adjList;
    unordered_map<char, int> inDegree;
    unordered_set<char> chars;
    
    // Initialize the in-degree map and character set
    for (const string& word : words) {
        for (char c : word) {
            chars.insert(c);
            inDegree[c] = 0;
        }
    }
    
    // Build the adjacency list and in-degree count
    for (int i = 0; i < words.size() - 1; ++i) {
        string word1 = words[i];
        string word2 = words[i + 1];
        int len = min(word1.length(), word2.length());
        bool foundDifference = false;
        
        for (int j = 0; j < len; ++j) {
            char c1 = word1[j];
            char c2 = word2[j];
            if (c1 != c2) {
                if (adjList[c1].find(c2) == adjList[c1].end()) {
                    adjList[c1].insert(c2);
                    inDegree[c2]++;
                }
                foundDifference = true;
                break;
            }
        }
        
        // If we didn't find a difference and word2 is a prefix of word1, it's invalid
        if (!foundDifference && word1.length() > word2.length()) {
            return "";
        }
    }
    
    // Perform a topological sort using Kahn's algorithm
    queue<char> zeroInDegreeQueue;
    for (const auto& entry : inDegree) {
        if (entry.second == 0) {
            zeroInDegreeQueue.push(entry.first);
        }
    }
    
    string result;
    while (!zeroInDegreeQueue.empty()) {
        char c = zeroInDegreeQueue.front();
        zeroInDegreeQueue.pop();
        result += c;
        
        if (adjList.find(c) != adjList.end()) {
            for (char neighbor : adjList[c]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroInDegreeQueue.push(neighbor);
                }
            }
        }
    }
    
    // Check if we used all characters
    if (result.length() != chars.size()) {
        return "";
    }
    
    return result;
}

int main() {
    vector<string> words1 = {"caa", "aaa", "aab"};
    cout << "Output for words1: " << alienOrder(words1) << endl; // Output: "cab"

    vector<string> words2 = {"z", "x", "z"};
    cout << "Output for words2: " << alienOrder(words2) << endl; // Output: ""

    return 0;
}
