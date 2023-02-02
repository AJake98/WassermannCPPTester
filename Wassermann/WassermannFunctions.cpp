// Projektname: Wassermann
// Prerelease: 2
// Tests && Features implemented

#include <iostream>
#include <string>
#include "WassermannHeader.h"
//using namespace std;  

bool testIfDayAndMonthIsAquarius(int day, int month)                            // function definition (Funktionsdefinition) & function head (Funktionskörper) & formal parameters (Formale Parameter) & return type (Rückgabetyp)
{                                                                               // function body (Funktionskörper)
    bool isAquariusInJanuary = (month == 1 && day >= 21);
    bool isAquariusInFebuary = (month == 2 && day <= 18);
    bool isAquarius = (isAquariusInJanuary || isAquariusInFebuary);
    return isAquarius;
}

void outputIsAquarius(bool isAquarius)
{
    if (isAquarius)
    {                                                                           // block (Block)
        std::cout << "Sie sind ein Wassermann";
    }
    else
    {
        std::cout << "Sie sind kein Wassermann";
    }
}

void extractDayAndMonthAndCheckFormat(std::string dd_mm_, int& day, int& month) // CRM2401: Return bool für Format-Check
{                                                                               // CRM2401: Regex in Betracht ziehen, Keine "Magic Numbers"
    day = 0;
    month = 0;

    // Check Preconditions
    if (!(dd_mm_.length() == 6)) return;
    int pos1stDelimiter = 2;                                                    // Avoid Magic Numbers!
    int pos2ndDelimiter = 5;
    if (!('.' == dd_mm_[pos1stDelimiter] && '.' == dd_mm_[pos2ndDelimiter])) return;                                                                        // CRM2401: Zwischenvariablen? (auch Zeile 35f)   // CRM2401: Konstante zuerst wegen Zuweisungsrisiko
    std::string stringDay = dd_mm_.substr(0, 2);
    std::string stringMonth = dd_mm_.substr(3, 2);
    if (!(std::isdigit(stringDay[0]) && std::isdigit(stringDay[1])
        && std::isdigit(stringMonth[0]) && std::isdigit(stringMonth[1]))) return;


    day = std::stoi(stringDay);
    month = std::stoi(stringMonth);                                             // Upgrade Cpp 11 CRM2401: std::stoi verwenden
}

bool isActuallyADate(int day, int month)
{
    switch (month)                                                              // deliberate fall through used as an implied || 
    {
    case(1):
    case(3):
    case(5):
    case(7):
    case(8):
    case(10):
    case(12):
        if (day > 31) return false;
        break;

    case(4):
    case(6):
    case(9):
    case(11):
        if (day > 30) return false;
        break;

    case(2):
        if (day > 29) return false;
        break;

    default:
        return false;
        break;
    }
    return true;
}

void inputDayAndMonthByUserAndReturnAsParam(int& day, int& month)               // int& sind In- Outparameter
{
    while ((day == 0 && month == 0) || !isActuallyADate(day, month)) {
        std::string dd_mm_ = "";
        std::cout << "Bitte valieden Tag und Monat im Format DD.MM. eingeben" << std::endl;
        std::cin >> dd_mm_;
        extractDayAndMonthAndCheckFormat(dd_mm_, day, month);
    }
}

bool runAllTests()
{
    // Normalfälle für testIfDayAndMonthIsAquarius
    if (true != testIfDayAndMonthIsAquarius(25, 1)) return false;
    if (false != testIfDayAndMonthIsAquarius(25, 10)) return false;
    if (true != testIfDayAndMonthIsAquarius(6, 2)) return false;
    if (false != testIfDayAndMonthIsAquarius(20, 4)) return false;
    if (false != testIfDayAndMonthIsAquarius(18, 3)) return false;

    // Grenzfälle für testIfDayAndMonthIsAquarius
    if (false != testIfDayAndMonthIsAquarius(20, 1)) return false;
    if (true != testIfDayAndMonthIsAquarius(21, 1)) return false;
    if (true != testIfDayAndMonthIsAquarius(22, 1)) return false;
    if (true != testIfDayAndMonthIsAquarius(17, 2)) return false;
    if (true != testIfDayAndMonthIsAquarius(18, 2)) return false;
    if (false != testIfDayAndMonthIsAquarius(19, 2)) return false;
    //    if (false != testIfDayAndMonthIsAquarius(21, 0)) return false;

        // Normalfälle für extractDayAndMonthAndCheckFormat
    int day = 0;
    int month = 0;
    extractDayAndMonthAndCheckFormat("10.10.", day, month);
    if (!(day == 10 && month == 10))return false;

    day = month = 0;
    extractDayAndMonthAndCheckFormat("01.07.", day, month);
    if (!(day == 01 && month == 07))return false;

    day = month = 0;
    extractDayAndMonthAndCheckFormat("01_07_", day, month);
    if ((day == 01 && month == 07))return false;

    day = month = 0;
    extractDayAndMonthAndCheckFormat("012222", day, month);
    if (!(day == 00 && month == 00))return false;

    // Normalfälle für isActuallyADate
    if (true == isActuallyADate(1, 40)) return false;
    if (true == isActuallyADate(40, 1)) return false;                           // Manche ungütigen Daten werden als Wassermann evaluiert
    if (false == isActuallyADate(1, 1)) return false;
    if (false == isActuallyADate(1, 4)) return false;
    if (false == isActuallyADate(1, 2)) return false;

    // Grenzfälle für isActuallyADate
    if (true == isActuallyADate(31, 2)) return false;
    if (true == isActuallyADate(31, 4)) return false;
    if (false == isActuallyADate(30, 1)) return false;
    if (false == isActuallyADate(31, 1)) return false;
    if (true == isActuallyADate(32, 1)) return false;
    if (false == isActuallyADate(29, 2)) return false;
    if (false == isActuallyADate(30, 4)) return false;
    if (true == isActuallyADate(31, 4)) return false;

    return true;
}