/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: BenjaminK
 *
 * Created on July 11, 2019, 10:17 AM
 */

#include <iostream>
using std::cout; using std::endl; using std::cin;
#include <ostream>
#include <windows.h>
#include "Card.h"
#include "Game.h"


/*
 * 
 */
int main(int argc, char** argv) {
    int human_players, ai_players;
    cout << "Please enter how many human players there are: ";
    cin >> human_players;
    cout << endl;
    cout << "Please enter how many AI players there are: ";
    cin >> ai_players;
    cout << endl;
    Game g(human_players, ai_players);
    g.StartGame();
    return 0;
}

