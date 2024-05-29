/*You're embarking on a journey through a circular route with n checkpoints. Each checkpoint i is equipped with a certain resource, represented by res[i]. Traveling from checkpoint i to (i + 1) consumes a certain amount of this resource, denoted by cost[i]. You begin your journey with empty supplies at one of the checkpoints. Your task is to find the starting checkpoint index from where you can complete the circuit once in a clockwise direction without exhausting your resources. If such a solution exists, return the index; otherwise, return -1. If there exists a solution, it is guaranteed to be unique.

Example 1:
Input:
res = [1, 2, 3, 4, 5], cost = [3, 4, 5, 1, 2]
Output:
3
Example 2:
Input:
res = [2, 3, 4], cost = [3, 4, 3]
Output:
-1*/

#include <iostream>
#include <vector>

int canCompleteCircuit(const std::vector<int>& res, const std::vector<int>& cost) {
    int n = res.size();
    int totalRes = 0, totalCost = 0;
    int currentRes = 0;
    int startIndex = 0;
    
    for (int i = 0; i < n; ++i) {
        totalRes += res[i];
        totalCost += cost[i];
        currentRes += res[i] - cost[i];
        
        // If currentRes drops below 0, reset the startIndex to the next index
        if (currentRes < 0) {
            startIndex = i + 1;
            currentRes = 0;
        }
    }
    
    // If total resources are less than total cost, return -1
    if (totalRes < totalCost) {
        return -1;
    }
    
    return startIndex;
}

int main() {
    int n;
    std::cout << "Enter the number of checkpoints: ";
    std::cin >> n;

    std::vector<int> res(n);
    std::vector<int> cost(n);

    std::cout << "Enter the resources at each checkpoint: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> res[i];
    }

    std::cout << "Enter the costs to travel to the next checkpoint: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> cost[i];
    }

    int result = canCompleteCircuit(res, cost);
    std::cout << "Starting checkpoint index: " << result << std::endl;

    return 0;
}
