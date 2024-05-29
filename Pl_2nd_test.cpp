/*Imagine you have an array nums where each element represents the value of a toffee. When you consume the toffee at position i, you gain coins equal to nums[i - 1] * nums[i] * nums[i + 1]. If i - 1 or i + 1 are out of the array's bounds, use the value 1 for those positions. Your objective is to determine the maximum number of coins you can collect by consuming all the toffees in the most strategic order.

Example 1:
Input:
nums = [3, 1, 5, 8]
Output:
167

Example 2:
Input:
nums = [1,5]

Output: 10
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive function with memoization
int dp(vector<int>& nums, vector<vector<int>>& memo, int left, int right) {
    if (left + 1 == right) return 0;  // No toffees in the subarray
    if (memo[left][right] != -1) return memo[left][right];
    
    int ans = 0;
    for (int i = left + 1; i < right; ++i) {
        int coins = nums[left] * nums[i] * nums[right];
        coins += dp(nums, memo, left, i) + dp(nums, memo, i, right);
        ans = max(ans, coins);
    }
    memo[left][right] = ans;
    return ans;
}

// Function to calculate the maximum coins
int maxCoins(vector<int>& nums) {
    int n = nums.size();
    
    // Add 1 at both ends of the nums array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    // Create a memoization table
    vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));
    
    // Calculate the maximum coins
    return dp(nums, memo, 0, n + 1);
}

// Test the function
int main() {
    vector<int> nums1 = {3, 1, 5, 8};
    cout << "Max coins for [3, 1, 5, 8]: " << maxCoins(nums1) << endl; // Output: 167
    
    vector<int> nums2 = {1, 5};
    cout << "Max coins for [1, 5]: " << maxCoins(nums2) << endl; // Output: 10
    
    return 0;
}
