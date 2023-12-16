// File name: 5 x 5 Tic Tac Toe board
// Purpose: Problem 3
// Author(s): Yousuf Mounir Ramadan
// ID(s): 20210489
// Section: S17 & S18
// Date:16/12/2023
// Version: 1.0

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
X_O_Board::X_O_Board () {
   n_rows = n_cols = 5;
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
bool X_O_Board::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > n_rows || y < 0 || y > n_cols) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
   for (int i: {0,1,2,3,4}) {
      cout << "\n| ";
      for (int j: {0,1,2,3,4}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(4) << board [i][j] << " |";
      }
      cout << "\n------------------------------------";
   }
   cout << endl;
}

// Returns 1 if X wins, -1 if Y wins, or 0 otherwise
int X_O_Board::is_winner(char p1_symbol, char p2_symbol) {
    bool valid[5][5];
    // All cell are available are not checked at begining.
    memset(valid, true, sizeof valid);
    int p1_cnt = 0, p2_cnt = 0;
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {

            // Check Diagonals.
            if (i + 2 < n_rows && j + 2 < n_cols
                && valid[i][j] && valid[i + 1][j + 1] && valid[i + 2][j + 2]
                && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2])
            {
                if (board[i][j] = p1_symbol) p1_cnt++;
                else p2_cnt++;
                valid[i][j] = valid[i + 1][j + 1] = valid[i + 2][j + 2] = false;
            }

            // Check Columns.
            if (i + 2 < n_rows
                && valid[i][j] && valid[i + 1][j] && valid[i + 2][j]
                && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j])
            {
                if (board[i][j] = p1_symbol) p1_cnt++;
                else p2_cnt++;
                valid[i][j] = valid[i + 1][j] = valid[i + 2][j] = false;
            }

            // Check Rows.
            if (j + 2 < n_rows
                && valid[i][j] && valid[i][j + 1] && valid[i][j + 2]
                && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2])
            {
                if (board[i][j] = p1_symbol) p1_cnt++;
                else p2_cnt++;
                valid[i][j] = valid[i][j + 1] = valid[i][j + 2] = false;
            }
        }
    }
    // Draw State
    if (p1_cnt == p2_cnt) return 0;
    else if (p1_cnt > p2_cnt) return 1;
    else return -1;
}

bool X_O_Board::game_is_over () {
    return n_moves >= 24;
}
