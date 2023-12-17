//
// Created by DELL on 12/17/2023.
//
#ifndef FOUR_IN_AROW_FOUR_IN_AROWBOARD_H
#define FOUR_IN_AROW_FOUR_IN_AROWBOARD_H
#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
using namespace std;


class Four_in_aRowBoard: public Board{
public:
    Four_in_aRowBoard();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};



#endif //FOUR_IN_AROW_FOUR_IN_AROWBOARD_H
