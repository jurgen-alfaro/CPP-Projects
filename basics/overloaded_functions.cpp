#include <iostream>

using namespace std;

void bakePizza(){
    cout << "Here is your pizza!" << endl;
}

void bakePizza(string topping1){
    cout << "Here is your" << topping1 << " pizza!" << endl;
}

void bakePizza(string topping1, string topping2){
    cout << "Here is your" << topping1 << "and " << topping2 << " pizza!" << endl;
}

int main() {
    bakePizza();
    bakePizza("pepperoni");
    bakePizza("pepperoni", "pineapple");

    return 0;
}