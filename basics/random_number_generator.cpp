#include <iostream>
#include <ctime>

int main() {
    // pseudo-random = NOT truly random (but close)
    srand(time(NULL));

    int num = (rand() % 20) + 1; // rolling a 20 sided dice, like in D&D!

    // Remember to add the +1 at the end so it does not include the 0 and includes the number you want (20 in this case)
    std::cout << num;

    return 0;   
}