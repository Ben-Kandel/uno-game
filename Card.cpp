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


std::ostream& operator<<(std::ostream& os, Card& c){
    //9 for blue
    //12 for red
    //10 for green
    //14 for yellow
    //15 for white
    HANDLE hconsole;
    hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(c.GetColor() == 'r'){
        SetConsoleTextAttribute(hconsole, 12);
        os << "red ";
        //SetConsoleTextAttribute(hconsole, 15);
    }else if(c.GetColor() == 'g'){
        SetConsoleTextAttribute(hconsole, 10);
        os << "green ";
        //SetConsoleTextAttribute(hconsole, 15);
    }else if(c.GetColor() == 'b'){
        SetConsoleTextAttribute(hconsole, 9);
        os << "blue ";
        //SetConsoleTextAttribute(hconsole, 15);
    }else if(c.GetColor() == 'y'){
        SetConsoleTextAttribute(hconsole, 14);
        os << "yellow ";
        //SetConsoleTextAttribute(hconsole, 15);
    }else if(c.GetColor() == 'w'){
        SetConsoleTextAttribute(hconsole, 15);
        os << "wild ";
        //SetConsoleTextAttribute(hconsole, 15);
    }
    
    if(c.GetNumber() == 10){
        os << "skip";
    }else if(c.GetNumber() == 11){
        os << "reverse";
    }else if(c.GetNumber() == 12){
        os << "draw 2";
    }else{
        os << c.GetNumber();
    }
    SetConsoleTextAttribute(hconsole, 15);
    return os;
}

