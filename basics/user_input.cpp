#include<iostream>
#include <string>

// cout << (insertion operator)
// cin >> (extraction operator)

int main() {
    std::string name;
    int age;

    // std::cout << "What's your name? "; 
    // std::cin >> name;

    // If you need to capture a string that contains spaces, use the getline() function.
    std::cout << "What's your full name? "; 
    std::getline(std::cin, name);
    

    std::cout << "What's your age? ";
    std::cin >> age;

    std::cout << "Hello " << name << "\n";
    std::cout << "You're " << age << " years old";

    return 0;
}