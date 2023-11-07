#include <iostream>
#include <ctime>

void drawBoard(char *spaces){
    std::cout << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "   " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "   " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "   " << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << std::endl;
}


void playerMove(char *spaces, char player){
    int number;
    do {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--; // Remember the array starts with 0, but the user doesn't know :P
        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
    } while (!number > 0 || !number < 8);
    system("cls");
}
void computerMove(char *spaces, char computer){
    int number;
    srand(time(0));

    while(true) {
        number = rand() % 9;
        if(spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer){
    
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
        spaces[0] == player ? std::cout << "YOU WIN!" << std::endl : std::cout << "YOU LOSE!" << std::endl;
    } else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? std::cout << "YOU WIN!" << std::endl : std::cout << "YOU LOSE!" << std::endl;
    } else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? std::cout << "YOU WIN!" << std::endl : std::cout << "YOU LOSE!" << std::endl;
    } else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? std::cout << "YOU WIN!" << std::endl : std::cout << "YOU LOSE!" << std::endl;
    } else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout << "YOU WIN!" << std::endl : std::cout << "YOU LOSE!" << std::endl;
    } else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout << "YOU WIN!" << std::endl : std::cout << "YOU LOSE!" << std::endl;
    } else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? std::cout << "YOU WIN!" << std::endl : std::cout << "YOU LOSE!" << std::endl;
    } else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? std::cout << "YOU WIN!" << std::endl : std::cout << "YOU LOSE!" << std::endl;
    } else {
        return false;
    }

    return true;
}
bool checkTie(char *spaces){
    for(int i = 0; i < 9; i++) {
        if(spaces[i] == ' ') {
            return false;
        }
    }
    std::cout << "IT'S A TIE!" << std::endl;
}


int main() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces); // When you pass an array to a function it decases to a pointer

    while(running){
        playerMove(spaces, player);
        drawBoard(spaces);

        if(checkWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (checkTie(spaces)){
            running = false;
            break;
        }

        computerMove(spaces, computer);
        drawBoard(spaces);

        if(checkWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (checkTie(spaces)){
            running = false;
            break;
        }
    }
    std::cout << "THANKS FOR PLAYING! :)" << std::endl;

    return 0;
}