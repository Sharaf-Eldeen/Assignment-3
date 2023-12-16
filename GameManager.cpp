// File name: Game manager
// Purpose: Problem 3
// Author(s): Yousuf Mounir Ramadan
// ID(s): 20210489
// Section: S17 & S18
// Date:16/12/2023
// Version: 1.0
#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
        }
    }
    int state = boardPtr->is_winner(players[0]->get_symbol(), players[1]->get_symbol());
    if (state == 1)
        cout << players[0]->to_string() << " wins\n";
    else if (state == -1)
        cout << players[1]->to_string() << " wins\n";
    else
        cout << "Draw!\n";
}

