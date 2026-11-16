
#include "pch.h"
#include "CppUnitTest.h"

#include <cmath>

#include "var.h"
#include "dod.h"
#include "sum.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace nsVar;
using namespace nsDod;
using namespace nsSum;

namespace Lab09Tests
{
    TEST_CLASS(Lab09_1_Tests)
    {
    public:

        // 1. Перевірка суми при x = 2
        TEST_METHOD(TestSumX2)
        {
            x = 2.0;
            e = 0.0000000001;

            sum();

            double expected =
                0.5 * log((x + 1) / (x - 1));

            Assert::AreEqual(expected, s, 0.000000001);
        }

        // 2. Перевірка суми при x = 2.5
        TEST_METHOD(TestSumX2_5)
        {
            x = 2.5;
            e = 0.0000000001;

            sum();

            double expected =
                0.5 * log((x + 1) / (x - 1));

            Assert::AreEqual(expected, s, 0.000000001);
        }

        // 3. Перевірка суми при x = 3
        TEST_METHOD(TestSumX3)
        {
            x = 3.0;
            e = 0.0000000001;

            sum();

            double expected =
                0.5 * log((x + 1) / (x - 1));

            Assert::AreEqual(expected, s, 0.000000001);
        }

        // 4. Перевірка від'ємного x = -2
        TEST_METHOD(TestSumNegativeX2)
        {
            x = -2.0;
            e = 0.0000000001;

            sum();

            double expected =
                0.5 * log((x + 1) / (x - 1));

            Assert::AreEqual(expected, s, 0.000000001);
        }

        // 5. Перевірка від'ємного x = -3
        TEST_METHOD(TestSumNegativeX3)
        {
            x = -3.0;
            e = 0.0000000001;

            sum();

            double expected =
                0.5 * log((x + 1) / (x - 1));

            Assert::AreEqual(expected, s, 0.000000001);
        }

        // 6. Перевірка рекурентної формули
        TEST_METHOD(TestDod)
        {
            x = 2.0;
            n = 1;
            a = 1.0 / x;

            dod();

            Assert::AreEqual(1.0 / 24.0, a, 0.000000001);
        }

        // 7. Перевірка перших двох доданків
        TEST_METHOD(TestFirstTwoTerms)
        {
            x = 2.0;
            e = 0.1;

            sum();

            double expected = 0.5 + 1.0 / 24.0;

            Assert::AreEqual(expected, s, 0.000000001);
            Assert::AreEqual(2, n + 1);
        }

        // 8. Перевірка кількості доданків
        TEST_METHOD(TestTermsCount)
        {
            x = 2.0;
            e = 0.01;

            sum();

            Assert::AreEqual(3, n + 1);
        }

        // 9. Перевірка додатної суми
        TEST_METHOD(TestPositiveSum)
        {
            x = 5.0;
            e = 0.000001;

            sum();

            Assert::IsTrue(s > 0.0);
        }

        // 10. Перевірка повторного обчислення
        TEST_METHOD(TestRepeatedCalculation)
        {
            x = 2.0;
            e = 0.0000001;

            sum();
            double first = s;

            sum();
            double second = s;

            Assert::AreEqual(first, second, 0.000000001);
        }
    };
}
