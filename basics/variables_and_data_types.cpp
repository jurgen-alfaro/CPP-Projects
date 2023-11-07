#include <iostream>

int main(){

    // integer (whole numbers)
    int age = 21;
    int year = 2023;
    int days = 7;

    // double (number including decimal point)
    double price = 10.99;
    double gpa = 2.5;
    double temperature = 25.1;

    // char (single character)
    char grade = 'A';
    char initial = 'J';
    char currency = '$';

    // boolean (true or false)
    bool student = true; 
    bool power = false;
    bool for_sale = true;

    // string (objects that represent sequence of text)
    std::string name = "Jurgen";
    std::string day = "Friday";
    std::string food = "pizza";
    std::string address = "123 Fake Street";

    std::cout << "Hello " << name << '\n';
    std::cout << "You are " << age << " years old";

    return 0;
}