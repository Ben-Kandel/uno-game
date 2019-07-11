/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TurnManager.cpp
 * Author: BenjaminK
 * 
 * Created on July 11, 2019, 12:00 PM
 */

#include "TurnManager.h"

TurnManager::TurnManager(int nplayers){
    number_of_players = nplayers;
    currentturn = 0;
    dir = true;
}

int TurnManager::GetPlayerTurn(){
    return currentturn;
}

void TurnManager::NextTurn(){
    //here is where the logic comes in. positive dir means go forward. negative dir means go backward.
    if(dir){
        currentturn++;
    }else{
        currentturn--;
    }
    //say we have 3 players. we represent those by having 0, 1, or 2 as our current turn.
    //so a currentturn of 3 would be wrong.
    //and so would a currentturn of anything below 0
    if(currentturn >= number_of_players){
        currentturn = 0;
    }
    if(currentturn < 0){
        currentturn = number_of_players - 1;
    }
}

void TurnManager::SkipTurn(){
    NextTurn();
    NextTurn();
}