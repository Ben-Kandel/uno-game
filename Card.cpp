/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card.cpp
 * Author: BenjaminK
 * 
 * Created on July 11, 2019, 10:17 AM
 */

#include "Card.h"

Card::Card(char c, int n){
    color = c;
    number = n;
}

char Card::GetColor(){
    return color;
}

int Card::GetNumber(){
    return number;
}
