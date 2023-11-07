#include <iostream>

int main() {

    // foreach loop eases the traversal over an iterable data set

    // std::string students[] = {"Spongebob", "Patrick", "Squidward"};
    int grades[] = {65, 72, 81, 93};

    for(int grade : grades){
        std::cout << grade << std::endl;
    }

    return 0;
}