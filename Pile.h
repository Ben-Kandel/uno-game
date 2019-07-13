/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pile.h
 * Author: BenjaminK
 *
 * Created on July 12, 2019, 11:27 AM
 */

#ifndef PILE_H
#define PILE_H

#include <stack>
using std::stack;
#include <vector>
using std::vector;
#include <algorithm>
using std::shuffle;
#include <random>
#include <chrono>

#include "Card.h"

class Pile {
public:
    Pile() = default;
    Card* GetTop();
    void RestartPile(vector<Card*> &deck);
    void SetWildChoice(char c);
    char GetWildChoice();
    void TakeCard(Card* x);
private:
    stack<Card*> pile;
    char colorchosen;
};

#endif /* PILE_H */

