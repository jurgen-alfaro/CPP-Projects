#include <iostream>
#include <string>
#include <list>
#include <thread>
#include <chrono>

// to auto-generate ids
static int nextId = 1;

class TodoItem {
    private:
        int id;
        std::string description;
        bool completed = false;
    
    public:
        TodoItem(){}; // default constructor
        TodoItem(std::string description){
            this->id = nextId++;
            this->description = description;
        };
        ~TodoItem() = default; // destructor 

        // getters
        int getId() {return id;};
        std::string getDescription() {return description;};
        bool isCompleted() {return completed;};

        // setters
        void setCompleted(bool val) { completed = val;};
};

// List of todos
std::list<TodoItem> todosList;

void printTodosList(std::list<TodoItem> todosList) {
    std::list<TodoItem>::iterator it;

    if(todosList.empty()) {
        std::cout << "Add your first todo!" << std::endl;
    } else {
        for (it = todosList.begin(); it != todosList.end(); it++){
            std::string isCompleted = it->isCompleted() == true ? "done" : "not done";
            std::cout << it->getId() << " | " << it->getDescription() << " | " << isCompleted << std::endl;
        }
    }
}

void printOptionsMenu() {
    std::cout << "[a]dd a new Todo" << std::endl;
    std::cout << "[c]complete Todo" << std::endl;
    std::cout << "[q]uit" << std::endl;
    std::cout << "choice: ";
}

void performAction(char inputOption) {
    std::string inputDescription;
    int inputId;
    TodoItem newTodo;
    std::list<TodoItem>::iterator it;

    switch (inputOption) {
        case 'q':
            std::cout << "Have a great day now!" << std::endl;
            exit(0);
            break;

        case 'a':
            std::cout << "Enter a new description: "; 
            std::cin.clear(); // start with a fresh input buffer
            std::cin.ignore(); // ignore any characters in the buffer
            std::getline(std::cin, inputDescription);

            newTodo = TodoItem(inputDescription);
            todosList.push_back(newTodo);
            break;
        case 'c': 
            std::cout << "Enter id to mark completed: ";
            std::cin >> inputId;
            
            for(it = todosList.begin(); it != todosList.end(); it++){
                if(it->getId() == inputId){
                    it->setCompleted(true);
                    break;
                }
            }
            break;

        default:
            std::cout << "Invalid choice!" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
    }
}

int main () {
    char inputOption;
    std::string version = "v0.2.0";

    todosList.clear();

    while (true) {
        system("cls");
        std::cout << "******** Todo List Maker - " << version << " ********" << std::endl << std::endl;
        
        printTodosList(todosList);

        std::cout << std::endl;
        std::cout << "******************************************" << std::endl << std::endl;

        printOptionsMenu();
        std::cin >> inputOption;

        performAction(inputOption);
    }

    return 0;
}