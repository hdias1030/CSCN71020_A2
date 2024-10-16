#include "pch.h"
#include "CppUnitTest.h"
#include "../BCSRec/main.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BCSRecTest
{
	TEST_CLASS(BCSRecTests)
	{
	public:
		
		TEST_METHOD(TestPerimeter_10)
		{
			int expectedPerimeter = 10;
			int testPerimeterLength = 3;
			int testPerimeterWidth = 2;
			int testGetPerimiter = getPerimeter(&testPerimeterLength, &testPerimeterWidth);

			Assert::AreEqual(expectedPerimeter, testGetPerimiter);
		}

		TEST_METHOD(TestArea_32)
		{
			int expectedArea = 32;
			int testAreaLength = 8;
			int testAreaWidth = 4;
			int testGetArea = getArea(&testAreaLength, &testAreaWidth);

			Assert::AreEqual(expectedArea, testGetArea);
		}

		TEST_METHOD(TestSetLength_1)
		{
			int testLength;

			//should set to 1 since range is 1 to 99, inclusive
			setLength(1, &testLength);
			
			Assert::AreEqual(1, testLength);
		}

		TEST_METHOD(TestSetLength_100)
		{
			int testLength;

			//should not set to 100 since range is 1 to 99, inclusive
			setLength(100, &testLength);

			Assert::AreNotEqual(100, testLength);
		}

		TEST_METHOD(TestSetLength_1000000)
		{
			int testLength;

			//should not set since 1000000 is out of range
			setLength(1000000, &testLength);

			Assert::AreNotEqual(1000000, testLength);
		}

		TEST_METHOD(TestSetWidth_1)
		{
			int testWidth;

			//should set to 1 since range is 1 to 99, inclusive
			setWidth(1, &testWidth);

			Assert::AreEqual(1, testWidth);
		}

		TEST_METHOD(TestSetWidth_100)
		{
			int testWidth;

			//should not set to 100 since range is 1 to 99, inclusive
			setWidth(100, &testWidth);

			Assert::AreNotEqual(100, testWidth);
		}

		TEST_METHOD(TestSetWidth_Negative12324)
		{
			int testWidth;

			//should not set since -12324 is out of range
			setWidth(-12324, &testWidth);

			Assert::AreNotEqual(-12324, testWidth);
		}
	};
}
