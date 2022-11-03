/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

Inlämningsuppgift nr 4b

Namn: Ture Hassler

Personummer: 9904122091

Fyll i (alt stryk det som ej är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kompilator/editor (namn/version): Xcode / 11.6

Jag har använt följande dator (PC/Mac/Annat): Mac
      med operativsystemet: macOS Catalina

Jag har arbetat ungefär 7 timmar med denna uppgift
================================================================================
*/

//
// Programskal till obluppg4 - deluppgift B
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

// 2d-arrayen TOLK_HJALP innehåller bokstavsfrekvensen i %
// för fyra språk. TOLK_HJALP[0][0] är frekvensen av
// bokstaven a för engelska.TOLK_HJALP[0][25] är frekvensen av
// bokstaven z för engelska.
// Arrayen är en GLOBAL KONSTANT och skall alltså ej skickas
// som parameter till den funktion som behöver den.
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
// Funktionsdeklarationer:

void berakna_histogram_abs(string str, int histogram[],int &counter);
void abs_till_rel(int histogram_abs[], double histogram_rel[], int counter);
void plotta_histogram_rel(double histogram_rel[], int counter);
void tolkning(double histogram_rel[]);
string namn_pa_fil();
string inlasning(string filnamn);

//--------------------------------------------------------
// Huvudprogram:

int main()
{
    // Deklarera variabler
    int histogram_abs[ANTAL_BOKSTAVER];
    double histogram_rel[ANTAL_BOKSTAVER];
    int counter;
    
    // Tar namnet, läser indata från valda filen och beräknar abs histogrammet
    berakna_histogram_abs(inlasning(namn_pa_fil()), histogram_abs, counter);
    
    // Går från histogram med absolutbelopp till procent
    abs_till_rel(histogram_abs, histogram_rel, counter);
    
    // Plottar histogrammet
    plotta_histogram_rel(histogram_rel, counter);
    
    // Bestämmer vilket språk som är likast
    tolkning(histogram_rel);
     
  return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:

// Beräknar histogrammet. Tar input en string med data,
// en array att fylla och en counter som håller koll på
// antalet giltiga bokstäver
void berakna_histogram_abs(string str, int histogram[], int &counter){
    
    counter = 0; // Nollställ arrayen och räknaren 
    for(int i=0; i<ANTAL_BOKSTAVER; i++){
        histogram[i] = 0;
    }
    
    for (int i=0; i< str.length(); i++) {
        if (isalpha(str.at(i))) {
            counter++;
            histogram[tolower(str.at(i))-'a']++;
        }
    }
}

// Omvandlar histogrammet med absoluta siffror till en med procent.
// Input: array med datan, tom array och counter
void abs_till_rel(int histogram_abs[], double histogram_rel[], int counter){
    for (int i=0; i<ANTAL_BOKSTAVER; i++) {
        histogram_rel[i] = (double(histogram_abs[i]) / double(counter)) *  double(100);
    }
}

// Skriver ut alla värden i histogram_rel, och antalet behandlade bokstäver.
// Tar input: en array histogram_rel[] med data och int counter för antalet behandalde bokstäver.
void plotta_histogram_rel(double histogram_rel[], int counter){
    for (int i=0; i<ANTAL_BOKSTAVER; i++) {
        cout << char(i + 'A') << ":";
        int j = 0;
        
        for (j=0; j < (round(histogram_rel[i] * 2)); j++) {
            cout << "*";
        }
        
        cout << "\n";
    }
    cout << "Antalet behandlade bokstäver är: " << counter << "\n";
}

// Beräknar kvadratsumman för texten jämfört med de fyra referensspråken.
// Skriver sedan ut svaret.
// Tar input histogram_rel. Returnar inget.
void tolkning(double histogram_rel[]){
    
    double ksum[ANTAL_SPRAK] = {0,0,0,0};
    string sprakNamn[ANTAL_SPRAK] = {"Engelska", "Franska", "Svenska", "Tyska"};
    
    for (int j=0; j<ANTAL_SPRAK; j++) {
        
        for (int i=0; i<ANTAL_BOKSTAVER; i++) {
            ksum[j] += (TOLK_HJALP[j][i] - histogram_rel[i]) * (TOLK_HJALP[j][i] - histogram_rel[i]);
        }
        cout << "Kvadratsumman för " << sprakNamn[j] << " är: " << ksum[j] << "\n";
    }
    

    // Skriv ut det likaste språket
    if (ksum[0] <= ksum[1] && ksum[0] <= ksum[2] && ksum[0] <= ksum[3]) {
        cout << sprakNamn[0]<< " är det mest lika språket. \n";
    } else if (ksum[1] <= ksum[2] && ksum[1] <= ksum[3]){
        cout << sprakNamn[1]<< " är det mest lika språket. \n";
    } else if (ksum[2] <= ksum[3]){
        cout << sprakNamn[2]<< " är det mest lika språket. \n";
    } else {
        cout << sprakNamn[3]<< " är det mest lika språket. \n";
    }
}

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

/**
 Här skriver du en kort rapport om uppgiften. Ett eller ett par stycken om vad
 uppgiften gick ut på, vilka svårigheter som fanns, vad du tyckte var
 besvärligt och hur du löste problemen. Om det finns frågor att besvara i
 uppgiften ska det göras här.
 
 Uppgiften gick ut på att ta programmet från uppgift 4a och lägga till en hel del ny funktionalitet, mestadels med filinläsning.
 Det svåraste tyckte jag var att få programmet att korrekt läsa in data från andra filer. ifstream var nytt att jobba med och
 jag hade problem att få datorn att kolla i rätt mapp. Vidare så hade jag problem med heltalsdivision när jag skulle räkna ut
 procenten för histogram_rel. Det fixade jag med double();
 
 I lösningsförslagen tipsar vi om att man ska skapa/ladda hem en fil med bara lite innehåll medan man testar sitt program. Varför, tror du?
 Den största fördelen som jag kan se med en liten testfil är att man oftast enkelt kan kolla igenom filen och se var
 eller varför programmet gjorde fel. Det blir t.ex lätt att se att datan är rimlig.
 Är min textfil aaabbc inser jag ju snabbt att programmet inte funkar om den skapar ett histogram med prickar för z, x och y,
 vilket jag inte kan göra med en text från en bok.
 Sen är det ju alltid bra med mindre filstorlekar så det ska gå snabbare.
 
 Texten i filen lagerlof.txt innehåller de svenska bokstäverna å, ä och ö.
 Som programet fungerar nu räknas inte dessa bokstäver alls.
 Hur skulle man gå tillväga för att också inkludera å, ä och ö i histogrammet?
 Du behöver inte ge en program-lösning, men resonera kring hur man skulle kunna göra.
 
 Det finns nog flera sätt att inkludera åäö i histogrammet. Antingen kan man försöka förlänga arrayen med några platser
 och lägga till if satser som kollar efter åäö. Eller så kan man förlänga arrayen för att inkludera alla ascii tecken,
 men bara skriv ut de relevanta. Med programmering finns det alltid massor av olika sätt att göra på!
 
 */
