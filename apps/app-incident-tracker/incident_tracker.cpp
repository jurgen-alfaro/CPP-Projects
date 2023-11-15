#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <memory>
#include <thread>
#include <chrono>

std::string VERSION = "v0.2.0";
static int nextId = 1; // to auto-generate ids

enum Severity: int {
    HIGH = 1,
    MEDIUM = 2,
    LOW = 3
};

// Base class
class Incident {
    private:
        int ticketNum;
        int priority;
        int duration; // in hours
        Severity severity;
        std::string name;
        std::string description;
    
    public: 
        // constructor
        Incident(int priority, int duration, Severity severity, std::string& name, std::string& description){
            this->ticketNum = nextId++; // increment ticket num
            this->priority = priority;
            this->duration = duration;
            this->severity = severity;
            this->name = name;
            this->description = description;
        }
        // destructor
        ~Incident() = default; // destructor 

        virtual double calculateTotalCost() = 0; // pure virtual function
        
        void exportXML() {
            // TODO - Create a method that exports the list of incidents into XML format
        };

        // Getters
        int getTicketNum(){ return this->ticketNum; };
        int getPriority(){ return this->priority; };
        int getDuration(){ return this->duration; };
        Severity getSeverity(){ return this->severity; };
        std::string getName(){ return this->name; };
        std::string getDescription(){ return this->description; };

        // Setters
        void setTicketNum(int ticketNum){
            if(ticketNum > 0 && std::abs(ticketNum) < 100000){
                this->ticketNum = ticketNum;
            }
        };
        void setPriority(int priority){
            // must be between 1 and 5
            if(priority >= 1 && priority <= 5){  
                this->priority = priority;
            }
        };
        void setDuration(int duration){
            // min hours allowed = 1 | max hours allowed = 48
            if(duration >= 1 && duration <= 48){
                this->duration = duration;
            }
        };
        void setSeverity(Severity severity){
            this->severity = severity;
        };
        void setDescription(std::string description){
            this->description = description;
        };
};

// Incidents list
std::list<std::unique_ptr<Incident>> incidentsList;

// Derived classes
class Internet : public Incident {
    private:
        const int BASE_COST = 1500; // internet base cost
        std::string name;

    public:
        Internet(int priority, int duration, Severity severity, std::string& name, std::string& description)
            : Incident(priority, duration, severity, name, description){
                this->name = "Internet";
            }
        ~Internet() = default;
        
        std::string getName(){ return this->name; }

        double calculateTotalCost() override {
            double totalCost = 0;
            totalCost += BASE_COST;

            // priority cost
            if(this->getPriority() == 1 || this->getPriority() == 2){
                totalCost += 200;
            } else { // priority 3, 4, or 5
                totalCost += 150;
            }

            // duration cost
            if(this->getDuration() >= 1 || this->getDuration() <= 12){
                totalCost += 130;
            } else if(this->getDuration() >= 13 || this->getDuration() <= 24){
                totalCost += 135;
            } else { // if duration is between 25 and 48
                totalCost += 140;
            }

            // severity cost
            if(this->getSeverity() == HIGH) {
                totalCost += (totalCost * 0.085);
            } else if(this->getSeverity() == MEDIUM) {
                totalCost += (totalCost * 0.09);
            } else { // LOW
                totalCost += (totalCost * 0.095);
            }

            return totalCost;
        }
};

class Phone : public Incident {
    private:
        const int BASE_COST = 750; // phone base cost
        std::string name;

    public: 
        Phone(int priority, int duration, Severity severity, std::string& name, std::string& description)
            : Incident(priority, duration, severity, name, description){
                this->name = "Phone";
            }
        ~Phone() = default;
        std::string getName(){ return this->name; }
    
