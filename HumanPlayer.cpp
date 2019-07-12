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

HumanPlayer::HumanPlayer(int n):Player(n){
    
}

int HumanPlayer::Play(Pile* pl){
    size_t index;
    PrintHand();
    while(true){
        cout << "Please choose a card to play by typing in the corresponding number (-1 to draw a card): ";
        cin >> index;
        if(index == -1){ //how do we draw a card?
            //we should make the deck a class. the player class should have access to it, as well as the game.
            //we need to restructure a bit.
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
        }else if(result == 2){
            //2 means we gotta prompt the user for a color choice.
        }
        break;
    }
}
