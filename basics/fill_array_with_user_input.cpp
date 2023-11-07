#include <iostream>
#include <string>

int main(){
    std::string foods[5];
    int size = sizeof(foods)/sizeof(foods[0]);
    std::string temp;

    for(int i = 0; i < size; i++) {
        std::cout << "Enter a food you like or 'q' to quit #" << i << ": ";
        std::getline(std::cin, temp);
        if(temp == "q") break; 
        else foods[i] = temp;
    }

    std::cout << "You like the following food: " << std::endl;

    for(int i = 0; !foods[i].empty(); i++) { // do not display if item is empty
        std::cout << foods[i] << std::endl;
    }

    return 0;
}