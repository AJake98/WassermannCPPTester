// Projektname: Wassermann
// Prerelease: 2
// Tests && Features implemented

#include <iostream>
#include <string>
#include "WassermannHeader.h"
//using namespace std;                                                          // CR10.01: 'using namespace' nicht an dieser Stelle

int main()
{
    if (runAllTests()) 
    {
        std::cout << "Alle Tests waren Erfolgreich!" << std::endl;
    }
    else
    {
        std::cout << "Mindestens ein Test ist fehlgeschlagen!" << std::endl;
    }
    // Variablen Definitionen & Initialisierung                                 // CR10.01: Style Guide überdenken
    int day = 0;                                                                // CR10.01: 'i_' nicht erwünscht
    int month = 0;

    inputDayAndMonthByUserAndReturnAsParam(day,month);                          // actual parameter (Aktueller Parameter)

    bool isAquarius = testIfDayAndMonthIsAquarius(day , month);                 // return value (Rückgabewert)
    //isAquarius = false;                                                       // assignment (Zuweisung)
    outputIsAquarius(isAquarius);                     

    return 0;
}



