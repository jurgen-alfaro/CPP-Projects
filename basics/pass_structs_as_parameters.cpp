#include <iostream>

struct Car {
    std::string model;
    int year;
    std::string color;
};

// When you pass a struct as a parameter, it's passed by value (a copy)
// If you need to use the original struct, use the address-of (&) operator
void printCar(Car car){
     std::cout << car.model << std::endl;
     std::cout << car.year << std::endl;
     std::cout << car.color << std::endl;
}

void paintCar(Car &car, std::string color){
    car.color = color;
}


int main() {
    Car car1;
    Car car2;

    car1.model = "Corolla";
    car1.year = 1994;
    car1.color = "Black";

    car2.model = "Trooper";
    car2.year = 1992;
    car2.color = "White";

    paintCar(car2, "Red");
    paintCar(car1, "Green");

    printCar(car1);
    printCar(car2);

    return 0;
}