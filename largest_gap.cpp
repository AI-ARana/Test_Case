/* Given an array of integers, return the largest gap between the sorted 
elements of the array.*/
#include <iostream>
#include <vector>
#include <algorithm>

int largestGap(const std::vector<int>& nums) {
    if (nums.empty() || nums.size() == 1) {
        return 0; // Empty array or single element array
    }

    // Sort the array in ascending order
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());

    // Find the largest gap
    int maxGap = 0;
    for (size_t i = 0; i < sortedNums.size() - 1; ++i) {
        int gap = sortedNums[i + 1] - sortedNums[i];
        if (gap > maxGap) {
            maxGap = gap;
        }
    }
    return maxGap;
}

int main() {
    std::vector<int> nums1 = {1, 10, 5};
    std::cout << "Largest gap: " << largestGap(nums1) << std::endl;

    std::vector<int> nums2 = {10, 3, 1};
    std::cout << "Largest gap: " << largestGap(nums2) << std::endl;

    std::vector<int> nums3 = {5, 3, 9, 8};
    std::cout << "Largest gap: " << largestGap(nums3) << std::endl;

    return 0;
}
