#include <iostream>

class Stove {
    private: 
        int temperature = 0;
    
    public: 
        Stove(int temperature){
            setTemperature(temperature);
        };
        int getTemperature(){
            return temperature;
        };
        void setTemperature(int temperature){
            if(temperature < 0){
                this->temperature = 0;
            } else if(temperature >= 10){
                this->temperature = 10;
            } else {
                this->temperature = temperature;
            }
        };
};

int main() {
    // Abstraction = Hiding unnecessary data from outside class.
    // GETTER = Function that makes a private attribute READABLE.
    // SETTER = Function that makes a private attribute WRITEABLE.

    Stove stove(1000);
    // stove.setTemperature(1000);
    std::cout << "The temperature setting is: " << stove.getTemperature();
    
    return 0;
}