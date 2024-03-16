#include "pch.h"
#include "CppUnitTest.h"
#include "fuctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	

	TEST_CLASS(distanceBlackBox)
	{
	public:
		//TEST CASES FOR PACKAGE
		TEST_METHOD(T017)
		{
			double expected = 5.6568542494923806;
			struct Point p1 = {2, 3};
			struct Point p2 = {6, 7};
			double result = distance(&p1, &p2); 
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T018)
		{
			double expected = 5.0;
			struct Point p1 = { 1.5, 2.5 };
			struct Point p2 = { 4.5, 6.5 };
			double result = distance(&p1, &p2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T019)
		{
			double expected = 33.941125496954278;
			struct Point p1 = { 1 - 1, 'A' - 'A' };
			struct Point p2 = { 25 - 1, 'Y' - 'A' };
			double result = distance(&p1, &p2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T020)
		{
			double expected = 0.0;
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 0, 0 };
			double result = distance(&p1, &p2);
			Assert::AreEqual(expected, result);
		}
	};

	
}