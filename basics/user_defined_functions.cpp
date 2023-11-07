#include <iostream>

using namespace std;

void happyBirthday(string name, int age){
    cout << "Happy Birthday to " << name << endl;
    cout << "Happy Birthday to " << name << endl;
    cout << "Happy Birthday dear " << name << endl;
    cout << "Happy Birthday to " << name << endl;
    cout << "You are " << age << " years old" << endl;

}


int main() {
    // function = a block reusable code
    string name = "Jurgen";
    int age = 28;
    happyBirthday(name, age);
    
    return 0;
}