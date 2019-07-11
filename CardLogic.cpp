/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CardLogic.cpp
 * Author: BenjaminK
 * 
 * Created on July 11, 2019, 6:24 PM
 */

#include "CardLogic.h"

int CardLogic::ValidPlay(Card* card_on_pile, Card* potential_play){
    //returning 0 means false, returning 1 means true, returning 2 means it was a wild card and we need to choose a color.
    if(potential_play->GetColor() == 'w'){
        return 2; //I see a future problem. After we play a wild card, the color of the top card will be wild.
        //so we need to keep track of the choice we had, and it make it so the next card played has to be that color.
    }
    if(SameColor(card_on_pile, potential_play) || SameNumber(card_on_pile, potential_play)){
        return 1;
    }
    return 0;
}

bool CardLogic::SameColor(Card* x, Card* y){
    //card x is the top card on the pile. there are some extra rules if it is a wild card.
    //we need to keep track of the previous chosen color and make sure the next card played matches it.
    //but lets test one thing at a time here.
    if(x->GetColor() == y->GetColor()){
        return true;
    }
    return false;
}

bool CardLogic::SameNumber(Card* x, Card* y){
    if(x->GetNumber() == y->GetNumber()){
        return true;
    }
    return false;
}