        double calculateTotalCost() override {
            double totalCost = 0;
            totalCost += BASE_COST;

            // priority cost
            if(this->getPriority() == 1 || this->getPriority() == 2){
                totalCost += 90;
            } else { // priority 3, 4, or 5
                totalCost += 80;
            }

            // duration cost
            if(this->getDuration() >= 1 || this->getDuration() <= 12){
                totalCost += 100;
            } else if(this->getDuration() >= 13 || this->getDuration() <= 24){
                totalCost += 110;
            } else { // if duration is between 25 and 48
                totalCost += 125;
            }

            // severity cost
            if(this->getSeverity() == HIGH) {
                totalCost += (totalCost * 0.035);
            } else if(this->getSeverity() == MEDIUM) {
                totalCost += (totalCost * 0.045);
            } else { // LOW
                totalCost += (totalCost * 0.055);
            }

            return totalCost;
        }
};

class Television : public Incident {
    private:
        const int BASE_COST = 1000; // television base cost
        std::string name;

    public: 
        Television(int priority, int duration, Severity severity, std::string& name, std::string& description)
            : Incident(priority, duration, severity, name, description){
                this->name = "Television";
            }
        ~Television() = default;

        std::string getName(){ return this->name; }

        double calculateTotalCost() override {
            double totalCost = 0;
            totalCost += BASE_COST;

            // priority cost
            if(this->getPriority() == 1 || this->getPriority() == 2){
                totalCost += 150;
            } else { // priority 3, 4, or 5
                totalCost += 100;
            }

            // duration cost
            if(this->getDuration() >= 1 || this->getDuration() <= 12){
                totalCost += 120;
            } else if(this->getDuration() >= 13 || this->getDuration() <= 24){
                totalCost += 140;
            } else { // if duration is between 25 and 48
                totalCost += 160;
            }

            // severity cost
            if(this->getSeverity() == HIGH) {
                totalCost += (totalCost * 0.08);
            } else if(this->getSeverity() == MEDIUM) {
                totalCost += (totalCost * 0.06);
            } else { // LOW
                totalCost += (totalCost * 0.04);
            }
            
            return totalCost;
        }
};

void addIncidentToList(std::unique_ptr<Incident> incident){
    incidentsList.push_back(std::move(incident)); // remember to move the unique pointer ownership to the list
    std::cout << std::endl;
    std::cout << "Incident added to the list!" << std::endl << std::endl;
}

std::unique_ptr<Incident> registerIncident(std::string& name, std::string& description, int priority, int duration, Severity severity){
    if(name == "Television"){
        return std::make_unique<Television>(priority, duration, severity, name, description);
    } else if(name == "Internet"){
        return std::make_unique<Internet>(priority, duration, severity, name, description);
    } else if(name == "Phone"){
        return std::make_unique<Phone>(priority, duration, severity, name, description);
    } else {
        std::cerr << "Invalid incident type: " << name << std::endl;
        return nullptr;
    }
}

void displayRegisterIncidentForm(){
    char inputOption;
    char severityChoice;
    std::string name;
    std::string description;
    int priority;
    int duration;
    Severity severity;

    while(true) {
        system("cls");
        std::cout << "++++++++ REGISTER INCIDENT ++++++++" << std::endl << std::endl;
        std::cout << "Enter incident type: " << std::endl;
        std::cout << "[t]elevision" << std::endl;
        std::cout << "[i]nternet" << std::endl;
        std::cout << "[p]hone" << std::endl;
        std::cout << "[b]ack to previous menu" << std::endl << std::endl;
        std::cout << "choice: ";
        std::cin >> inputOption;

        if(inputOption == 'b') break; // return to previous menu
        else if(inputOption == 't' || inputOption == 'i' || inputOption == 'p'){
            switch (inputOption){
                case 't':
                    name = "Television";
                    break;
                case 'i':
                    name = "Internet";
                    break;
                case 'p':
                    name = "Phone";
                    break;
            }

            while(description.length() == 0){
                std::cout << "Enter incident description: ";
                std::cin.clear(); // start with a fresh input buffer
                std::cin.ignore(); // ignore any characters in the buffer
                std::getline(std::cin, description);
            }

            while(priority < 1 || priority > 5) {
                std::cout << "Enter incident priority (1 to 5): ";
                std::cin >> priority;
            }

            while(duration < 1 || duration > 48) {
                std::cout << "Enter incident duration (min: 1 hour| max: 48 hours): ";
                std::cin >> duration;
            }

            while(true){
                std::cout << "Enter incident severity ([h]igh, [m]edium, [l]ow): ";
                std::cin >> severityChoice;

                if(severityChoice == 'h') {
                    severity = HIGH;
                    break;
                } else if(severityChoice == 'm') {
                    severity = MEDIUM; 
                    break;
                } else if(severityChoice == 'l') {
                    severity = LOW;
                    break;
                }
            }

            // Create incident unique pointer 
            std::unique_ptr<Incident> incident = registerIncident(name, description, priority, duration, severity);

            if(incident) {
                // add incident to incidents list
                addIncidentToList(std::move(incident)); // transfer/move the ownership of the local 'incident' to the list

                std::cout << "[r]egister new incident" << std::endl;
                std::cout << "[b]ack to main menu" << std::endl;
                std::cout << "choice: ";
                std::cin >> inputOption; // reassigning inputOption
                
                if(inputOption == 'b') break;
                else {
                    // reset variables
                    severityChoice = ' ';
                    name = "";
                    description = "";
                    priority = 0;
                    duration = 0;                    
                };
            }
        }
        



    }
}

