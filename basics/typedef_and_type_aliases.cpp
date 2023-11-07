#include<iostream>
#include<vector>

typedef std::vector<std::pair<std::string, int>> pairlist_t;
//typedef std::string text_t;
//typedef int number_t;

using text_t = std::string;
using number_t = int;

int main(){

    pairlist_t pairList;
    text_t firstName = "Jurgen";
    number_t age = 28;

    std::cout << firstName << '\n';
    std::cout << age << '\n';

    return 0;
}

//    typedef = reserved keyword used to create an additional name (alias) for another data type.
//    New identifier for an existing type.
//    Helps with readability and reduces typos. 
//    Use when there is a clear benefit
//    Replaced with 'using' (works better with templates)
