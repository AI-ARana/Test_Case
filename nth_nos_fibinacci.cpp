/*Write a function that will find the nth number in 
the Fibonacci Sequence and runs at O(n) time.*/
#include <iostream>

int fibonacci(int n) {
    if (n <= 1)
        return n;

    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main() {
    int n = 10; // Example: find the 10th Fibonacci number
    std::cout << "The " << n << "th Fibonacci number is: " << fibonacci(n) << std::endl;
    return 0;
}
