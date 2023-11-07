#include <iostream>

int main() {

    // dynamic memory = Memory that's allocated after the program is already compiled & running
    // Use the 'new' operator to allocate memory in the heap rather than the stack

    // Useful when we don't know how much memory we will need. Makes our programs more flexible,
    // especially when accepting user input

    int *pNum = NULL; // <- Best practice to set pointer to NULL if it's not assigned at creation

    pNum = new int; // The new operator will return an address 
    *pNum = 21; 
    std::cout << "Address: " << pNum << std::endl; //Address: 0x1bdef561ab0 (this is in the heap)
    std::cout << "Value: " << *pNum << std::endl; // Value: 21

    // When you are no longer using the memory space, make sure to use the 'delete' operator
    // to free up space

    delete pNum;

    return 0;

}