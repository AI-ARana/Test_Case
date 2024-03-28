/* Create a function that determines whether elements in an array
 can be re-arranged to form a consecutive list of numbers
  where each number appears exactly once.
1. For the first array {4, 2, 5, 3, 1}, the elements can be 
rearranged to form a consecutive list, hence the output is true.
2. For the second array {1, 2, 3, 4, 5}, the elements are already 
3. in consecutive order, hence the output is true.
For the third array {3, 5, 2, 8, 1}, the elements cannot be rearranged 
to form a consecutive list, hence the output is false.*/

 #include <iostream>
#include <algorithm>
#include <vector>

bool canFormConsecutiveList(const std::vector<int>& arr) {
    // Sort the array in ascending order
    std::vector<int> sortedArr = arr;
    std::sort(sortedArr.begin(), sortedArr.end());

    // Check if the array contains consecutive numbers
    for (size_t i = 0; i < sortedArr.size() - 1; ++i) {
        if (sortedArr[i + 1] - sortedArr[i] != 1) {
            return false; // Not consecutive
        }
    }
    return true; // Consecutive
}

int main() {
    std::vector<int> arr1 = {4, 2, 5, 3, 1};
    std::cout << "Can elements be rearranged to form a consecutive list? " 
              << std::boolalpha << canFormConsecutiveList(arr1) << std::endl;

    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    std::cout << "Can elements be rearranged to form a consecutive list? " 
              << std::boolalpha << canFormConsecutiveList(arr2) << std::endl;

    std::vector<int> arr3 = {3, 5, 2, 8, 1};
    std::cout << "Can elements be rearranged to form a consecutive list? " 
              << std::boolalpha << canFormConsecutiveList(arr3) << std::endl;

    return 0;
}
 