#include "pch.h"
#include "CppUnitTest.h"
#include "../Wassermann/WassermannHeader.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WassermannTester
{
	TEST_CLASS(testsuiteForTestIfDayAndMonthIsAquarius)
	{
	public:
		
		TEST_METHOD(testForNormalCases)
		{
			Assert::IsFalse(true != testIfDayAndMonthIsAquarius(25, 1));
			Assert::IsFalse(false != testIfDayAndMonthIsAquarius(25, 10));
			Assert::IsFalse(true != testIfDayAndMonthIsAquarius(6, 2));
			Assert::IsFalse(false != testIfDayAndMonthIsAquarius(20, 4));
			Assert::IsFalse(false != testIfDayAndMonthIsAquarius(18, 3));
		}
	};
}

//bool runAllTests()
//{
//    // Normalfälle für testIfDayAndMonthIsAquarius
//    if (true != testIfDayAndMonthIsAquarius(25, 1)) return false;
//    if (false != testIfDayAndMonthIsAquarius(25, 10)) return false;
//    if (true != testIfDayAndMonthIsAquarius(6, 2)) return false;
//    if (false != testIfDayAndMonthIsAquarius(20, 4)) return false;
//    if (false != testIfDayAndMonthIsAquarius(18, 3)) return false;
//
//    // Grenzfälle für testIfDayAndMonthIsAquarius
//    if (false != testIfDayAndMonthIsAquarius(20, 1)) return false;
//    if (true != testIfDayAndMonthIsAquarius(21, 1)) return false;
//    if (true != testIfDayAndMonthIsAquarius(22, 1)) return false;
//    if (true != testIfDayAndMonthIsAquarius(17, 2)) return false;
//    if (true != testIfDayAndMonthIsAquarius(18, 2)) return false;
//    if (false != testIfDayAndMonthIsAquarius(19, 2)) return false;
//    //    if (false != testIfDayAndMonthIsAquarius(21, 0)) return false;
//
//        // Normalfälle für extractDayAndMonthAndCheckFormat
//    int day = 0;
//    int month = 0;
//    extractDayAndMonthAndCheckFormat("10.10.", day, month);
//    if (!(day == 10 && month == 10))return false;
//
//    day = month = 0;
//    extractDayAndMonthAndCheckFormat("01.07.", day, month);
//    if (!(day == 01 && month == 07))return false;
//
//    day = month = 0;
//    extractDayAndMonthAndCheckFormat("01_07_", day, month);
//    if ((day == 01 && month == 07))return false;
//
//    day = month = 0;
//    extractDayAndMonthAndCheckFormat("012222", day, month);
//    if (!(day == 00 && month == 00))return false;
//
//    // Normalfälle für isActuallyADate
//    if (true == isActuallyADate(1, 40)) return false;
//    if (true == isActuallyADate(40, 1)) return false;                           // Manche ungütigen Daten werden als Wassermann evaluiert
//    if (false == isActuallyADate(1, 1)) return false;
//    if (false == isActuallyADate(1, 4)) return false;
//    if (false == isActuallyADate(1, 2)) return false;
//
//    // Grenzfälle für isActuallyADate
//    if (true == isActuallyADate(31, 2)) return false;
//    if (true == isActuallyADate(31, 4)) return false;
//    if (false == isActuallyADate(30, 1)) return false;
//    if (false == isActuallyADate(31, 1)) return false;
//    if (true == isActuallyADate(32, 1)) return false;
//    if (false == isActuallyADate(29, 2)) return false;
//    if (false == isActuallyADate(30, 4)) return false;
//    if (true == isActuallyADate(31, 4)) return false;
//
//    return true;
//}