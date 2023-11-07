#include <iostream>

class Human {
    public:
        std::string name;
        std::string occupation;
        int age;

        void eat(){
            std::cout << "This person is eating" << std::endl;
        }
        void drink(){
            std::cout << "This person is drinking" << std::endl;
        }
        void sleep(){
            std::cout << "This person is sleeping" << std::endl;
        }
        
};

int main() {
    Human h1;
    h1.name = "Jurgen";
    h1.occupation = "Software Developer";
    h1.age = 28;

    std::cout << h1.name << std::endl;
    std::cout << h1.occupation << std::endl;
    std::cout << h1.age << std::endl;

    h1.eat();
    h1.drink();
    h1.sleep();

    return 0;
}