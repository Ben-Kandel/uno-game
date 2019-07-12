/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HumanPlayer.cpp
 * Author: BenjaminK
 * 
 * Created on July 11, 2019, 10:59 AM
 */

#include "HumanPlayer.h"
#include "Deck.h"

HumanPlayer::HumanPlayer(int n):Player(n){
    
}

int HumanPlayer::Play(Pile* pl, Deck* d){
    int index;
    PrintHand();
    while(true){
        cout << "Please choose a card to play by typing in the corresponding number (-1 to draw a card): ";
        cin >> index;
        if(index == -1){
            hand.push_back(d->DealMeCard());
            PrintHand();
            continue;
        }
        if(index < 1 || index > hand.size()){
            cout << "ERROR: Please enter a valid number." << endl;
            continue;
        }
        int result = cl->ValidPlay(pl->GetTop(), hand[index-1]);
        if(result == 0){
            cout << "ERROR: You can't play that card. Please select another one." << endl;
            continue;
        }else if(result == 1){
            pl->TakeCard(hand[index-1]);
            //hand.erase(hand.begin() + index-1);
        }else if(result == 2){
            //2 means we gotta prompt the user for a color choice.
            //blah blah stuff
            //hand.erase(hand.begin() + index-1);
        }
        break;
    }
    Card* played = hand[index-1];
    hand.erase(hand.begin() + index-1);
    if(played->GetNumber() == 10){
        return 2;
    }else if(played->GetNumber() == 11){
        return 1;
    }else if(played->GetNumber() == 12){
        return 3;
    }
    return 0;
    //THIS function will return an integer. 0 means dont do anything. 1 means we played a reverse. 2 means we played a skip. 3 means we played a draw 2.
}
