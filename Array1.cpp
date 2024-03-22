/*“arr” is an array of integers. There are no repeating integers in “arr”.
 A function f(x,y) acting on two elements in the list moves x to y's position and 
 y to x's position. Find out the least number of times you can call f so that
  the resulting array is in ascending order.*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to find the minimum number of swaps
int minSwaps(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> pos;

    for (int i = 0; i < n; ++i)
        pos[arr[i]] = i;

    int swaps = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != i + 1) {
            swaps++;
            int x = arr[i];
            int y = pos[i + 1];
            swap(arr[i], arr[y]);
            pos[x] = y;
            pos[i + 1] = i;
        }
    }
    return swaps;
}

int main() {
    vector<int> arr = {3, 1, 2, 4}; // Example array
    int swaps = minSwaps(arr);
    cout << "Minimum number of swaps needed: " << swaps << endl;
    return 0;
}
