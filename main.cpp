// Class definition for main app
// Author:  Mahmoud Reda Sharaf Eldeen
//id: 20220318
// Date: 14/12/2023
// Version: 1


#include <iostream>
#include"../include/BoardGame_Classes.hpp"
#include "Player.cpp"
#include "RandomPlayer.cpp"
#include "X_O_Board.cpp"
#include "PyramicBoard.cpp"
#include "PyramicPlayer.cpp"
#include "RandomPyramicPlayer.cpp"
#include "GameManager.cpp"
using namespace std;

int main() {
    int chosenGame;
    cout << "The available games for you are: " << endl;
    cout << "1- X O App " <<endl;
    cout << "2- Pyramic X O App " <<endl;
    cout << "please choose the game to start: " << endl;
    cin >> chosenGame;
    while( chosenGame < 1 || chosenGame > 2 ) {
        cout << "1- X O App " <<endl;
        cout << "2- Pyramic X O App " <<endl;
        cin >> chosenGame;
    }
    if(chosenGame == 1) {
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x');

        cout << "Welcome to FCAI X-O Game. :)\n";
        cout << "Press 1 if you want to play with computer: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);

        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
        system ("pause");
    }else {
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
    
}
