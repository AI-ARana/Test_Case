/*Given two words (startWord and endWord) and a dictionary’s word list,
 find the length of the tshortest transformation sequence from startWord to endWord.*/
#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int ladderLength(string startWord, string endWord, unordered_set<string>& wordList) {
    // BFS
    queue<pair<string, int>> q;
    q.push({startWord, 1});

    // Mark visited words to avoid cycles
    unordered_set<string> visited;
    visited.insert(startWord);

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        string currentWord = front.first;
        int level = front.second;

        // Check if we reached the end word
        if (currentWord == endWord) {
            return level;
        }

        // Generate all possible next words by changing one character at a time
        for (int i = 0; i < currentWord.length(); ++i) {
            char originalChar = currentWord[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == originalChar) continue;
                currentWord[i] = c;

                // If the new word is in the word list and not visited yet, add it to the queue
                if (wordList.count(currentWord) && !visited.count(currentWord)) {
                    q.push({currentWord, level + 1});
                    visited.insert(currentWord);
                }
            }
            // Restore the original character
            currentWord[i] = originalChar;
        }
    }
    // If endWord is not reachable from startWord
    return 0;
}

int main() {
    string startWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = ladderLength(startWord, endWord, wordList);
    cout << "Length of the shortest transformation sequence: " << result << endl;

    return 0;
}
