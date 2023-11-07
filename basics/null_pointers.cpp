#include <iostream>

int main() {
    // Null value = a special value that means something has no value.
    //              when a pointer is holding a null value,
    //              that pouinter is not pointing at anything (null pointer)

    // nullptr = keywor represents a null pointer literal

    // nullptrs are helpful when determining if an address
    // was successfully assigned to a pointer.

    int *pointer = nullptr; // Is best practice to assign a pointer a nullptr if it's not going to be assigned right away
    int x = 123;

    pointer = &x;
    *pointer;

    if(pointer == nullptr) {
        std::cout << "Address was not assigned!" << std::endl;
    } else {
        std::cout << "address was assigned!" << std::endl;
        std::cout << &pointer;
    }

    return 0;
}