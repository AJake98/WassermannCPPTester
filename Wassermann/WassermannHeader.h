#pragma once
#include <string>


void inputDayAndMonthByUserAndReturnAsParam(int& day, int& month);
bool isActuallyADate(int day, int month);
void extractDayAndMonthAndCheckFormat(std::string dd_mm_, int& day, int& month);
void outputIsAquarius(bool isAquarius);
bool testIfDayAndMonthIsAquarius(int day, int month);
bool runAllTests();