/*Within a list of tasks represented by integers in an array called "nums," pinpoint a consecutive sequence of tasks. Rearranging these tasks in ascending order of complexity would ensure that the entire list is arranged in ascending order of complexity. Provide the indices denoting the start and end of this task sequence.
Input:
nums = [2, 6, 4, 8, 10, 9, 15]
Output:
[1, 5]
Explanation: 
To ensure that all events proceed in chronological order, you need to rearrange the events starting from the second event [6] to the sixth event [9]. This subarray [6, 4, 8, 10, 9] represents the shortest sequence of events that need to be rescheduled, allowing all events to progress seamlessly.

Example 2:
Input:
nums = [1, 3, 2, 4, 5]
Output: [1, 2]
Explanation:
 To ensure that tasks are tackled in the order of their priority levels, you need to rearrange the tasks starting from the second task [3] to the third task [2]. This subarray [3, 2] represents the shortest sequence of tasks that need to be reassigned, ensuring that tasks are addressed according to their priorities.

Constraints :
Array is not given sorted.*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findUnsortedSubarray(std::vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = n - 1;
    
    // Find the first element which is out of order from the beginning
    while (start < n - 1 && nums[start] <= nums[start + 1]) {
        start++;
    }
    
    // If start reached the end, the array is already sorted
    if (start == n - 1) {
        return {0, 0}; // The array is already sorted
    }
    
    // Find the first element which is out of order from the end
    while (end > 0 && nums[end] >= nums[end - 1]) {
        end--;
    }
    
    // Find the minimum and maximum values in the identified subarray
    int subarray_min = *std::min_element(nums.begin() + start, nums.begin() + end + 1);
    int subarray_max = *std::max_element(nums.begin() + start, nums.begin() + end + 1);
    
    // Extend the start index to the left if there are elements greater than the subarray_min
    while (start > 0 && nums[start - 1] > subarray_min) {
        start--;
    }
    
    // Extend the end index to the right if there are elements less than the subarray_max
    while (end < n - 1 && nums[end + 1] < subarray_max) {
        end++;
    }
    
    return {start, end};
}

int main() {
    int n;
    std::cout << "Enter the number of tasks: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the tasks: ";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::vector<int> result = findUnsortedSubarray(nums);
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;

    return 0;
}
