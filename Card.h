/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card.h
 * Author: BenjaminK
 *
 * Created on July 11, 2019, 10:17 AM
 */

#ifndef CARD_H
#define CARD_H

#include <ostream>
#include <windows.h>
#include <iostream>
using std::cout; using std::endl;

class Card {
public:
    Card(char c, int n);
    char GetColor();
    int GetNumber();
    friend std::ostream& operator<<(std::ostream& os, Card &c);
private:
    char color;
    int number;
};

#endif /* CARD_H */

