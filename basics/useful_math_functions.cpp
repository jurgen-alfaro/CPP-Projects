#include <iostream>
#include <cmath>

int main() {
    double x = 3;
    double y = 4;
    double z;

    z = std::max(x, y); // Get the max between two numbers
    z = std::min(x, y); // Get the min between two numbers
    z = pow(2, 3); // Power function (needs to he cmath header);
    z = sqrt(9); // Square root
    z = abs(-3); // Absolute value
    z = round(x); 
    z = ceil(x); // Round up
    z = floor(x); // Round down

    std::cout << z;

    return 0;
}