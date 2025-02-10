// Write a program for rotation. 
//For Example, the array 1,2,3,4,5,6,7 becomes 3,4,5,6,7,1,2 after 2 rotations.

#include <iostream>
#include <algorithm>  // For reverse function
using namespace std;

// Function to rotate array left by d positions
void rotateArray(int arr[], int n, int d) {
    d = d % n;  // Handle cases where d > n
    reverse(arr, arr + d);       // Reverse first d elements
    reverse(arr + d, arr + n);   // Reverse remaining n-d elements
    reverse(arr, arr + n);       // Reverse the whole array
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;  // Number of rotations
    system("cls");
    cout << "Original Array: ";
    printArray(arr, n);

    rotateArray(arr, n, d);

    cout << "Rotated Array: ";
    printArray(arr, n);

    return 0;
}
