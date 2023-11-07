#include <iostream>

class Student {
    public:
        std::string name;
        int age;
        double gpa;
    
    // Constructor
    Student(std::string name, int age, double gpa) {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    };
};

int main(){
    // A special method that is automatically called when an object is instantiated. 
    //It is useful for assigning values to attributes as arguments

    Student s1("Jurgen", 28, 3.5);

    std::cout << s1.name << std::endl;
    std::cout << s1.age << std::endl;
    std::cout << s1.gpa << std::endl;

    return 0;   
}