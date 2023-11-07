#include <iostream>

enum Day {
    sunday = 0,
    monday = 1,
    tuesday = 2,
    wednesday = 3,
    thursday = 4,
    friday = 5, 
    saturday = 6
};

// If you don't specifically assign a value, the first one will be 0 and so on.
enum Flavor {vanilla, chocolate, strawberry, mint}; 

int main() {
    // enums = a user-defined data type that consists of paired named-integer constants.
    // GREAT if you a set of potential options
    Day today = sunday;
    std::cout << "It is " << today << std::endl;

    return 0;
}