/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: BenjaminK
 *
 * Created on July 11, 2019, 10:21 AM
 */

#ifndef GAME_H
#define GAME_H

#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;
#include <algorithm>
using std::random_shuffle;

#include "Card.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "TurnManager.h"
#include "Pile.h"
#include "Deck.h"

class Game {
public:
    Game(int p);
    //~Game();
    void StartGame();
    void PrintPlayerHands();
private:
    void CreatePlayers();
    void DealCards(int p, int cards);
    int nplayers;
    vector<Player*> players;
    TurnManager* tm;
    Pile* pl;
    bool gameover;
    Deck* deck;
};

#endif /* GAME_H */

