#include <iostream> 

struct student {
    std::string name; 
    double gpa; 
    bool enrolled = true;
};

int main() {

    // struct = A structure that groups related variables under one name
    // structs can contain many different data types (string, int, double, bool, etc.. )
    // variables in a struct are known as "members"
    // members can be accessed with . "Class Member Access Operator"

    student student1; 
    student1.name = "Jurgen";
    student1.gpa = 3.2;
    student1.enrolled = true;

    std::cout << student1.name << std::endl;
    std::cout << student1.gpa << std::endl;
    std::cout << student1.enrolled << std::endl; // bools are printed as numbers


    return 0;
}