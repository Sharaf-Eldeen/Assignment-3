// Class definition for Pyramic _XO_App class
// Author:  Mahmoud Reda Sharaf Eldeen
//id: 20220318
// Date: 14/12/2023
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
#include "Player.cpp"
#include "PyramicBoard.cpp"
#include "PyramicPlayer.cpp"
#include "RandomPyramicPlayer.cpp"
#include "GameManager.cpp"
using namespace std;

int main() {
    int choice;
    PyramicPlayer* players[2];
    players[0] = new PyramicPlayer (1, 'x');

    cout << "Welcome to FCAI Pyramic X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new PyramicPlayer (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPyramicPlayer ('o', 3);

    GameManager Pyramic_X_O_Game (new PyramicBoard(), players);
    Pyramic_X_O_Game.run();
    system ("pause");
}
