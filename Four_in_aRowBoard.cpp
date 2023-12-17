//
// Created by DELL on 12/17/2023.
//
//
//
//
#include "Four_in_aRowBoard.h"
Four_in_aRowBoard::Four_in_aRowBoard() {
    n_rows =6; n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
void Four_in_aRowBoard::display_board() {
    cout<<"  0   1   2   3   4   5   6\n";
    cout<<"______________________________\n";


    for (int i = 0; i <6 ; ++i) {
        cout<<i<<"|";


        for (int j = 0; j <7 ; ++j) {

//            if (board[i][j]== ' ')
//                cout<<"   |";


//            else
                cout << " " << board[i][j] << " |";

        }
        cout<<endl;
    }
    cout<<"==============================\n";
}
bool Four_in_aRowBoard::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
        return false;
}
bool Four_in_aRowBoard::is_winner() {
    for (int i = 0; i <n_rows ; ++i) {
        for (int j = 0; j < n_cols-3; ++j) {
            if (board[i][j]==board[i][j+1]&&board[i][j+1]== board[i][j+2]&& board[i][j+2]==board[i][j+3] && board[i][j]!=0) {
                return true;
            }

        }
    }
    for (int i = 0; i < n_rows-3; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (board[i][j]==board[i+1][j]&&board[i+1][j]== board[i+2][j]&& board[i+2][j]==board[i+3][j] && board[i][j]!=0) {
                return true;
            }
        }
    }
    for (int i = 0; i < n_rows-3; ++i) {
        for (int j = 0; j <n_cols-3 ; ++j) {
            if (board[i][j]==board[i+1][j+1]&&board[i+1][j+1]== board[i+2][j+2]&& board[i+2][j+2]==board[i+3][j+3] && board[i][j]!=0) {
                return true;
            }
        }
    }
    for (int i = 3; i < n_rows; ++i) {
        for (int j = 3; j <n_cols ; ++j) {
            if (board[i][j]==board[i-1][j-1]&&board[i-1][j-1]== board[i-2][j-2]&& board[i-2][j-2]==board[i-3][j-3] && board[i][j]!=0) {
                return true;
            }
        }
    }
    return false;
}

// Return true if 42 moves are done and no winner
bool Four_in_aRowBoard::is_draw() {
    return (n_moves ==42  && !is_winner());
}
bool Four_in_aRowBoard::game_is_over () {
    return n_moves >= 42;
}

