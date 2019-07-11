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

void HumanPlayer::Play(){
    size_t index;
    PrintHand();
    while(true){
        cout << "Please choose a card to play by typing in the corresponding number: ";
        cin >> index;
        if(index < 1 || index > hand.size()){
            cout << "ERROR: Please enter a valid number." << endl;
            continue;
        }
        break;
    }
    //if we get here, that means we picked a valid number. now we need our turn logic. also we need access to the pile so we can compare.
}
