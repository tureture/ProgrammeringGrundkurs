//
//  main.cpp
//  Uppgift 4 Tenta Prog GrundKurs
//
//  Created by Ture Hassler on 2020-08-29.
//  Copyright © 2020 Ture Hassler. All rights reserved.
//

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


class Barn
{
private:
  int regnr;             // barnets registreringsnummer
  string namn;          // barnets namn.

public:
  Barn();
  Barn(int p, string n);
  Barn& operator= (const Barn &b); // Tilldelningsoperator
  int hamtaRegnr();                  // returnerar regnr
  string hamtaNamn();                // skicka ut namn
  void skriv();                      // skriver ut barndata
  void las();                        // laser in data om nytt barn
  bool sammanr( Barn annat );        // true om aktuellt barn har
                                     // samma regnr som "annat".

};

class Skolklass
{
private:
  string larare;       // Lärarens namn
  Barn *barnen;        // Barnen i klassen
  int antal;           // antalet barn i klassen
  int maxantal;        // max antal barn som får finnas i klassen

public:
  Skolklass();
  ~Skolklass();

  void skolstart();    // läs in data, initiera, dvs starta klassen
  void nyttbarnforst(Barn bny); // nytt barn till skolklassen, lägg först
  void tabortbarn(int pnr );  // barn med regnr=pnr slutar i klassen
  void skriv();               // skriver ut alla data om skolklassen
  bool finns( int nr, int & i ); // true om barnet "b" finns i klassen
                                 //   "i" är då index för pos
};

int main( void )
{
  Skolklass Valsatra4A;    // Skapa en skolklass.
  Valsatra4A.skolstart();  // initiera klassen med data.
  Valsatra4A.skriv();      // Skriv ut

  int testTabort;
  cout << "Vilken skall bort? ge regnr:"  << endl;
  cin >> testTabort;
  Valsatra4A.tabortbarn( testTabort );
  Valsatra4A.skriv();          // Skriv ut

  return 0;
}


Barn::Barn(){
    namn = "";
    regnr = 0;
}

Barn::Barn(int p, string n){
    namn = n;
    regnr = p;
}

// Tilldelningsoperator
Barn& Barn:: operator= ( const Barn &b ){
   if (this != &b){
       namn = b.namn;
       regnr = b.regnr;
   }
   return *this;
}


int Barn::hamtaRegnr(){
    return regnr;
}

string Barn::hamtaNamn(){
    return namn;
}

void Barn::skriv(){
    cout << "Barnet " << namn << " med reg.nummer: " << regnr << "\n";
}

void Barn::las(){
    cout << "\n Skriv in namn: ";
    cin >> namn;
    cout << "\n Skriv in reg.nr: ";
    cin >> regnr;
    cout << "\n";
}

bool Barn::sammanr(Barn annat){
    if (regnr == annat.regnr){
        return true;
    }
    return false;
}

Skolklass::Skolklass(){
    larare = "";
    barnen = 0; // Null pointer
    antal = 0;
    maxantal = 0;
}

Skolklass::~Skolklass(){
    delete [] barnen;
}

void Skolklass::skolstart(){
    cout << "Ge lärarens namn: ";
    cin >> larare;
    
    cout << "\n Ge max antal elever i denna klass: ";
    cin >> maxantal;
    
    cout << "\n Ge antal barn idag: ";
    cin >> antal;
    
    Barn tempB;
    
    for (int i=0; i<antal; i++) {
        tempB.las();
        nyttbarnforst(tempB);
    }
}

void Skolklass::nyttbarnforst(Barn bny){
    int index = 0;
    Barn *temp = 0;
    
    for (int i=0; i<antal; i++) {
        if (!finns(i, index) && (antal<maxantal)) {
            temp = new Barn[antal +1];
            temp[0] = bny;
            for (int i=0; i<antal; i++) {
                temp[i+1] = barnen[i];
            }
            antal++;
            delete [] barnen;
            barnen = temp;
        }
    }
}

bool Skolklass::finns( int nr, int & i ){
    for (int j=0; j<antal; j++) {
        if (nr == barnen[j].hamtaRegnr()) {
            i = j;
            return true;
        }
    }
    return false;
}

void Skolklass::tabortbarn(int pnr){
    Barn *temp;
    temp = new Barn[antal -1];
    
    for (int i=0; i<antal; i++) {
        if (pnr == barnen[i].hamtaRegnr()) {
            for (int j=0; j<i; j++) {
                temp[j] = barnen[j];
            }
            for (int j=i+1; j<antal; j++) {
                temp[j-1] = barnen[j];
            }
        }
    }
    antal--;
    delete [] barnen;
    barnen = temp;
}

void Skolklass::skriv(){
    cout << "Lärarens namn: " << larare << "\n";
    cout << "Klassen har " << antal << "st barn \n";
    for (int i=0; i<antal; i++) {
        barnen[i].skriv();
    }
    
}
