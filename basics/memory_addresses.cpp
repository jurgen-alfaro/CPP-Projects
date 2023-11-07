#include <iostream>

int main() {
    // memory address = a location in memory where data is stored
    // a memory address can be accessed with & (address-of operator)

    std::string name = "Jurgen Alfaro";
    int age = 28;
    bool student = true;

    std::cout << &name << std::endl; 
    std::cout << &age << std::endl; 
    std::cout << &student << std::endl; 

    // the addresses are shown in hexadecimal format

    return 0;
}