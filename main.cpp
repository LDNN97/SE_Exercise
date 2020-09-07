#include<iostream>

bool isWin(char game[3][3]){ 
    bool win = false; 
    if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true; 
    if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true; 
    if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true; 
    // column 
    if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true; 
    if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true; 
    if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true; 
    // diagonal 
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true; 
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true; 
    return win; 
} 
 
int main(){ 
    int i, j; 
    char game[3][3] = {' '}; // Tic-tac-toe 
    char player1 = 'X'; char player2 = 'O'; 
    bool turn = false; // false for player 1's turn, true for player 2's turn. Player 1 first. 

    std::cout << "X = Player 1" << std::endl << "O = Player 2" << std::endl; 
    int count = 0;
    while (count < 9) { 
        if (turn == false) 
            std::cout << "Player 1: "; 
        else 
            std::cout << "Player 2: "; 
        
        std::cout << "Which cell to mark? i:[0..2], j:[0..2]: ";  // !!!
        std::cin >> i >> j; 
        if ((i < 0) || (i > 2) || (j < 0) || (j > 2)) {
            std::cout << "input error" << std::endl;
            continue;
        }
        if (game[i][j] != ' ') {
            std::cout << "cell occupied" << std::endl;
            continue;
        }

        if (turn == false) 
            game[i][j] = player1; 
        else  
            game[i][j] = player2; 

        if (isWin(game)){ 
            std::cout << "Win!" << std::endl; 
            break; // need to terminate the problem 
        } 

        count += 1;
        if (count == 8) 
            std::cout << "Tie!" << std::endl;
        
        turn = !turn;
    }
    // show the game to console 
    std::cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << std::endl; 
    std::cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << std::endl; 
    std::cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << std::endl; 
    return 0; 
} 
