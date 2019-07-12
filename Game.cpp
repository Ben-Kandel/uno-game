/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: BenjaminK
 * 
 * Created on July 11, 2019, 10:21 AM
 */

#include "Game.h"

Game::Game(int p){
    nplayers = p;
    deck = new Deck();
    CreatePlayers();
    tm = new TurnManager(p);
    gameover = false;
    pl = new Pile();
}


void Game::CreatePlayers(){
    for(int i = 0; i<nplayers; i++){
        Player* p = new HumanPlayer(i); //right now we are just making all of them human players.
        players.push_back(p);
    }
}

void Game::StartGame(){
    deck->StartGame(players, pl);
    while(!gameover){
        Player* x = players[tm->GetPlayerTurn()];
        cout << "The card on the top of the pile is a " << pl->GetTop()->GetColor() << ":" << pl->GetTop()->GetNumber() << endl;
        int result = x->Play(pl, deck);
        if(result == 0){
            tm->NextTurn();
        }else if(result == 1){
            tm->Reverse();
            tm->NextTurn();
        }else if(result == 2){
            tm->SkipTurn();
        }else if(result == 3){
            //next player has to draw 2.
            tm->NextTurn();
        }
    }
    cout << "<<<<<< Game over? >>>>>>" << endl;
    
}

void Game::PrintPlayerHands(){
    for(int i = 0; i<nplayers; i++){
        Player* x = players[i];
        x->PrintHand();
    }
}
