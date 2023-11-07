#include<iostream>

int main() {
    char op; // operator
    double num1;
    double num2;
    double result;

    std::cout<<"************* CALCULATOR *************\n";

    std::cout <<"Enter either (+ - * /): ";
    std::cin >> op;

    std::cout << "Enter #1: ";
    std::cin >> num1;

    std::cout << "Enter #2: ";
    std::cin >> num2;

    switch (op)
    {
    case '+':
        result = num1 + num2;
        std::cout << "Result: " << result;
        break;
    case '-':
        result = num1 - num2;
        std::cout << "Result: " << result;
        break;
    case '*':
        result = num1 * num2;
        std::cout << "Result: " << result;
        break;
    case '/':
        if(num2 <= 0) {
            std::cout << "Division by 0 is not allowed";
            break;
        }
        result = num1 / num2;
        std::cout << "Result: " << result;
        break;
    
    default:
        std::cout << "That's not a valid operator!";
        break;
    }

    std::cout<<"\n**************************************";

    return 0;
}