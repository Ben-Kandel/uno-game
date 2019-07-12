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
    CreateCards(deck);
    CreatePlayers();
    tm = new TurnManager(p);
    gameover = false;
    pl = new Pile();
    DealCards(-1, 1); //giving the pile one card.
}

Game::~Game(){
    for(Card* x : deck){
        free(x);
    }
}

void Game::CreateCards(vector<Card*> &d){
    //okay. so..the cards. the colors are 'r', 'g', 'b', 'y', 'w' w is wild by the way
    //we're representing the action cards like skip, reverse, and draw 2 with just 10, 11, and 12 respectively, but the players
    //will see them in their normal form
    //10 = skip, 11 = reverse, 12 = draw 2
    for(int i = 0; i <= 12; i++){
        Card* a = new Card('r', i);
        Card* b = new Card('g', i);
        Card* c = new Card('b', i);
        Card* dd = new Card('y', i);
        d.push_back(a);
        d.push_back(b);
        d.push_back(c);
        d.push_back(dd);
    }
    for(int i = 1; i <= 12; i++){
        Card* a = new Card('r', i);
        Card* b = new Card('g', i);
        Card* c = new Card('b', i);
        Card* dd = new Card('y', i);
        d.push_back(a);
        d.push_back(b);
        d.push_back(c);
        d.push_back(dd);
    }
    random_shuffle(d.begin(), d.end()); //randomly shuffle the deck.
}

void Game::CreatePlayers(){
    for(int i = 0; i<nplayers; i++){
        Player* p = new HumanPlayer(i); //right now we are just making all of them human players.
        players.push_back(p);
    }
}

void Game::DealCards(int p, int cards){
    if(p == -1){ //we already have a function to deal cards, might as well  make it so
        //it can deal to the pile too.
        for(int i = 0; i<cards; i++){
            Card* c = deck.back();
            pl->TakeCard(c);
            deck.pop_back();
        }
        return;
    }
    
    //we are given the player number, and how many cards we want to give to them.
    Player* x = players[p];
    //we should check they are the same number.
    //this is pretty redundant, but better safe than sorry.
    if(x->GetPNumber() == p){
        //if we want to give them 7 cards this loop will run 7 times..
        for(int i = 0; i<cards; i++){
            Card* c = deck.back();
            x->TakeCard(c);
            deck.pop_back();
        }
    }
}

void Game::PrintDeck(){
    cout << "Deck size: " << deck.size() << endl;
    for(Card* x : deck){
        cout << "Color: " << x->GetColor() << " Number: " << x->GetNumber() << endl;
    }
    cout << "End print of deck." << endl;
}

void Game::StartGame(){
    for(int i = 0; i<nplayers; i++){
        DealCards(i, 7);
    }
    while(!gameover){
        Player* x = players[tm->GetPlayerTurn()];
        cout << "The card on the top of the pile is a " << pl->GetTop()->GetColor() << ":" << pl->GetTop()->GetNumber() << endl;
        x->Play(pl);
        //we should make play return something. but also...idk.
        //how do we want this to go?
        tm->NextTurn(); //we should be giving this to the logic manager so they can determine which way the turn goes.
    }
    cout << "<<<<<< Game over? >>>>>>" << endl;
    //now we just loop through our players endlessly, call their play function, until someone wins.
    //let's start off with two human players.
    
}

void Game::PrintPlayerHands(){
    for(int i = 0; i<nplayers; i++){
        Player* x = players[i];
        x->PrintHand();
    }
}
