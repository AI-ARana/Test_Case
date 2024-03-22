/*WAP to Print Address Of Pointer Of An Array.*/
#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptrArr = arr; // Pointer to the first element of the array

    // Print the address of each element of the array using pointer arithmetic
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        std::cout << "Address of element " << i << " is: " << &ptrArr[i] << std::endl;
    }

    return 0;
}
