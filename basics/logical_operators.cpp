#include<iostream>

int main() {

    // && = check if two conditions are true
    // || = check if at least one of two conditions are true
    // !  = reverses the logical state of its operand

    int temp;
    bool sunny = true;

    std::cout << "Enter the temperature: ";
    std::cin >> temp;

    // Check if temp in Celsius
    if(temp > 0 && temp < 30){
        std::cout << "The temperature is good!\n";
    } else {
        std::cout << "The temperature is bad\n";
    }

    if(sunny){
        std::cout << "It is sunny outside";
    } else {
        std::cout << "It is cloudy outside";
    }

    return 0;
}