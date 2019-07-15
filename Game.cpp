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
    Player* p = new HumanPlayer(0);
    players.push_back(p);
    for(int i = 1; i<nplayers; i++){
        Player* pai = new AIPlayer(i);
        players.push_back(pai);
    }
}

void Game::StartGame(){
    bool drawtwo = false;
    bool drawfour = false;
    deck->StartGame(players, pl);
    int winner;
    while(!gameover){
        cout << "the deck size is: " << deck->GetSize() << endl;
        if(deck->GetSize() <= 0 ){
            cout << "this is the pile card before: " << pl->GetTop() << endl;
            pl->RestartPile(deck->GetDeck());
            cout << "pile shuffled back into deck. this is the pile card now: " << pl->GetTop() << endl;
        }
        Player* x = players[tm->GetPlayerTurn()];
        if(drawtwo){
            x->TakeCard(deck->DealMeCard());
            x->TakeCard(deck->DealMeCard());
            drawtwo = false;
        }
        if(drawfour){
            x->TakeCard(deck->DealMeCard());
            x->TakeCard(deck->DealMeCard());            
            x->TakeCard(deck->DealMeCard());
            x->TakeCard(deck->DealMeCard());
            drawfour = false;
        }
        cout << "The card on the top of the pile is a " << *pl->GetTop() << endl;
        int result = x->Play(pl, deck);
        if(x->GetHandSize() <= 0){
            winner = x->GetPNumber() + 1;
            break;
        }
        if(result == 0){
            tm->NextTurn();
        }else if(result == 1){
            cout << "someone played a reverse." << endl;
            tm->Reverse();
            tm->NextTurn();
        }else if(result == 2){
            tm->SkipTurn();
        }else if(result == 3){
            //next player has to draw 2.
            drawtwo = true;
            tm->NextTurn();
        }else if(result == 4){
            drawfour = true;
            tm->NextTurn();
        }
    }
    cout << "GAME OVER! Player " << winner << " wins!" << endl;
    
}

void Game::PrintPlayerHands(){
    for(int i = 0; i<nplayers; i++){
        Player* x = players[i];
        x->PrintHand();
    }
}
