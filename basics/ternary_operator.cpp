#include<iostream>

int main () {

    int grade = 75;
    grade >= 60 ? std::cout << "You pass!" : std::cout << "You fail!";

    int number = 9;
    number % 2 == 0 ? std::cout << "EVEN" : std::cout << "ODD";
    
   
    bool hungry = true;
    // hungry ? std::cout << "You are hungry" : std::cout << "You are full" << std::endl; 

    // If you want to print some text you could use this method instead

    std::cout << (hungry ? "You are hungry" : "You are full") << std::endl;

    return 0;
}