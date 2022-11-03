/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: 2020

Inlämningsuppgift nr 2

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


#include <iostream>
using namespace std;

int main(){
    int startN, startH, startM, startS;
    int endH, endM, endS, timeDiff, timeStart, timeEnd;
    int fastestN = -1, timeInDay = 86400, counter = 0;
    int fastestT = timeInDay +1; // Sätter omöjlig tid för att alltid gå in i loopen
    
    cout << "Startnummer: ";
    cin >> startN;
    
    while (startN > 0){ // Avbryt loopen om vi sätter in startnummer < 1
        
        cout << "\n" << "Starttid (h m s): ";
        cin >> startH >> startM >> startS;
        cout << "\n" << "Måltid (h m s): ";
        cin >> endH >> endM >> endS;
        
        counter++;
        
        timeStart = (startH*3600) + (startM*60) + startS;
        timeEnd = (endH*3600) + (endM*60) + endS;
        
        timeDiff = timeEnd - timeStart;
        if (timeDiff < 0){ // Hanterar fallet när tiden övergår till nästa dag
            timeDiff += timeInDay;
        }
        
        if (timeDiff < fastestT) { // Uppdatterar snabbaste tiden
            fastestT = timeDiff;
            fastestN = startN;
        }
        
        cout << "\n" << "Startnummer: ";
        cin >> startN;
    }
    
    if (fastestN > 0){ // Ger output vinnaren och dess tid
    cout << "Vinnaren är startnummer: " << fastestN <<"\n";
    cout <<"Med tiden: " << ((fastestT) / 3600) << "h "
         << ((fastestT % 3600) / 60) << "min "
         << (fastestT % 60) << "s \n";
    cout << "Antalet tävlande är: " << counter << "\n";
    } else { // Hanterar fallet med inga tävlande
        cout << "Inga tävlande \n";
    }

  return 0;
}

/*
 ================================================================================
 Här följer programkörningar för alla testdata:
 ==============================================
 Jag testade all data men glömde att spara all testdata... =(
 Jag tar istället med några av de mest övergripande fallen. Kan såklart komplettera med detta om det krävs!
 
 Testdata 3:
 Startnummer: 33
 Starttid (h m s): 17 30 15
 Måltid (h m s): 18 22 35
 Startnummer: 14
 Starttid (h m s): 23 35 00
 Måltid (h m s): 0 12 24
 Startnummer: 26
 Starttid (h m s): 10 11 12
 Måltid (h m s): 20 21 22
 Startnummer: -1
 Vinnaren är startnummer: 14
 Med tiden: 0h 37min 24s
 Antalet tävlande är: 3
 Program ended with exit code: 0 // Automatiskt från Xcode
 
 Testdata 7:
 Startnummer: -1
 Inga tävlande
 Program ended with exit code: 0
 
 Testdata 9:
 Startnummer: 15
 Starttid (h m s): 10 00 00
 Måltid (h m s): 11 00 00
 Startnummer: 12
 Starttid (h m s): 11 00 00
 Måltid (h m s): 10 00 10
 Startnummer: -1
 Vinnaren är startnummer: 15
 Med tiden: 1h 0min 0s
 Antalet tävlande är: 2
 Program ended with exit code: 0
    
================================================================================
Här skriver du en kort rapport om uppgiften. Ett eller ett par stycken om vad
uppgiften gick ut på, vilka svårigheter som fanns, vad du tyckte var
besvärligt och hur du löste problemen. Om det finns frågor att besvara i
uppgiften ska det göras här.
 
 Programmet är ett enkelt program där man kan skriva in tävlandes startnummer och tider för att sedan räkna ut vem som vann. Den använder sig främst av en while loop men även ett flertal if och if-else satser.
 Det jag tyckte var klurigast var hur man skulle få programmet att hantera datumgränsen och räkna ut antalet timmar och minuter från sekunderna. Men det visade sig vara ganska simpelt med datorns heltals-division. Eftersom datorn inte bryr sig om decimalerna löste sig problemet med att dela och sedan använda modulo.
 
 Vad händer i ditt program (testa om du vill) om du rapporterar in två tävlande med olika nummer som har samma totaltid? Är det den första eller den andra som vinner? Varför?
 
 Det som händer i programmet om man skriver in två personer med samma totaltid är att personen som skrevs in först vinner.
 Detta kommer ifrån att if-satsen kollar om värdet är mindre, inte mindre eller lika med. Hade jag gjort <= istället hade den andra personen vunnit.
 
 Varför har vi så många testdata? Är det för att det är kul att köra programmet många gånger?
 Ibland vid programmering börjar man med att skriva sina testdata, sedan gör man programmet. Finns det några fördelar med det?
 
 Vi har så många testdata för att kunna prova alla möjliga fall och se så att programmet uppför sig som förväntat. Det är också därför vi (gärna) skriver testdatan innan själva programmet. Annars hade vi lätt kunnat missa saker så som att den inte kan hantera datumgränsen. Har man sin testdata vet man vad vilka fall man ska programmera för, så som negativa tal och ifall man inte skriver in nått nummer alls.

 
*/
