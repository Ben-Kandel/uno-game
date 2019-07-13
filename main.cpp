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
     * 5. ai players. //almost done. they don't know how to play wild cards yet,
     * and I kinda want to change the way they play regular cards..idk. maybe ill put it in a list of
     * priority or something. I definitely want them to always play their action cards if they can.
     * 6. testing the whole thing.
     
     */
    Game g(2);
    g.StartGame();
    return 0;
}

