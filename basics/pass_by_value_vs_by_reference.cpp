#include <iostream>

void swap(std::string &x, std::string &y){
    std::string temp; 
    temp = x; 
    x = y;
    y = temp;
}

int main() {
    std::string x = "Kool-Aid";
    std::string y = "Water";

    swap(x, y);

    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;

    return 0;
}