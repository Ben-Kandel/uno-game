/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TurnManager.h
 * Author: BenjaminK
 *
 * Created on July 11, 2019, 12:00 PM
 */

#ifndef TURNMANAGER_H
#define TURNMANAGER_H

class TurnManager {
public:
    TurnManager(int nplayers);
    void NextTurn();
    void SkipTurn();
    int GetPlayerTurn();
private:
    bool dir; //true will mean going forward in the loop. false will mean going backward.
    int currentturn; //0 technically means player 1...maybe i'll fix it later.
    int number_of_players;
};

#endif /* TURNMANAGER_H */

