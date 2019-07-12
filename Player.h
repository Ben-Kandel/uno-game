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
using std::cout; using std::endl; using std::cin;
#include "Card.h"
#include "CardLogic.h"
#include "Pile.h"

class Deck; //forward declaration for the deck class.

class Player {
public:
    Player(int n){
        pnumber = n;
        cl = new CardLogic();
    }
    virtual int Play(Pile* pl, Deck* d) = 0;
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
        cout << "Player " << pnumber+1 << "'s hand:" << endl;
        int counter = 1;
        for(Card* c : hand){
            cout << counter << ":" << "Color: " << c->GetColor() << " Number: " << c->GetNumber() << endl;
            counter++;
        }
        cout << endl;
    }
protected:
    int pnumber;
    int handsize = 7;
    vector<Card*> hand;
    virtual bool IsHandFull(){
        if(hand.size() > handsize){
            return true;
        }
        return false;
    }
    CardLogic* cl;
};

#endif /* PLAYER_H */

