//
//  Uppgift 2 Tenta 2020.cpp
//  Tenta Augusti 2020 Programmering Grundkurs
//
//  Created by Ture Hassler on 2020-08-29.
//  Copyright © 2020 Ture Hassler. All rights reserved.
//

#include "Uppgift 2 Tenta 2020.hpp"

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int lagstaPris( string filnamn, string inkopslista[], int antal );

int main()
{
    string filnamn = "test.txt"; // Filnamnet på filen som ska läsas in.
    string grejerattkopa[] = { "DVD-brännare", "Mus", "Laserskrivare" };
    cout << lagstaPris(filnamn, grejerattkopa, 3) << "kr totalt \n";

}

int lagstaPris( string filnamn, string inkopslista[], int antal ){
    int billigastePris[antal]; // Håller koll på billigaste priset för respektive produkts index
    bool produktHittad[antal]; // Ser till så vi alltid fyller billigaste priset med första produkten
    string billigasteMarke[antal]; // Märket på den billigaste
    string tempProd;
    int tempPris;
    string tempNamn;
    int sum = 0;
    
    for (int i=0; i<antal; i++) {
        produktHittad[i] = false;
    }
    
    // Skapar ifstream instans för att läsa in data från en fil
    ifstream fin(filnamn.c_str());
    
    // Läser in tills eof är nådd
    while (!fin.eof()) {
        
        fin >> tempProd;
        fin >> tempNamn;
        fin >> tempPris;
        
        // For loop som kollar igenom objekten på inköpslistan för att hitta billigare
        for (int i=0; i<antal; i++) {
            if (inkopslista[i] == tempProd) { // Kollar om produkten är av samma typ
                // Kollar om priset är billigare, eller om det är första varvet.
                if (tempPris < billigastePris[i] || produktHittad[i] == false){
                    billigasteMarke[i] = tempNamn; // Sparar billigaste märket
                    billigastePris[i] = tempPris; // Sparar billigaste priset
                    produktHittad[i] = true; // Ser till så att vi inte har en tom array
                }
            }
        }
    }
    // Räknar ihop totala summan och skriver ut
    for (int j=0; j<antal; j++) {
        sum += billigastePris[j];
        cout << inkopslista[j] << " " << billigasteMarke[j] << " " << billigastePris[j] << "\n";
    }
    
    return sum;
}
