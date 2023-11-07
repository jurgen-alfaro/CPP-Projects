#include <iostream>

int main(){
    // fill() = Fills a range of elements with a specified value
    // fill(begin, end, value);

    const int SIZE = 99;
    std::string foods[SIZE];

    // fill(foods, foods + SIZE, "pizza");

    fill(foods, foods + (SIZE/3), "pizza"); // The first third will have pizza
    fill(foods + (SIZE/3), foods + (SIZE/3) * 2, "hamburger"); // The second third will have hamburger
    fill(foods + (SIZE/3) * 2, foods + SIZE, "hotdog"); // The second third will have hotdog

    for(std::string food : foods) {
        std::cout << food << std::endl;
    }

    return 0;
}