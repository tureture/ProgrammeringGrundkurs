/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

Inlämningsuppgift nr 1

Namn: Ture Hassler

Personummer: 9904122091

Fyll i (alt stryk det som ej är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja

Jag har använt kompilator/editor (namn/version): Xcode / 11.6

Jag har använt följande dator (PC/Mac/Annat): Mac
      med operativsystemet: macOS Catalina

Jag har arbetat ungefär  1 timmar med denna uppgift
================================================================================
*/
// Slut på kommentar

#include <iostream>
using namespace std;

int main(){

  int a;
  int b = 12;
    a = 0; // Felet var felaktig syntax, missat semikolon

  cout << "a = " << a << endl;
  cout << a+b << '\n' << "a-b = " << a-b << endl;

  return 0;
}

/*
 ================================================================================
 Här följer programkörningar för alla testdata:
 ==============================================
 a = 0
 12
 a-b = -12
 Program ended with exit code: 0 // Obs den här delen kommer automatiskt från Xcode
 
================================================================================
Här skriver du en kort rapport om uppgiften. Ett eller ett par stycken om vad
uppgiften gick ut på, vilka svårigheter som fanns, vad du tyckte var
besvärligt och hur du löste problemen. Om det finns frågor att besvara i
uppgiften ska det göras här.
 
Uppgiften fungerade som ett exempel på att skriva och arbeta med en c++ fil. Felet var missad syntax.
 
*/

