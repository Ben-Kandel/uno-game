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
using std::cout; using std::endl;

#include "Card.h"
#include "Game.h"


/*
 * 
 */
int main(int argc, char** argv) {
    cout << "testing" << endl;
    
    Game g(2);
    g.PrintDeck();
    
    g.StartGame();
    g.PrintPlayerHands();
    
    g.PrintDeck();
    
    return 0;
}

