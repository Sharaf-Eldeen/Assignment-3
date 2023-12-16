// Class definition for Pyramic_XO_Player class
// Author:  Mahmoud Reda Sharaf Eldeen
//id: 20220318
// Date: 14/12/2023
// Version: 1
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
PyramicPlayer::PyramicPlayer(char symbol):Player(symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
// PyramicPlayer constructor
PyramicPlayer::PyramicPlayer (int order, char symbol) : Player() {
    cout << "Welcome Pyramic Player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}


// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void PyramicPlayer::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x (0 to 2) and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

// Give player info as a string
string PyramicPlayer::to_string(){
    return "Pyramic Player: " + name ;
}

// Get symbol used by player
char PyramicPlayer::get_symbol() {
    return symbol;
}
