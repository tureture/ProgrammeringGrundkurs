/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

Inlämningsuppgift nr 6a v2

Namn: Ture Hassler

Personummer: 9904122091

Fyll i (alt stryk det som ej är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kompilator/editor (namn/version): Xcode / 11.6

Jag har använt följande dator (PC/Mac/Annat): Mac
      med operativsystemet: macOS Catalina

Jag har arbetat ungefär 10 timmar med denna uppgift
================================================================================
*/
//
//  Created by Ture Hassler on 2020-08-09.
//  Copyright © 2020 Ture Hassler. All rights reserved.
//

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:

const int MAX_KOMPISAR = 10;
const int MAX_TRANSAKTIONER = 30;
const int MAX_PERSONER = 20;

//--------------------------------------------------------
// H‰r kommer klassdeklarationen

class Transaktion
{
 private:
  string datum;
  string typ;
  string namn;
  double belopp;
  int ant_kompisar;
  string kompisar[MAX_KOMPISAR];

 public:
  Transaktion();
  ~Transaktion();
  string haemta_namn();
  string haemta_kompis_namn(int index);
  double haemta_belopp();
  int haemta_ant_kompisar();
  bool finnsKompis( string namnet );
  bool laesEnTrans( istream &is );
  void skrivEnTrans( ostream &os );
 
};

 class Person
 {
 private:
   string namn;
   double betalat_andras;   // ligger ute med totalt
   double skyldig;          // skyldig totalt

 public:
   Person();
   Person( string n, double b, double s );
   double haemta_betalat();
   double haemta_skyldig();
   string haemta_namn();
   void skrivUt();
  
};

class PersonLista
{
private:
  int antal_pers;
  Person pers[MAX_PERSONER];

public:
  PersonLista();
  ~PersonLista();
  void laggTillEn( Person pny );
  void skrivUtOchFixa();
  double summaSkyldig();
  double summaBetalat();
  bool finnsPerson(const string& namn);

};

class TransaktionsLista
{
 private:
   Transaktion trans[MAX_TRANSAKTIONER];
   int antalTrans;

 public:
   TransaktionsLista();
   ~TransaktionsLista();
   void laesin( istream & is );
   void skrivut( ostream & os );
   void laggTill( Transaktion & t );
   double totalkostnad();
   double liggerUteMed( string namnet );
   double aerSkyldig( string namnet );
   PersonLista FixaPersoner();
   
 };

// Huvudprogram:

int main()
{
    TransaktionsLista transL;
    ifstream fin("resa.txt");
    ofstream fout("data_out.txt");
    transL.laesin(fin);
    
    string tempN;
    Transaktion tempT;
    
    cout << "Fildata har lästs in";
    
    // Startmenyn
    int meny;
    cout << "\n";
    cout << "Välj från menyn nedan: \n";
    cout << "0. Avsluta. Alla transaktioner sparas på fil. \n";
    cout << "1. Läs in en transaktion från tangentbordet. \n";
    cout << "2. Skriv ut information om alla transaktioner. \n";
    cout << "3. Beräkna totala kostnaden. \n";
    cout << "4. Hur mycket är en viss person skyldig? \n";
    cout << "5. Hur mycket ligger en viss person ute med? \n";
    cout << "6. Lista alla personer mm och FIXA!!! \n";
    cin >> meny;
    cout << "\n";
    
    // Menyn loopar tills användaren väljer att avsluta med 0
    while (meny != 0) {
        switch (meny) {
            case 1:
            {
                Transaktion tempT;
                cout << "Skriv en transaktion (datum, typ, namn, belopp, antal vänner och namn på vänner): ";
                tempT.laesEnTrans(cin);
                transL.laggTill(tempT);
            }
                break;
            case 2:
                transL.skrivut(cout);
                break;
            case 3:
                cout << "Total kostnad: ";
                cout << transL.totalkostnad() << "kr \n";
                break;
            case 4:
            {
                string tempN;
                cout << "Skriv namn på personen: ";
                cin >> tempN;
                cout << "\n" << tempN << " är skyldig ";
                cout << transL.aerSkyldig(tempN) << "kr \n";
            }
                break;
            case 5:
            {
                string tempN;
                cout << "Skriv namn på personen: ";
                cin >> tempN;
                cout << "\n" << tempN << " ligger ute med ";
                cout << transL.liggerUteMed(tempN) << "kr \n";
            }
                break;
            case 6:
                transL.FixaPersoner().skrivUtOchFixa();
                break;
        }
        // Frågar efter ny input
        cout << "\n";
        cout << "Välj från menyn nedan: \n";
        cout << "0. Avsluta. Alla transaktioner sparas på fil. \n";
        cout << "1. Läs in en transaktion från tangentbordet. \n";
        cout << "2. Skriv ut information om alla transaktioner. \n";
        cout << "3. Beräkna totala kostnaden. \n";
        cout << "4. Hur mycket är en viss person skyldig? \n";
        cout << "5. Hur mycket ligger en viss person ute med? \n";
        cout << "6. Lista alla personer mm och FIXA!!! \n";
        cin >> meny;
        cout << "\n";
    }

    
    // Sparar datan i en fil, i det här fallet data_out.txt
    transL.skrivut(fout);
    cout << "Programmet är nu sparat och klart. \n";

  return 0;
}

// -------------------------------------------------------
// Här skriver du klassimplementationen

// Transaktion klassen

//Konstruktor
Transaktion::Transaktion(){
    datum = "";
    typ = "";
    namn = "";
    belopp = 0;
    ant_kompisar = 0;
    for (int i=0; i<MAX_KOMPISAR; i++) {
        kompisar[i] = "";
    }
}

// Dekonstruktor, används först i 6b
Transaktion::~Transaktion(){
 
}

// Hämtar namnet på personen som betalat transaktionen
string Transaktion::haemta_namn() {
    return namn;
}
// Hämtar kompis namn. Tar input index för arrayen
string Transaktion::haemta_kompis_namn(int index){
    return kompisar[index];
}

// Hämtar beloppet för transaktionen
double Transaktion::haemta_belopp() {
    return belopp;
}
// Hämtar antalet kompisar som var med i transaktionen
int Transaktion::haemta_ant_kompisar() {
    return ant_kompisar;
}
// Kollar om namnet finns med i kompis-listan
bool Transaktion::finnsKompis( string namnet ) {
    for (int i=0; i<ant_kompisar; i++) {
        if (namnet == kompisar[i]) {
            return true;
        }
    }
    return false;
}
// Läser in en transaktion. Tar input vald istream. Returnar falskt om eof är nådd, annars sant
bool Transaktion::laesEnTrans( istream &is ) {
    if (is.eof()) {
        return false;
    } else {
        is >> datum;
        is >> typ;
        is >> namn;
        is >> belopp;
        is >> ant_kompisar;
        for (int i=0; i< ant_kompisar; i++) {
            is >> kompisar[i];
        }
        return true;
    }
}

// Skriver ut en transaktion. Tar en ostream som input
void Transaktion::skrivEnTrans( ostream &os ) {
    os << datum << " " << typ << " " << namn << " " << belopp << " " << ant_kompisar << " ";
    for (int i=0; i<ant_kompisar; i++) {
        os << kompisar[i] << " ";
    }
    os << "\n";
}

// TransaktionsLista klassen

// Konstruktor
TransaktionsLista::TransaktionsLista(){
    antalTrans = 0;
    for (int i=0; i<MAX_TRANSAKTIONER; i++) {
        trans[i] = Transaktion();
    }
}

// Dekonstruktor
TransaktionsLista::~TransaktionsLista(){
    
}

// Läser in transaktioner till listan, forstätter så länge laesEnTrans returnar true. Tar input en istream
void TransaktionsLista::laesin( istream & is ){
    Transaktion t;
    while(t.laesEnTrans(is)){
        laggTill(t);
    }
}

// Skriver ut alla transaktioner. Tar input ostream
void TransaktionsLista::skrivut( ostream & os ){
    os << "Antal transaktioner: " << antalTrans << "\n";
    for (int i=0; i<antalTrans; i++) {
        trans[i].skrivEnTrans(os);
    }
}

// Lägger till en transaktion till listan. Tar input ett transaktions objekt
void TransaktionsLista::laggTill( Transaktion & t ){
    if (antalTrans < MAX_TRANSAKTIONER) {
        trans[antalTrans] = t;
        antalTrans++;
    } else {
        cout << "Fullt antal transaktioner";
    }
    
}

// Returnar den totala kostnaden för alla utgifter
double TransaktionsLista::totalkostnad(){
    double sum = 0;
    for (int i=0; i<antalTrans; i++) {
        sum += trans[i].haemta_belopp();
    }
    return sum;
}

// Returnar summan en person ligger ute med. Tar input personens namn
double TransaktionsLista::liggerUteMed( string namnet ){
    double sum = 0;
    for (int i=0; i<antalTrans; i++) {
        if (trans[i].haemta_namn() == namnet) {
            sum += trans[i].haemta_belopp() * double(trans[i].haemta_ant_kompisar()) / double(trans[i].haemta_ant_kompisar() + 1);
            //Fixar så att personen som har betalat betalar sin andel också
        }
    }
    return sum;
}
// Returnar summan en person är skyldig. Tar input personens namn
double TransaktionsLista::aerSkyldig( string namnet ){
    double debt = 0;
    for (int i=0; i<antalTrans; i++) {
        if (trans[i].finnsKompis(namnet)) {
            debt += trans[i].haemta_belopp() / double(trans[i].haemta_ant_kompisar() +1);
        }
    }
    return debt;
}

// Kollar igenom listan för unika namn och returnar en PersonLista med personerna och deras skulder/utgifter
PersonLista TransaktionsLista::FixaPersoner(){
    PersonLista personL;
    string namn;
    
    // Kollar alla som har betalat
    for (int i=0; i<antalTrans; i++) {
        namn = trans[i].haemta_namn();
        if (!personL.finnsPerson(namn)){
            personL.laggTillEn(Person(namn,liggerUteMed(namn),aerSkyldig(namn)));
        }
    }
    // Kollar alla som ej har lagt ut något
    for (int i=0; i<antalTrans; i++) {
        for (int j=0; j<trans[i].haemta_ant_kompisar(); j++) {
            namn = trans[i].haemta_kompis_namn(j);
            if (!personL.finnsPerson(namn)) {
                personL.laggTillEn(Person(namn,liggerUteMed(namn),aerSkyldig(namn)));
            }
        }
       
    }
    return personL;
}



//Person klassen

// Konstruktor
Person::Person(){
    namn = "";
    betalat_andras = 0;
    skyldig = 0;
}

// Överlagrad Konstruktor med input: namn, belopp och skulder
Person::Person(string n, double b, double s ){
    namn = n;
    betalat_andras = b;
    skyldig = s;
}

// Hämtar betalat_andras
double Person::haemta_betalat(){
    return betalat_andras;
}
// Hämtar pengar skyldig
double Person::haemta_skyldig(){
    return skyldig;
}
// Hämtar namnet
string Person::haemta_namn(){
    return namn;
}
// Skriver ut namnet, skulder och pengar som ligger ute
void Person::skrivUt(){
    cout << namn << " ligger ute med: " << betalat_andras << " och är skyldig: " << skyldig << ".";
    if (betalat_andras > skyldig) {
        cout << " Skall ha " << (betalat_andras - skyldig) << " från potten! \n";
    } else {
         cout << " Skall ge " << (skyldig - betalat_andras) << " till potten! \n";
    }
}

// Personlista klassen

// konstruktor
PersonLista::PersonLista(){
    antal_pers = 0;
    for (int i=0; i<MAX_PERSONER; i++) {
        pers[i] = Person();
    }
}
// Dekostruktor, används ej än
PersonLista::~PersonLista(){
    
}
// Lägger till ett Person objekt i slutet av listan
void PersonLista::laggTillEn( Person pny ){
    if (antal_pers<MAX_PERSONER) {
        pers[antal_pers] = pny;
        antal_pers++;
    } else {
        cout << "Fullt antal personer";
    }
}

// Skriver ut alla personer och deras skulder. Kollar sedan om pengarna går jämnt ut.
void PersonLista::skrivUtOchFixa(){
    // Skriver ut namn och skulder
    cout << "Följande är en lista på vad alla har lagt ut och/eller är skyldiga: \n";
    for (int i=0; i<antal_pers; i++) {
        pers[i].skrivUt();
    }
    // Kollar om pengarna har gått jämnt ut
    if (round(summaSkyldig() * 100) == round(summaBetalat() * 100)){
        cout << "Potten går jämnt ut med " << summaSkyldig() << "kr \n";
    } else {
        cout << "Potten går inte jämnt ut med " << summaSkyldig() << "kr skulder och " << summaBetalat() << " kr utlägg \n";
    }
}
// Hämtar totala summan alla är skyldiga
double PersonLista::summaSkyldig(){
    double debt = 0;
    for (int i=0; i<antal_pers; i++) {
        debt += pers[i].haemta_skyldig();
    }
    return debt;
}
// Hämtar totala summan alla har betalat
double PersonLista::summaBetalat(){
    double sum = 0;
    for (int i=0; i<antal_pers; i++) {
        sum += pers[i].haemta_betalat();
    }
    return sum;
}
// Kollar om personen finns. Tar input namn och returnar sant eller falskt.
bool PersonLista::finnsPerson(const string& namn){
    for (int i=0; i<antal_pers; i++) {
        if (namn == pers[i].haemta_namn()) {
            return true;
        }
    }
    return false;
}
    
/*
 ================================================================================
 Här följer programkörningar för alla testdata:
 ==============================================
 
 Fildata har lästs in
 Välj från menyn nedan:
 0. Avsluta. Alla transaktioner sparas på fil.
 1. Läs in en transaktion från tangentbordet.
 2. Skriv ut information om alla transaktioner.
 3. Beräkna totala kostnaden.
 4. Hur mycket är en viss person skyldig?
 5. Hur mycket ligger en viss person ute med?
 6. Lista alla personer mm och FIXA!!!
 2

 Antal transaktioner: 10
 050615 transp Eva 6000 5 Bosse Kristin Paul Torsten Stina
 050721 mat Eva 300 2 Bosse Kristin
 050721 mat Paul 400 2 Torsten Stina
 050721 transp Bosse 5000 3 Eva Kristin Paul
 050721 transp Stina 5000 1 Torsten
 050722 boende Kristin 200 1 Eva
 050722 mat Eva 300 2 Kristin Bosse
 050723 mat Torsten 300 2 Paul Stina
 050724 mat Paul 200 1 Stina
 050725 transp Eva 600 3 Bosse Kristin Paul

 Välj från menyn nedan:
 0. Avsluta. Alla transaktioner sparas på fil.
 1. Läs in en transaktion från tangentbordet.
 2. Skriv ut information om alla transaktioner.
 3. Beräkna totala kostnaden.
 4. Hur mycket är en viss person skyldig?
 5. Hur mycket ligger en viss person ute med?
 6. Lista alla personer mm och FIXA!!!
 3

 Total kostnad: 18300kr

 Välj från menyn nedan:
 0. Avsluta. Alla transaktioner sparas på fil.
 1. Läs in en transaktion från tangentbordet.
 2. Skriv ut information om alla transaktioner.
 3. Beräkna totala kostnaden.
 4. Hur mycket är en viss person skyldig?
 5. Hur mycket ligger en viss person ute med?
 6. Lista alla personer mm och FIXA!!!
 4

 Skriv namn på personen: Eva

 Eva är skyldig 1350kr

 Välj från menyn nedan:
 0. Avsluta. Alla transaktioner sparas på fil.
 1. Läs in en transaktion från tangentbordet.
 2. Skriv ut information om alla transaktioner.
 3. Beräkna totala kostnaden.
 4. Hur mycket är en viss person skyldig?
 5. Hur mycket ligger en viss person ute med?
 6. Lista alla personer mm och FIXA!!!
 5

 Skriv namn på personen: Eva

 Eva ligger ute med 5850kr

 Välj från menyn nedan:
 0. Avsluta. Alla transaktioner sparas på fil.
 1. Läs in en transaktion från tangentbordet.
 2. Skriv ut information om alla transaktioner.
 3. Beräkna totala kostnaden.
 4. Hur mycket är en viss person skyldig?
 5. Hur mycket ligger en viss person ute med?
 6. Lista alla personer mm och FIXA!!!
 6

 Följande är en lista på vad alla har lagt ut och/eller är skyldiga:
 Eva ligger ute med: 5850 och är skyldig: 1350. Skall ha 4500 från potten!
 Paul ligger ute med: 366.667 och är skyldig: 2500. Skall ge 2133.33 till potten!
 Bosse ligger ute med: 3750 och är skyldig: 1350. Skall ha 2400 från potten!
 Stina ligger ute med: 2500 och är skyldig: 1333.33. Skall ha 1166.67 från potten!
 Kristin ligger ute med: 100 och är skyldig: 2600. Skall ge 2500 till potten!
 Torsten ligger ute med: 200 och är skyldig: 3633.33. Skall ge 3433.33 till potten!
 Potten går jämnt ut med 12766.7kr

 Välj från menyn nedan:
 0. Avsluta. Alla transaktioner sparas på fil.
 1. Läs in en transaktion från tangentbordet.
 2. Skriv ut information om alla transaktioner.
 3. Beräkna totala kostnaden.
 4. Hur mycket är en viss person skyldig?
 5. Hur mycket ligger en viss person ute med?
 6. Lista alla personer mm och FIXA!!!
 0

 Programmet är nu sparat och klart.
 Program ended with exit code: 0
*/

/*
================================================================================
Rapport om uppgiften:
==============================================
 Här skriver du en kort rapport om uppgiften. Ett eller ett par stycken om vad
 uppgiften gick ut på, vilka svårigheter som fanns, vad du tyckte var
 besvärligt och hur du löste problemen. Om det finns frågor att besvara i
 uppgiften ska det göras här.
 
 Deluppgift 6a gick ut på att skapa vårat första lite större program, med flera klasser och aggregat.
 Den innehåller delar från alla tidigare kapitel, så som att läsa in och skriva ut i filer och
 mer avancerade for och while loopar. Programmet håller reda på hur mycket alla personer är skyldiga
 varandra via en stor lista med kvitton, som är formatterade på ett visst sätt.
 
 Några saker hade jag svårt med. För det första var det annorlunda att jobba i ett lite större dokument.
 Man insåg vikten av att skriva vad funktioner och klasser gör, och organisera bra för att inte blanda
 ihop eller tappa bort sig. Sen hade jag lite svårt med att läsa in från filerna. Men det löste sig
 när jag instanserade fin och öppnade rätt fil. Sen var det lite klurigt med t.ex while-loopen som
 fortsätter så länge metoden innanför returnar true, men lösningen blev ganska enkel ändå,
 man kallar bara funktionen inuti själva while-parantesen while().
 
 Det var kul att skriva ett program som har lite mer funktionalitet och kan användas i verkligheten!
 Sen tyckte jag det var coolt med "menyn".
 
 För kompletteringen har jag fixat lite i menyn och gjort om metoden laesIn,
 så den använder den andra funktionen laggTill.
 Jag har fortfarande kvar round i fixa funktionen, men jag gångrar med hundra,
 vilket innebär att alla skillnader mindre än 1 öre antas vara avrundningsfel.
 Annars säger den att potten alltid ej går jämnt ut med en skillnad på ca 7e-12.
 
*/
 
