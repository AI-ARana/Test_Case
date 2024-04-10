/* You are given a list of names and their corresponding scores in a coding competition. 
Your task is to sort the names based on their scores in descending order. 
If two or more participants have the same score, sort their names alphabetically. 
Write a program to perform this task efficiently.
Input Format:
The input consists of multiple lines, each containing a participant's name and 
score separated by a space. The input is terminated by a line containing 
only a single asterisk '*'.

Output Format:
Output the sorted list of names along with their scores, separated by a space, 
with each participant's name and score on a new line.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Participant {
    std::string name;
    int score;
};

bool compareParticipants(const Participant& p1, const Participant& p2) {
    if (p1.score != p2.score)
        return p1.score > p2.score; // Sort by score in descending order
    else
        return p1.name < p2.name;   // If scores are equal, sort by name in ascending order
}

int main() {
    std::vector<Participant> participants;
    std::string name;
    int score;

    // Input
    while (true) {
        std::cin >> name;
        if (name == "*")
            break;
        std::cin >> score;
        participants.push_back({name, score});
    }

    // Sorting
    std::sort(participants.begin(), participants.end(), compareParticipants);

    // Output
    for (const auto& participant : participants) {
        std::cout << participant.name << " " << participant.score << std::endl;
    }

    return 0;
}
