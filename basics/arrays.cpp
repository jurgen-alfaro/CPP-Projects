#include <iostream>

int main() {

    // an array is a data structure that can hold multiple values
    // values are accessed by an index number
    // "kind of like a variable that holds multiple values"

    std::string cars[] = {"Trooper", "Corolla", "Mustang"};

    std::cout << cars << std::endl; // This prints the memory address where the array is located.
    std::cout << cars[0] << std::endl; // This prints 'Trooper'
    std::cout << cars[1] << std::endl; // This prints 'Corolla'
    std::cout << cars[2] << std::endl; // This prints 'Mustang'

    // To change a value
    cars[2] = "Camaro";

    // To add a new value to the array
    cars[3] = "Montero";

    return 0;
}