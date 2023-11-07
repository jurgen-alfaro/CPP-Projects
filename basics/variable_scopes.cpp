#include <iostream>

int myNum = 3;

void printNum(){
    int myNum = 2;
    std::cout << myNum << std::endl;
}

int main() {
    int myNum = 1;
    printNum();
    std::cout << myNum << std::endl;

    // You use the scope resolution operator (::) to use a global variable instead of a local variable
    std::cout << ::myNum << std::endl;

    return 0;
}