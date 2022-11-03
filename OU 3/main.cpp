/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

Inlämningsuppgift nr 3

Namn: Ture Hassler

Personummer: 9904122091

Fyll i (alt stryk det som ej är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kompilator/editor (namn/version): Xcode / 11.6

Jag har använt följande dator (PC/Mac/Annat): Mac
      med operativsystemet: macOS Catalina

Jag har arbetat ungefär 3 timmar med denna uppgift
================================================================================
*/
// Inläming 3 av Ture Hassler

#include <iostream>
using namespace std;

// Deklarationer av funktioner
void skrivInfo();
int lasEttTal();
char lasOp();
void ordna(int &tal1, int &tal2);
int berakna(int num1, int num2, char type);
void skrivResultat(int results);

// Main funktion. Se skrivInfo() för information.
int main(){

    int tal1, tal2, svar;
    char type;
  
    skrivInfo();

    tal1 = lasEttTal();
    tal2 = lasEttTal();
    type = lasOp();

    ordna(tal1,tal2);

    svar = berakna(tal1,tal2,type);
    skrivResultat(svar);

    return 0;
}

// Skriver ut i consolen vad programmet gör och vilken input som förväntas.
void skrivInfo(){
    cout << "Skriv först in 2 tal. Välj sedan vilken matematik-operation du vill göra. Funktionen går från det lägsta till det högsta talet och adderar, multiplicerar eller adderar kvadraterna beroende på ditt val. \n";
}

// Läser in och returnar ett tal från användaren
int lasEttTal() {
    int num;
    cout << "Skriv in ett tal: ";
    cin >> num;
    return num;
}

// Läser in och returnar en bokstav från användaren
char lasOp() {
    char type;
    cout << "Skriv a för addition, m för mulitplikation och k för kvadratmultiplikation. \n";
    cout << "Välj metod: ";
    cin >> type;
    return type;
}

// Ändrar ordningen på talen, så att den minsta är först.
void ordna(int &tal1, int &tal2) {
    int temp;
    if (tal1 > tal2) {
        temp = tal1;
        tal1 = tal2;
        tal2 = temp;
    }
}

// Beräknar och returnar resultatet. 3 olika beräkningar beroende på type.
int berakna(int num1, int num2, char type) {
    int sum;
    
    if (type == 'a') {
        sum = 0;
        for(int i = num1; i <= num2; i++){
            sum += i;
        }
    } else if (type == 'm'){
        sum = 1;
        for(int i = num1; i <= num2; i++){
            sum *= i;
        }
    } else {
        sum = 0;
        for(int i = num1; i <= num2; i++){
            sum += i*i;
        }
    }
    return sum;
}

// Skriver resultatet i console
void skrivResultat(int results){
    cout << "Resultatet blev: " << results <<"\n";
}

/*
 ================================================================================
 Här följer programkörningar för alla testdata:
 ==============================================
 
 Skriv först in 2 tal. Välj sedan vilken matematik-operation du vill göra. Funktionen går från det lägsta till det högsta talet och adderar, multiplicerar eller adderar kvadraterna beroende på ditt val.
 Skriv in ett tal: 3
 Skriv in ett tal: 5
 Skriv a för addition, m för mulitplikation och k för kvadratmultiplikation.
 Välj metod: a
 Resultatet blev: 12
 Program ended with exit code: 0
 
 Skriv först in 2 tal. Välj sedan vilken matematik-operation du vill göra. Funktionen går från det lägsta till det högsta talet och adderar, multiplicerar eller adderar kvadraterna beroende på ditt val.
 Skriv in ett tal: 3
 Skriv in ett tal: 5
 Skriv a för addition, m för mulitplikation och k för kvadratmultiplikation.
 Välj metod: m
 Resultatet blev: 60
 Program ended with exit code: 0
 
 Skriv först in 2 tal. Välj sedan vilken matematik-operation du vill göra. Funktionen går från det lägsta till det högsta talet och adderar, multiplicerar eller adderar kvadraterna beroende på ditt val.
 Skriv in ett tal: 3
 Skriv in ett tal: 5
 Skriv a för addition, m för mulitplikation och k för kvadratmultiplikation.
 Välj metod: k
 Resultatet blev: 50
 Program ended with exit code: 0
 
 Skriv först in 2 tal. Välj sedan vilken matematik-operation du vill göra. Funktionen går från det lägsta till det högsta talet och adderar, multiplicerar eller adderar kvadraterna beroende på ditt val.
 Skriv in ett tal: -3
 Skriv in ett tal: 5
 Skriv a för addition, m för mulitplikation och k för kvadratmultiplikation.
 Välj metod: m
 Resultatet blev: 0
 Program ended with exit code: 0
 
 Skriv först in 2 tal. Välj sedan vilken matematik-operation du vill göra. Funktionen går från det lägsta till det högsta talet och adderar, multiplicerar eller adderar kvadraterna beroende på ditt val.
 Skriv in ett tal: 5
 Skriv in ett tal: 3
 Skriv a för addition, m för mulitplikation och k för kvadratmultiplikation.
 Välj metod: a
 Resultatet blev: 12
 Program ended with exit code: 0
 
 Skriv först in 2 tal. Välj sedan vilken matematik-operation du vill göra. Funktionen går från det lägsta till det högsta talet och adderar, multiplicerar eller adderar kvadraterna beroende på ditt val.
 Skriv in ett tal: -3
 Skriv in ett tal: -5
 Skriv a för addition, m för mulitplikation och k för kvadratmultiplikation.
 Välj metod: a
 Resultatet blev: -12
 Program ended with exit code: 0
 
 Skriv först in 2 tal. Välj sedan vilken matematik-operation du vill göra. Funktionen går från det lägsta till det högsta talet och adderar, multiplicerar eller adderar kvadraterna beroende på ditt val.
 Skriv in ett tal: 1
 Skriv in ett tal: 100
 Skriv a för addition, m för mulitplikation och k för kvadratmultiplikation.
 Välj metod: k
 Resultatet blev: 338350
 Program ended with exit code: 0

    
================================================================================
Här skriver du en kort rapport om uppgiften. Ett eller ett par stycken om vad
uppgiften gick ut på, vilka svårigheter som fanns, vad du tyckte var
besvärligt och hur du löste problemen. Om det finns frågor att besvara i
uppgiften ska det göras här.
 
 Programmet tar 2 tal som input och sen får man välja mellan 3 olika räknemetoder. Uppgiften gick ut på att introducera och vänja sig med att jobba med funktioner.
 Den här uppgiften kändes ganska lätt, men det var lite klurigt att fatta att man ska deklarera funktionerna högst upp i förväg.
 
 Tycker du att det finns någon fördel att använda funktioner för att utföra olika uppgifter i programmet, jämfört med hur det såg ut i OU2 där allt hände i huvudprogrammet?
 Jag tycker man märker klara fördelar med att jobba med funktioner! Det blir mycket lättare att upprepa samma kod flera gånger och framför allt blir det hela mycket mer läsbart. Allt blir bättre organsierat.
 Jämför man med O2 så är det här mycket lättare att förstå vad programmet handlar om.
 
 I någon av dina skrivna funktioner använder du dig troligen av referensparametrar. Varför gör man inte det jämt?
 Man vill gärna undvika att använda referensparametrar när det inte behövs eftersom det då finns risk att olika program använder och ändrar samma variabel, vilket kan göra att koden slutar fungera.

*/

