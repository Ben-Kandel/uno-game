/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HumanPlayer.h
 * Author: BenjaminK
 *
 * Created on July 11, 2019, 10:59 AM
 */

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player{
public:
    HumanPlayer(int n);
    virtual int Play(Pile* pl); //here is where we ask for user input.
    //the AI player's implementation is just the algorithm playing the first available card
private:
    //nothing
};

#endif /* HUMANPLAYER_H */

