/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.h
 * Author: BenjaminK
 *
 * Created on July 12, 2019, 3:16 PM
 */

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "Player.h"
#include <vector>
using std::vector;
#include <algorithm>
using std::shuffle;
#include <random>
#include <chrono>

class Deck {
public:
    Deck();
    Card* DealMeCard(Pile* p);
    void DealCards(int c, vector<Player*> players);
    void PrintDeck();
    void StartGame(vector<Player*> players, Pile* pl);
    int GetSize();
    ~Deck();
    vector<Card*>& GetDeck();
private:
    void CreateCards();
    vector<Card*> deck;
};

#endif /* DECK_H */

