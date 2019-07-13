/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pile.cpp
 * Author: BenjaminK
 * 
 * Created on July 12, 2019, 11:27 AM
 */

#include "Pile.h"

Card* Pile::GetTop(){
    return pile.top();
}

void Pile::RestartPile(vector<Card*>& deck){
    //take all of the stack except the top and shuffle it back into this deck we got passed
    Card* save = pile.top();
    pile.pop();
    
    vector<Card*> bottomofpile;
    
    for(int i = 0; i<pile.size(); i++){
        bottomofpile.push_back(pile.top());
        pile.pop();
    }
    //now the pile should be empty
    pile.push(save);
    
    //merge the bottomofpile with the deck
    deck.insert(deck.end(), bottomofpile.begin(), bottomofpile.end());
    //randomly shuffle it again
    int seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

void Pile::SetWildChoice(char c){
    colorchosen = c;
}

char Pile::GetWildChoice(){
    return colorchosen;
}

void Pile::TakeCard(Card* x){
    pile.push(x);
}