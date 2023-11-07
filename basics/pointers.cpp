#include <iostream>

int main () {

    // pointers = variable that stores a memory address of another variable
    // sometimes it's easier to work with an address
    // & address-of operator
    // * dereference operator

    std::string name = "Jurgen";
    int age = 28;
    std::string freePizzas[5] = {"Pizza1", "Pizza2", "Pizza3", "Pizza4", "Pizza5"};

    std::string *pName = &name;
    int *pAge = &age;
    std::string *pFreePizzas = freePizzas; // No need to use address-of operator as the array is already an address

    std::cout << *pName << std::endl;
    std::cout << *pAge;

    return 0;
}