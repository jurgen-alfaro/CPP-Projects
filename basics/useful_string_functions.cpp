#include<iostream>
#include <string>

int main () {
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Length: " << name.length() << std::endl;
    std::cout << "Is empty? " << name.empty() << std::endl;
    std::cout << "Is empty? " << std::boolalpha << name.empty() << std::endl; // Use boolalpha to print 'true' or 'false' instead of 1 or 0.
    
    // name.clear();
    // std::cout << "Cleared name: " << name << std::endl;

    name.append("@gmail.com");
    std::cout << "Your username is now: " << name  << std::endl;
    std::cout << name.at(0)  << std::endl;
    
    name.insert(0, "@");
    std::cout << name << std::endl;
    std::cout << name.find("@") << std::endl;
    
    name.erase(0, 3);
    std::cout << name << std::endl;

    return 0;
}