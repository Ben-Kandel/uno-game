/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: BenjaminK
 *
 * Created on July 11, 2019, 10:56 AM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;
#include "Card.h"


class Player {
public:
    Player(int n){
        pnumber = n;
    }
    virtual void Play() = 0;
    virtual void TakeCard(Card* c){
        if(!IsHandFull()){
            hand.push_back(c);   
        }
    }
    virtual void TakeCards(vector<Card*> c){
        for(Card* x : c){
            if(!IsHandFull()){
                hand.push_back(x);   
            }else{
                break;
            }
        }
    }
    virtual int GetHandSize(){
        return hand.size();
    }
    virtual int GetPNumber(){
        return pnumber;
    }
    virtual void PrintHand(){
        cout << endl;
        cout << "Player " << pnumber << "'s hand:" << endl;
        for(Card* c : hand){
            cout << "Color: " << c->GetColor() << " Number: " << c->GetNumber() << endl;
        }
        cout << endl;
    }
private:
    int pnumber;
    int handsize = 7;
    vector<Card*> hand;
    virtual bool IsHandFull(){
        if(hand.size() > handsize){
            return true;
        }
        return false;
    }
};

#endif /* PLAYER_H */

