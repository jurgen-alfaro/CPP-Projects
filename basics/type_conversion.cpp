#include<iostream>

int main() {

    // type conversion = conversion a value of one data type to another
    //                      Implicit = automatic
    //                      Explicit = precede value with new data type (int)

    int x = 3.14;
    std::cout << (double)x;

    // char x = 100; // Remember that 'char' will convert to its ASCII decimal representation, which is 'd'
    // std::cout << (char)100;

    // int correct = 8;
    // int questions = 10;
    // double score = correct/(double)questions*100;

    // std::cout << score << "%\n";



    return 0;
}