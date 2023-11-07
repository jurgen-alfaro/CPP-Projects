#include <iostream> 

int main() {
    // determines the size in bytes of a:
    // variable, data type, class, objects, etc...

    double gpa = 2.5;
    std::string name = "Jurgen Alfaro";
    char grade = 'F';   
    bool student = true;
    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    std::string students[] = {"Spongebob", "Patrick", "Squidward", "Sandy"};

    std::cout << sizeof(gpa) << " bytes\n";
    std::cout << sizeof(name) << " bytes\n";
    std::cout << sizeof(grade) << " bytes\n";
    std::cout << sizeof(student) << " bytes\n";
    std::cout << sizeof(grades) << " bytes\n";
    std::cout << sizeof(students) << " bytes\n";
    std::cout << sizeof(students)/sizeof(std::string) << " elements\n"; // This is to determine how many elements are in the array

    return 0;
}