/*Create a function that takes two arguments: 
the original price and the discount percentage as integers and 
returns the final price after the discount.*/
#include <iostream>

double calculateFinalPrice(int originalPrice, int discountPercentage) {
    double discountAmount = originalPrice * (static_cast<double>(discountPercentage) / 100.0);
    double finalPrice = originalPrice - discountAmount;
    return finalPrice;
}

int main() {
    int originalPrice = 100;
    int discountPercentage = 20;
    double finalPrice = calculateFinalPrice(originalPrice, discountPercentage);
    
    std::cout << "Original price: $" << originalPrice << std::endl;
    std::cout << "Discount percentage: " << discountPercentage << "%" << std::endl;
    std::cout << "Final price after discount: $" << finalPrice << std::endl;

    return 0;
}
