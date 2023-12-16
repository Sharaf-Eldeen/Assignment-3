// Class definition for Pyramic _XO_RandomPlayer class
// Which is a computer player playing randomly
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

// Set player symbol and name as Random Computer Player
RandomPyramicPlayer::RandomPyramicPlayer (char symbol, int dimension):PyramicPlayer(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Pyramic Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPyramicPlayer::get_move (int& x, int& y) {
    // Seed the random number generator with the current time
    srand(time(0));
    x = 10;
    while ( ( (x == 0) && (y == 0 || y == 1 || y == 3 || y == 4) ) || ( (x == 1) && (y == 0 || y == 4) ) || ( x > 6 ) ) {
        x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
        y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    }
}