void displayIncidentsList() {
    std::list<Incident>::iterator it;
    char inputOption;
   
    while(inputOption != 'b') {
        system("cls");
        std::cout << "++++++++ INCIDENTS LIST ++++++++" << std::endl << std::endl;
        if(incidentsList.empty()){
            std::cout << "Incidents list is empty.\nRegister your first incident!" << std::endl << std::endl;
            std::cout << "++++++++++++++++++++++++++++++++" << std::endl << std::endl;
        } else {
            for (auto it = incidentsList.begin(); it != incidentsList.end(); it++){
                std::unique_ptr<Incident>& pIncident = *it; // pointer to the iterator
                std::string sev = pIncident->getSeverity() == 1 ? "HIGH" : pIncident->getSeverity() == 2 ? "MEDIUM" : "LOW";

                std::cout << "Incident #: \t" << pIncident->getTicketNum() << std::endl;
                std::cout << "Type: \t\t" << pIncident->getName() << std::endl;
                std::cout << "Description: \t" << pIncident->getDescription() << std::endl;
                std::cout << "Priority: \t" << pIncident->getPriority() << std::endl;
                std::cout << "Duration: \t" << pIncident->getDuration() << std::endl;
                std::cout << "Severity: \t" << sev << std::endl;
                std::cout << "Total cost: \t" << std::fixed << std::setprecision(2) << "$" << pIncident->calculateTotalCost() << std::endl; // max 2 decimal spaces
                std::cout << "++++++++++++++++++++++++++++++++" << std::endl;
            }
        }

        std::cout << "[b]ack to main menu" << std::endl;
        std::cout << "[e]xport XML" << std::endl;
        std::cout << "choice: ";
        std::cin >> inputOption;

        if(inputOption == 'b') break;
        else if (inputOption == 'e') {
            if(incidentsList.empty()) {
                std::cerr << "Cannot export XML. Incidents list is empty!" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2)); // sleep for 1 second, then clear screen
                system("cls");
            }
        }
    }
}

int main() {
    char inputOption;
  
    while(true) {
        system("cls"); // clear screen
        std::cout << "++++++++ INCIDENT TRACKER APP - " << VERSION << " ++++++++" << std::endl << std::endl;
        std::cout << "Enter an option: " << std::endl;
        std::cout << "[i]ncidents list" << std::endl;
        std::cout << "[r]egister incident" << std::endl;
        std::cout << "[q]uit" << std::endl << std::endl;
        std::cout << "choice: ";
        std::cin >> inputOption;

        if(inputOption == 'q'){
            std::cout << "Have a great day now!" << std::endl;
            break;
        } else if(inputOption == 'r'){
            displayRegisterIncidentForm();
        } else if(inputOption == 'i') {
            displayIncidentsList();
        }
    }

    return 0;
}