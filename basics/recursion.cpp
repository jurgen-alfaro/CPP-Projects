#include <iostream>

int factorial(int num){
    if(num > 1){
        return num * factorial(num - 1);
    } else {
        return 1;
    }
}


int main() {

    // recursion = a programming technique where a function invokes itself from within.
    // break a complex concept into a repeatable single step

    // advantages
    // less code and is cleaner
    // user for sorting and searching algorithms

    // disadvantages
    // uses more memory and is slower'

    return 0;
}