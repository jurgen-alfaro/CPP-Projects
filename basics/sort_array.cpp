#include <iostream>

// This example uses a bubble sort approach to sort the array
// The idea is to go from the first element to the last one
// If the first is greater than the second one, save the first element in a 'temp' variable,
// then move the second element to the first, and then move the temp value to the second


void sort(int array[], int size) {
    int temp;

    for(int i = 0; i < size - 1; i++) { // -1 because we don't need to check the last element of the array
        for(int j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(){

    int array[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(array)/sizeof(array[0]);

    sort(array, size);

    for(int element : array) {
        std::cout << element << " ";
    }

    return 0;
}