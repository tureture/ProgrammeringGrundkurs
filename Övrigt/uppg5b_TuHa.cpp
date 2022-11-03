/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

Inlämningsuppgift nr 5b

Namn: Ture Hassler

Personummer: 9904122091

Fyll i (alt stryk det som ej är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kompilator/editor (namn/version): Xcode / 11.6

Jag har använt följande dator (PC/Mac/Annat): Mac
      med operativsystemet: macOS Catalina

Jag har arbetat ungefär 4 timmar med denna uppgift
================================================================================
*/
//
// Programskal till obluppg5A
//
// Hanterar fallet med 26 bokst‰ver A-Z

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:

const int ANTAL_BOKSTAVER = 26;  //A-Z
const int ANTAL_SPRAK = 4;

// 2d-arrayen TOLK_HJALP innehÂller bokstavsfrekvensen i %
// fˆr fyra sprÂk. TOLK_HJALP[0][0] ‰r frekvensen av
// bokstaven a fˆr engelska.TOLK_HJALP[0][25] ‰r frekvensen av
// bokstaven z fˆr engelska.
// Arrayen ‰r en GLOBAL KONSTANT och skall alltsÂ ej skickas
// som parameter till den funktion som behˆver den.
const double TOLK_HJALP[ANTAL_SPRAK][ANTAL_BOKSTAVER]=
       {{8.27,1.48,2.94,4.03,11.78,2.22,1.72,6.77, //engelska
         7.39,0.12,0.81,3.76,2.85,6.71,7.79,1.54,
         0.05,5.95,6.69,9.07,2.66,1.13,2.14,0.19,
         1.89,0.03},
        {7.97,1.40,3.55,3.79,16.89,1.02,1.00,0.75, //franska
         7.08,0.38,0.04,5.51,2.82,8.11,5.19,2.78,
         1.01,6.69,8.35,7.22,6.09,1.35,0.02,0.54,
         0.30,0.15},
        {9.50,1.11,1.53,5.30,8.94,1.74,3.57,3.94,  //svenska
         3.98,0.89,3.26,4.93,3.41,8.46,5.01,1.77,
         0.00,6.73,5.56,9.20,1.94,2.42,0.00,0.05,
         0.45,0.00},
        {5.12,1.95,3.57,5.07,16.87,1.35,3.00,5.79, //tyska
         8.63,0.19,1.14,3.68,3.12,10.64,1.74,0.42,
         0.01,6.30,6.99,5.19,3.92,0.77,1.79,0.01,
         0.69,1.24}};


//--------------------------------------------------------
// H‰r kommer klassdeklarationen

class Text {
private:
    // Variabler
    string text;
    int histogram_abs[ANTAL_BOKSTAVER];
    double histogram_rel[ANTAL_BOKSTAVER];
    int counter;
    // Privata funktioner, kallas bara inifrån klassen
    void absTillRel();
    bool beraknaHistogramAbs();

public:
    Text();
    void setText( string nyText );
    void skrivHistogramAbs();
    void plottaHistogramRel();
    void beraknaHistogram();
    string tolka();
};

// Funktionsdeklarationer
string namn_pa_fil();
string inlasning(string filnamn);

// -------------------------------------------------------

// Huvudprogram:

int main()
{
 // Deklarera variabler
  string text;
  Text minText;  // Ett objekt av typen Text skapas

  // L‰s in en rad med text frÂn tangentbordet
    text = inlasning(namn_pa_fil());

  // Skicka str‰ngen text till objektet minText
  minText.setText( text );

  // Ber‰kna och skriv ut histogrammet
  minText.beraknaHistogram();
  minText.skrivHistogramAbs();
  minText.plottaHistogramRel();
  cout << "Språket är: " << minText.tolka() << "\n";


  return 0;
}

// -------------------------------------------------------
// Här skriver du klassimplementationen
Text::Text(){
    text = "";
    for(int i=0; i<ANTAL_BOKSTAVER; i++) {
        histogram_abs[i] = 0;
        histogram_rel[i] = 0;
    }
    counter = 0;
}

void Text::setText( string nyText){
    text = nyText;
}

bool Text::beraknaHistogramAbs() {
    bool validText = false;
    
    counter = 0; // Nollställ arrayen och räknaren
    for(int i=0; i<ANTAL_BOKSTAVER; i++){
           histogram_abs[i] = 0;
       }
       
    for (int i=0; i< text.length(); i++) {
        if (isalpha(text.at(i))) {
            counter++;
            histogram_abs[tolower(text.at(i))-'a']++;
        }
    }
    
    if (counter > 0) {
        validText = true;
    }
    return validText;
}

void Text::skrivHistogramAbs() {
    cout << "Resultat för bokstäverna A-Z \n";
    cout << "Antalet behandlade bokstäver: " << counter << "\n";
    cout << "Fördelning: \n";
    for (int i=0; i<ANTAL_BOKSTAVER; i++) {
        cout << char(i +'A') << ": " << histogram_abs[i] << "\n";
    }
}

void Text::absTillRel(){
    for (int i=0; i<ANTAL_BOKSTAVER; i++) {
        histogram_rel[i] = (double(histogram_abs[i]) / double(counter)) *  double(100);
    }
}

void Text::plottaHistogramRel(){
    for (int i=0; i<ANTAL_BOKSTAVER; i++) {
        cout << char(i + 'A') << ":";
       
        for (int j=0; j < (round(histogram_rel[i] * 2)); j++) {
            cout << "*";
        }
        cout << "\n";
    }
    cout << "Antalet behandlade bokstäver är: " << counter << "\n";
}

void Text::beraknaHistogram(){
    if (beraknaHistogramAbs()){
        absTillRel();
    }
}

string Text::tolka(){
    double ksum[ANTAL_SPRAK] = {0,0,0,0};
    string sprakNamn[ANTAL_SPRAK] = {"Engelska", "Franska", "Svenska", "Tyska"};
    string sprak = "";
       
    // Beräkna kvadratsummorna
    for (int j=0; j<ANTAL_SPRAK; j++) {
        for (int i=0; i<ANTAL_BOKSTAVER; i++) {
            ksum[j] += (TOLK_HJALP[j][i] - histogram_rel[i]) * (TOLK_HJALP[j][i] - histogram_rel[i]);
         }
       }
       
    // Bestäm det likaste språket
    if (ksum[0] <= ksum[1] && ksum[0] <= ksum[2] && ksum[0] <= ksum[3]) {
           sprak = sprakNamn[0];
        } else if (ksum[1] <= ksum[2] && ksum[1] <= ksum[3]){
           sprak = sprakNamn[1];
       } else if (ksum[2] <= ksum[3]){
           sprak = sprakNamn[2];
       } else {
           sprak = sprakNamn[3];
       }
    return sprak;
}






//--------------------------------------------------------
// Funktionsdefinitioner:

// Låter användaren säga ett filnamn. Lägger till ändelsen .txt ifall den saknas
string namn_pa_fil() {
    string filnamn;
    
    cout << "Skriv in ett filnamn: ";
    cin >> filnamn;
    
    if (filnamn.rfind(".txt") == string::npos) { // Lägger till ändelse .txt
        filnamn.append(".txt");
    }
    return filnamn;
}

// Läser in datan från en fil. Tar input string filnamnet och returnar en string med
// all text från filen.
string inlasning(string filnamn) {
    string text;
     char c;
    
    ifstream fin(filnamn.c_str());
    
    if ( !fin ){
         cout << "Filen kunde inte öppnas"
              << endl;
         exit( EXIT_FAILURE );
       }

     while ( fin.get(c) ) {
           text += c;
       }
    return text;
}




// -------------------------------------------------------
// Rapport om uppgiften
/*
 
 Uppgiften gick ut på att omvandla samma program som i uppgift 4 till en klass med
 medföljande funktioner. Det svåraste var nog att börja tänka ur en "objekt" synvinkel.
 Att börja tänka på vilka delar objekten ska innehålla och vilka funktioner som behövs,
 istället för bara skriva mer funktioner. Såhär i efterhand känns dock koden mycket
 mer läsbar och förståelig som ett objekt.
 
 Finns det någon anledning till varför vi beräknar både det absoluta och det relativa
 histogrammet i samma funktionsanrop?
 
 Beräknar vi både det absoluta och det relativa histogrammet samtidigt finns det ingen
 risk att dom inte överrensstämmer. Ifall vi hade kallat funktionerna separat hade
 vi kunnat ändra string mellan och då hade inte längre datan hört ihop, utan att
 vi hade märkt något.
 
 Tänk dig att vi lägger till en rad sist i huvudprogrammet som anropar funktionen setText
 med en ny text, då får vi resultatet att attributet text ändras, men histogrammen
 fortfarande är desamma och alltså inte hör ihop med den aktuella texten.
 Finns det något sätt att lösa det problemet? Du behöver bara svara med ord,
 inte programmera något nytt.
 
 En lösning hade kunnat vara att låta funktionen setText automatiskt kalla funktionen
 beraknaHistogram. En annan skulle vara att spara en string med namnet på datan,
 så vet man vilken data som histogrammen visar.
 
 Skulle man kunna inkludera funktionerna namn_pa_fil och inlasning i klassen?
 Skulle det göra någon skillnad på resultatet? Finns det några fördelar med att
 använda samma funktioner som tidigare?
 
 Använder man samma funktioner som tidigare behöver man inte ändra någon kod för att
 överföra programmet. Hade funktionerna varit inuti objektet hade vi behövt läsa in
 hela objektet, och dessutom vill vi ju kunna använda det för att läsa in filer som
 inte är för histogrammen.
 */
