#include<iostream>
#include<cmath>

int main() {
    double a, b, c;

    std::cout << "Enter side A: ";
    std::cin >> a;

    std::cout << "Enter side B: ";
    std::cin >> b;

    std::cout << "'a' value is " << a << "\n";
    std::cout << "'b' value is " << b << "\n";

    c = sqrt(pow(a, 2) + pow(b, 2));

    std::cout << "The hypotenuse value is " << c;

    return 0;
}