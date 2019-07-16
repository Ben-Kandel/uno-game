/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.cpp
 * Author: BenjaminK
 * 
 * Created on July 12, 2019, 3:16 PM
 */

#include "Deck.h"

Deck::Deck(){
    CreateCards();
}

Card* Deck::DealMeCard(Pile* p){
    if(deck.size() == 1){
        Card* result = deck.back();
        deck.pop_back();
        p->RestartPile(deck);
        
        return result;
    }
    Card* result = deck.back();
    deck.pop_back();
    return result;
}

void Deck::PrintDeck(){
    cout << "<<< BEGIN PRINTING DECK >>>" << endl;
    for(Card* x : deck){
        cout << *x << endl;
    }
    cout << "<<< END PRINTING DECK >>>" << endl;
}

void Deck::CreateCards(){
    //create the 0-12 cards
    //10 is skip. 11 is reverse. 12 is draw 2.
    for(int i = 0; i <= 12; i++){
        Card* a = new Card('r', i);
        Card* b = new Card('g', i);
        Card* c = new Card('b', i);
        Card* d = new Card('y', i);
        deck.push_back(a);
        deck.push_back(b);
        deck.push_back(c);
        deck.push_back(d);
    }
    //create the 1-12 cards
    for(int i = 1; i <= 12; i++){
        Card* a = new Card('r', i);
        Card* b = new Card('g', i);
        Card* c = new Card('b', i);
        Card* d = new Card('y', i);
        deck.push_back(a);
        deck.push_back(b);
        deck.push_back(c);
        deck.push_back(d);
    }
    //create the wild cards
    for(int i = 0; i < 2; i++){
        for(int j = 0; j<4; j++){
            Card* a = new Card('w', i);
            deck.push_back(a);
        }
    }
    int seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

void Deck::StartGame(vector<Player*> players, Pile* pl){
    //PrintDeck();
    for(Player* x : players){
        for(int i = 0; i<6; i++){
            x->TakeCard(DealMeCard(pl));
        }
    }
    pl->TakeCard(DealMeCard(pl)); //putting the starter card down.
}

int Deck::GetSize(){
    return deck.size();
}

Deck::~Deck(){
    for(Card* x : deck){
        free(x);
    }
}

vector<Card*>& Deck::GetDeck(){
    return deck;
}