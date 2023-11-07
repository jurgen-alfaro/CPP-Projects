#include <iostream>

// Parent class
class Animal{
    public:
        bool alive = true;

        void eat() {
            std::cout << "This animal is eating" << std::endl;
        };
};

// Children classes
class Dog : public Animal {
    public: 
        void bark() {
            std::cout << "The dog goes woof!" << std::endl;
        }

};

class Cat : public Animal {
    public:

        void meow() {
            std::cout << "The cat goes meow!" << std::endl;
        };
};

int main() {

    Dog dog;
    Cat cat; 

    std::cout << dog.alive << std::endl;
    dog.eat();
    dog.eat();

    std::cout << cat.alive << std::endl;
    cat.eat();
    cat.meow();

    return 0;
}