#include <iostream>

double getTotal(double prices[], int size){

    double total = 0;
    for(int i = 0; i < size; i++) {
        total += prices[0];
    }

    return total;
} 

int main(){

    double prices[] = {49.99, 15.05, 75, 9.99};
    int size = sizeof(prices)/sizeof(prices[0]);

    // When you pass an array to a function it decase into a pointer
    // The function no longer knows the size of the array, so you need to pass its size
    double total = getTotal(prices, size);

    std::cout << "$" << total;
    return 0;
}