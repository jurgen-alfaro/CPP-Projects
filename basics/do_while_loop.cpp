#include<iostream>

int main() {
    // do some block of code first, then repeat again if condition is true\

    int number; // Remember that when the variable is not initialized, it's defaulted to 0 (for integers);

    do {
        std::cout << "Enter a positive number: ";
        std::cin >> number;
    } while(number < 0);

    std::cout << "The number is " << number;

    return 0;
}