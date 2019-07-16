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

    Card* played;
    while(true){
        //first: loop through hand, add to dictionary. then, determine what to play. if we need to draw, just draw a card and restart the loop.
        plays.clear(); //due to design flaws, im just gonna loop through the hand and repopulate the map everytime we ask for Play()
        //PrintHand();
        for(Card* x : hand){
            int result = cl->ValidPlay(pl->GetTop(), x);
            plays[result].push_back(x);
        }
        
        if(plays[1].size() == 0 && plays[2].size() == 0){
            //we have to draw a card. 
            TakeCard(d->DealMeCard(pl));
            continue;
        }else if(plays[1].size() == 0 && plays[2].size() != 0){
            //if we have no playable cards and some playable wild card:
            //play the first one (the 'first' one being the back of the vector)
            played = plays[2].back();
            plays[2].pop_back();
            //we need to choose a color now.
            char colorchoice = 'r';
            if(ngreencards > nredcards){
                colorchoice = 'g';
            }else if(nbluecards > ngreencards){
                colorchoice = 'b';
            }else if(nyellowcards > nbluecards){
                colorchoice = 'y';
            }
            pl->TakeCard(played);
            pl->SetWildChoice(colorchoice);
            break;
        }else if(plays[1].size() != 0){
            played = plays[1].back();
            plays[1].pop_back();
            pl->TakeCard(played);
            break;
        }
        
    }
    //we have to erase it from the hand. this is a little messy, but..:
    for(int i = 0; i<hand.size(); i++){
        if(played->GetColor() == hand[i]->GetColor()){
            if(played->GetNumber() == hand[i]->GetNumber()){
                //erase the card from hand.
                hand.erase(hand.begin() + i);
                break;
            }
        }
    }
    //updating our color values:
    if(played->GetColor() == 'r'){
        nredcards--;
    }else if(played->GetColor() == 'g'){
        ngreencards--;
    }else if(played->GetColor() == 'b'){
        nbluecards--;
    }else if(played->GetColor() == 'y'){
        nyellowcards--;
    }
    
    //determining what to return:
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

void AIPlayer::TakeCard(Card* c){
    
    hand.push_back(c);
    if(c->GetColor() == 'r'){
        nredcards++;
    }else if(c->GetColor() == 'g'){
        ngreencards++;
    }else if(c->GetColor() == 'b'){
        nbluecards++;
    }else if(c->GetColor() == 'y'){
        nyellowcards++;
    }
}
