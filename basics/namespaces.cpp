#include <iostream>

namespace first {
    int x = 1;
}

namespace second {
    int x = 2;
    int y = 5;
}

int main(){
    int x = 0; 

    std::cout << "Local x value is: " << x << "\n";
    std::cout << "First namespace x value is: " << first::x << "\n";
    std::cout << "Second namespace x value is: " << second::x << "\n";

    std::cout << second::y;

    return 0;
}

/* 
Namespace = provides a solution for preventing name conflicts
in large projects. Each entity needs an unique name. 
A namespace allows for identically named entitites 
as along as the namespaces are different

The :: is known as the scope resolution operator

If you want to use the value of a variable within a namespace
you need to prefix the namespace and then add the ::

Another way of using a namespace's variable is with 'using'. 

 */