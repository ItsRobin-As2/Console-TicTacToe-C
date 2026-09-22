#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<windows.h>

int move, score = 0, comp_score = 0;
bool first = true;
char player, computer;
char board[9];

// Print Board in Console.
void printBoard(char player, char computer){
    printf(" %c | %c | %c \tPlayer: %c\n", board[0], board[1], board[2], player);
    printf("---|---|---\tComputer: %c\n", computer);
    printf(" %c | %c | %c\tScore: %d/%d\n", board[3], board[4], board[5], score, comp_score);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

// Selects a Character for Player(X/O).
char player_char(){
    int p = rand() % 2;
    return player = (p == 1) ? 'X' : 'O';
}

// Gives other Character to Computer.
char computer_char(char player){
    return (player == 'X') ? 'O' : 'X';
}

// Takes Player Input
int player_move(){  
    move = -1;
    int ch;
    while(!(move >= 1 && move <= 9) || board[move - 1] != ' '){
        printf("Enter Your Move(1-9): ");
        if(scanf("%d", &move) != 1){
            while((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        // if user enters a string of wrong input this line clears it.
        while((ch = getchar()) != '\n' && ch != EOF);
    }
    return move;
}

// Calculates computer move from 1 to 9 using recursion.
void computer_move(char computer){
    int c_move;
    Sleep(100);
    if(first){
        printf("Its First");
        while(board[c_move = (rand() % 5) * 2] != ' '){
            continue;
        }
        board[c_move] = computer;
        first = false;
    }else{
        while(board[c_move = rand() % 9] != ' '){
            continue;
        }
        board[c_move] = computer;
    }
}

// Checks if Player Wins each iteration.
bool playerWins(char player){
    if((board[0] == board[1] && board[1] == board[2] && board[0] == player) || 
       (board[3] == board[4] && board[4] == board[5] && board[3] == player) ||
       (board[6] == board[7] && board[7] == board[8] && board[6] == player) ||
       (board[0] == board[4] && board[4] == board[8] && board[0] == player) ||
       (board[2] == board[4] && board[4] == board[6] && board[2] == player)){
            return true;
    }
    return false;
}

// Checks if Computer Wins each iteration.
bool computerWins(char computer){
    if((board[0] == board[1] && board[1] == board[2] && board[0] == computer) || 
       (board[3] == board[4] && board[4] == board[5] && board[3] == computer) ||
       (board[6] == board[7] && board[7] == board[8] && board[6] == computer) ||
       (board[0] == board[4] && board[4] == board[8] && board[0] == computer) ||
       (board[2] == board[4] && board[4] == board[6] && board[2] == computer)){
            return true;
    }
    return false;
}

// Checks if its a draw by calculating how many places are filled
bool draw(){
    short count;
    for(int i = 0; i < 9; i++){
        if(board[i] == ' '){
            return false;
        }
    }
    return true;
}


int main(){
    char play_again;
    srand(time(NULL));
    do{
        player = player_char();
        computer = computer_char(player);

        // Fills board array with space.
        memset(&board, ' ', sizeof(board));

        while(true){
            system("cls");
            printf(">>TicTacToe\n");
            printf("`````````````\n");
            printBoard(player, computer);

            player_move();

            switch(move){
                case 1:
                    board[0] = player;
                    break;
                case 2: 
                    board[1] = player;
                    break;
                case 3:
                    board[2] = player;
                    break;
                case 4: 
                    board[3] = player;
                    break;
                case 5:
                    board[4] = player;
                    break;
                case 6: 
                    board[5] = player;
                    break;
                case 7:
                    board[6] = player;
                    break;
                case 8: 
                    board[7] = player;
                    break;
                case 9:
                    board[8] = player;
                    break;
                default:
                    printf("Wrong Input Try Again!\n");
                    Sleep(2000);
                    continue;
            }

            if(playerWins(player)){
                system("cls");
                printf(">>TicTacToe\n");
                printf("`````````````\n");
                printBoard(player, computer);
                printf("Congrats! Player '%c' Wins.\n", player);
                score++;
                break;
            }

            if(draw()){
                system("cls");
                printf(">>TicTacToe\n");
                printf("`````````````\n");
                printBoard(player, computer);
                printf(">>Its A Draw!\n");
                break;
            }
            
            computer_move(computer);

            if(computerWins(computer)){
                system("cls");
                printf(">>TicTacToe\n");
                printf("`````````````\n");
                printBoard(player, computer);
                printf("Alas! Player '%c' Lost.\n", player);
                comp_score++;
                break;
            }
            
        }
        first = true;
        printf("Play Again? (Y/N): ");
        scanf("%c", &play_again);
    }while(play_again == 'Y' || play_again == 'y');

    return 0;
}
