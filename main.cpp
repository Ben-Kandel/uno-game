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
     TODO: the next major thing is maybe creating a Pile class. it's just the easiest way
     * to have an open pile and still have it work, as well as remembering the color chosen for wild cards.
     * after that, we should work on representing wild cards and action cards correctly in the output.
     * also, we still need to add those wild cards to the deck. so maybe do the other things first.
     * 
     * priorities:
     * 1. pile class
     * 
     * we need to restructure some things here. there are too many events going on that have to be passed between multiple classes.
     * I need to sit down and think of a better solution.
     * 
     * 2. drawing cards when you don't have any available.
     * 3. cleaner output for the human players
     * 3. two human players successfully playing a game with regular cards
     * 4. wild cards.
     * 5. ai players.
     * 6. testing the whole thing.
     
     */
    
    //9 for blue
    //12 for red
    //10 for green
    //14 for yellow
    //15 for white
    
    Game g(2);
    //g.PrintDeck();
    
    g.StartGame();
    //g.PrintPlayerHands();
    
    //g.PrintDeck();
    
    return 0;
}

