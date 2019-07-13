/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AIPlayer.cpp
 * Author: BenjaminK
 * 
 * Created on July 13, 2019, 4:29 PM
 */

#include "AIPlayer.h"
#include "Deck.h"

AIPlayer::AIPlayer(int n):Player(n){
    
}

int AIPlayer::Play(Pile* pl, Deck* d){
    
    //okay. so the AI basically needs to just pick a card that works.
    //let's get that working, and then we can make it play the special cards whenever.
    //we'll also make it play the wild cards well, too.
    //so, the first thing we can do, is loop through our hand until we find one that works. and then play it.
    PrintHand();
    
    Card* played;
    int index = 0;
    int badplaycounter = 0;
    for(Card* x : hand){
        int result = cl->ValidPlay(pl->GetTop(), x);
        if(result == 0){
            badplaycounter++;
        }else if(result == 1){
            pl->TakeCard(x);
            played = x;
            hand.erase(hand.begin() + index);
            break;
        }else if(result == 2){
            badplaycounter++;//this is just temporary. i haven't implemented how to deal with wild cards yet.
        }
        index++;
    }
    //if we made it here, it means we made no play. we gotta draw a card and keep going? we'll get there eventually, hold on.
   
    if(badplaycounter == hand.size()){ //if every single one of our cards was unplayable, we need to keep drawing until we can play one.
        cout << "im an AI player and I could not find a card to play, so I must draw." << endl;
        while(true){
            hand.push_back(d->DealMeCard());
            int result = cl->ValidPlay(pl->GetTop(), hand.back());
            if(result == 0){
                continue;
            }else if(result == 1){
                pl->TakeCard(hand.back());
                played = hand.back();
                hand.erase(hand.end()-1);
                break;
            }else if(result == 2){
                continue;
            }
        }
    }
    
    if(played->GetNumber() == 10){
        return 2;
    }else if(played->GetNumber() == 11){
        return 1;
    }else if(played->GetNumber() == 12){
        return 3;
    }
    if(played->GetColor() == 'w' && played->GetNumber() == 1){
        return 4;
    }
    return 0;
    //THIS function will return an integer. 0 means dont do anything. 1 means we played a reverse. 2 means we played a skip. 3 means we played a draw 2.
    //4 means we played a draw 4.
    
}
