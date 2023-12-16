// Class definition for Pyramic _X_O_Board class
// Author:  Mahmoud Reda Sharaf Eldeen
//id: 20220318
// Date: 14/12/2023
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
PyramicBoard::PyramicBoard () {
    n_rows = 3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
       board [i] = new char[n_cols];
       for (int j = 0; j < n_cols; j++)
          board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool PyramicBoard::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void PyramicBoard::display_board() {
   for (int i: {0,1,2}) {
      cout<< "\n";
      if ( i == 2) {
         cout<<"|";
      }else {
         cout << " ";
      }
      
      //cout << "\n| ";
      for (int j: {0,1,2,3,4}) {
         if((i==0 &&(j==2))) {
            cout << " |";
         }
         if ((i==0 &&(j==0||j==1||j==3||j==4))) {
            cout << "       ";
            continue;
         }
         if ((i==1 &&(j==1))) {
            cout << " |";
         }
          if ((i==1 &&(j==0||j==4))) {
            cout << "      ";
            continue;
         }
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n--------------------------------------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool PyramicBoard::is_winner() {
    if ( ( (board[0][2] == board[1][3] && board[1][3] == board[2][4]) && (board[0][2] != 0) ) || ( (board[0][2] == board[1][1] && board[1][1] == board[2][0]) && (board[0][2] != 0) ) ){
      return true;
    } else if ( ( (board[1][1] == board[1][2] && board[1][2] == board[1][3]) && (board[1][1] != 0) ) ){
      return true;
    } else if ( ( (board[2][0] == board[2][1] && board[2][1] == board[2][2]) && (board[2][0] != 0) ) || ( (board[2][1] == board[2][2] &&  board[2][2] == board[2][3]) && (board[2][1] != 0) ) || ( (board[2][2] == board[2][3] && board[2][3] == board[2][4]) && (board[2][2] != 0) ) ){
      return true;
    } else if ( (board[0][2] == board[1][2] && board[1][2] == board[2][2]) && (board[0][2] != 0) ) {
      return true;
    } else {
      return false;
    }
}

// Return true if 9 moves are done and no winner
bool PyramicBoard::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool PyramicBoard::game_is_over () {
    return n_moves >= 9;
}
