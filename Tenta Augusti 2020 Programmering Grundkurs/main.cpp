//
//  main.cpp
//  Tenta Augusti 2020 Programmering Grundkurs
//
//  Created by Ture Hassler on 2020-08-29.
//  Copyright © 2020 Ture Hassler. All rights reserved.
//
/*
 
 
#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Saft {
private:
    // Variabler
    string namn;
    int year;
    bool vitSaft; // True för vit saft, false för röd saft
    string berries;
    int antal;
    
public:
    Saft();
    Saft(string name, int year, bool vitSaft, string berries, int antal);
    string getName();
    int getYear();
    bool isWhite();
    int getAntal();
    void skrivUt();
    void laggTill(int antalF);
    void taBort(int antalF);
    
};

Saft::Saft() {
    namn = "";
    year = 0;
    vitSaft = false;
    berries = "";
    antal = 0;
}

Saft::Saft(string name, int year, bool vitSaft, string berries, int antal):
namn(name),year(year),vitSaft(vitSaft),berries(berries),antal(antal)
{}

string Saft::getName(){
    return namn;
}

int Saft::getYear(){
    return year;
}

int Saft::getAntal(){
    return antal;
}

bool Saft::isWhite(){
    return vitSaft;
}

void Saft::laggTill(int antalF){
    antal += antalF;
}

void Saft::taBort(int antalF){
    if ((antal-antalF) > 0) {
        antal -= antalF;
    } else {
        antal = 0;
    }
}

void Saft::skrivUt(){
    cout << "Saften heter: " << namn << "\n";
    cout << "Från år: " << year << "\n";
    if (vitSaft) {
        cout << "Är av typen Vit saft \n";
    } else {
        cout << "Är av typen Röd saft \n";
    }
    cout << "Gjord på: " << berries << "\n";
    cout << "Antal flaskor: " << antal << "\n";
}
*/
