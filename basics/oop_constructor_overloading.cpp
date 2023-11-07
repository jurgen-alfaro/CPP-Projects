#include <iostream>

class Pizza {
    public: 
        std::string topping1;
        std::string topping2;

        // Constructors
        Pizza(){
            // Empty constructor
        };
        Pizza(std::string topping1){
            this->topping1 = topping1;
        };
        Pizza(std::string topping1, std::string topping2){
            this->topping1 = topping1;
            this->topping2 = topping2;
        };
};


int main(){
    // overloaded constructors = This is when we have multiple constructors with the same name but different parameters.
    // This allows for varying arguments when instantiating an object.

    Pizza p1("pepperoni");
    Pizza p2("mushrooms", "peppers");
    Pizza p3; // If you pass no arguments, you don't need parenthesis
    std::cout << p1.topping1 << std::endl;
    std::cout << p2.topping1 << std::endl;
    std::cout << p2.topping2 << std::endl;

    return 0;
}