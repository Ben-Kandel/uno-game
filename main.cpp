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
#include <ostream>
#include <windows.h>
#include "Card.h"
#include "Game.h"


/*
 * 
 */
int main(int argc, char** argv) {
    /*
     TODO:
     * 4. wild cards. //almost done, just working on the color picking functionality
     * 5. ai players.
     * 6. testing the whole thing.
     
     */
    
    //9 for blue
    //12 for red
    //10 for green
    //14 for yellow
    //15 for white
    
    Game g(3);
    //g.PrintDeck();
    
    g.StartGame();
    //g.PrintPlayerHands();
    
    //g.PrintDeck();
    
    return 0;
}

