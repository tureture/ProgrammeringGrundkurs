/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

Inlämningsuppgift nr 4a

Namn: Ture Hassler

Personummer: 9904122091

Fyll i (alt stryk det som ej är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kompilator/editor (namn/version): Xcode / 11.6

Jag har använt följande dator (PC/Mac/Annat): Mac
      med operativsystemet: macOS Catalina

Jag har arbetat ungefär 2 timmar med denna uppgift
================================================================================
*/

//
// Programskal till obluppg4 - deluppgift A
//
// Hanterar fallet med 26 bokst‰ver A-Z

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;


// Anv‰nd g‰rna denna globala konstant i programmet
// i st‰llet fˆr v‰rdet 26
const int ANTAL_BOKSTAVER = 26;  //A-Z
// Globala variabler ‰r ej tillÂtna

//--------------------------------------------------------
// Funktionsdeklarationer:
// Anv‰nd exakt de funktionsnamn som finns nedan

void berakna_histogram_abs(string str, int histogram[],int &counter);
void skriv_histogram_abs(string str, int histogram[], int counter);


//--------------------------------------------------------
// Huvudprogram:

int main()
{
  // Deklarera variabler
    int histogram[ANTAL_BOKSTAVER];
    for(int i=0;i<ANTAL_BOKSTAVER; i++){ // Initierar hela arrayen till 0
        histogram[i] = 0;
    }
    string str;
    int counter = 0;
    
  // L‰s in en rad med text frÂn tangentbordet
    cout << "skriv en mening: \n";
    getline(cin,str);

  // Anropa funktionen berakna_histogram_abs som ber‰knar histogrammet
  // och antalet bokst‰ver.
    berakna_histogram_abs(str, histogram, counter);
  
  // Anropa funktionen skriv_histogram_abs som skriver ut histogrammet
    skriv_histogram_abs(str, histogram, counter);

  return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:
//*

 // Räknar förekomsten av varje bokstav från a-z
void berakna_histogram_abs(string str, int histogram[], int &counter){
    
    for (int i=0; i< str.length(); i++) {
        if (isalpha(str.at(i))) {
            counter++;
            histogram[tolower(str.at(i))-'a']++;
        }
    }
}
// Skriver ut värdet i hela arrayen i en tabell
void skriv_histogram_abs(string str, int histogram[], int counter){
    cout << "Resultat för bokstäverna a-z \n";
    cout << "Antalet behandlade bokstäver: " << counter << "\n";
    cout << "Fördelning : \n";
    for (int i=0; i<ANTAL_BOKSTAVER; i++) {
        cout << char(i +'a') << ": " << histogram[i] << "\n ";
    }
    
}

// Redovisning av uppgiften i ord.
/*
  Deluppgift a går ut på att använda arrayer för att räkna förekomsten av bokstäverna i
 en text.
 Programmet läser in en textrad. Därefter kallar den en funktion som räknar alla bokstäver
 och lägger till svaret i en array. Sen kallas ytterligare en funktion som skriver ut alla
 värden i arrayen tillsammans med respektive bokstav.
  Jag tyckte problemet först kändes komplicerat men det blev tillslut en väldigt enkel och
 smidig lösning när man enkelt kunde använda siffrorna för char-tecken för att hitta rätt
 index i arrayen, och den inbyggda funktionen isalpha föll bitarna på plats.
 
 */





