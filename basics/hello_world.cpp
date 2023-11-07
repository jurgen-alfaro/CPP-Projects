#include <iostream> 
/* In C++, #include <iostream> is a preprocessor directive that includes the standard input/output library, 
allowing you to use functions like cout and cin for input and output operations in your C++ program. */

// The main function is where the program begins
int main(){
    std::cout << "I like pizza!" << std::endl;
    std::cout << "It's really good!\n";
    return 0;
}

/* 
Additional comments:
- Using std::endl will clear the output buffer, using \n will not.
- std means 'standard'
- cout means 'character output'
 */