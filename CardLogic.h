/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CardLogic.h
 * Author: BenjaminK
 *
 * Created on July 11, 2019, 6:24 PM
 */

#ifndef CARDLOGIC_H
#define CARDLOGIC_H

#include "Card.h"

class CardLogic {
public:
    CardLogic() = default;
    int ValidPlay(Card* card_on_pile, Card* potential_play);
    bool SameColor(Card* x, Card* y);
    bool SameNumber(Card* x, Card* y);
private:
    //nothinn
};

#endif /* CARDLOGIC_H */

