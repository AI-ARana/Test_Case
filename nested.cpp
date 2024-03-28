/*Create a function that takes an array as an argument and 
returns a new nested array for each element in the original array.
 The nested array must be filled with the corresponding element in
 the original array and each nested array has the same amount of elements 
 as the original array.*/
 #include <iostream>
#include <vector>

std::vector<std::vector<int>> createNestedArrays(const std::vector<int>& arr) {
    std::vector<std::vector<int>> nestedArrays;
    for (int num : arr) {
        std::vector<int> nestedArray(arr.size(), num); // Fill the nested array with the current element
        nestedArrays.push_back(nestedArray);
    }
    return nestedArrays;
}

int main() {
    std::vector<int> originalArray = {1, 2, 3}; // Change the array as needed
    std::vector<std::vector<int>> result = createNestedArrays(originalArray);

    // Print the nested arrays
    std::cout << "Nested Arrays:" << std::endl;
    for (const auto& nestedArray : result) {
        for (int num : nestedArray) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
