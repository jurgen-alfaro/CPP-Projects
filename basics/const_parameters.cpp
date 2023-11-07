#include <iostream>

void printInfo(const std::string name, const int age){
    std::cout << name << std::endl;
    std::cout << age << std::endl;
}

int main() {
    // const parameters = parameters that is effectively read-only
    //                    the code is more secure & conveys intent
    //                    useful for references and pointers

    std::string name = "Jurgen";
    int age = 28;
    
    printInfo(name, age);

    return 0;
}