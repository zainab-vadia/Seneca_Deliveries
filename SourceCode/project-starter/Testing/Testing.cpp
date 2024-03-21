#include "pch.h"
#include "CppUnitTest.h"
#include "fuctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(distanceBlackBox)
	{
		public:	
		TEST_METHOD(T001)
		{
			struct Map OGMap = populateMap();
			struct Point pt1 = {0,0};
			struct Point pt2 = {0,3};
			struct Route expectedPath = { {{0,1},{0,2},{0,3} }, 3, 0};
			struct Route result = shortestPath(&OGMap, pt1, pt2);
			Assert::IsTrue(areRoutesEqual(expectedPath, result));
		}	

		TEST_METHOD(T002)
		{
			// Test case for 2 possible paths
			struct Map OGMap = populateMap();
			struct Point pt1 = {11, 1};
			struct Point pt2 = {11, 6};
			struct Route expectedPath1 = { {{10, 2}, {10, 3}, {10, 4}, {10, 5}, {11, 6}},5,0 };
			struct Route expectedPath2 = { {{12, 2}, {12, 3}, {12, 4}, {12, 5}, {11, 6} }, 5, 0};
			struct Route result = shortestPath(&OGMap, pt1, pt2);
			Assert::IsTrue(areRoutesEqual(expectedPath1, result) || areRoutesEqual(expectedPath2, result));
		}

		TEST_METHOD(T003)
		{
			// Error Case
			struct Map OGMap = populateMap();
			struct Point pt1 = {-1, 1};
			struct Point pt2 = {11, 7};
			struct Route expectedPath = {{0},0,0};
			struct Route result = shortestPath(&OGMap, pt1, pt2);
			Assert::IsTrue(areRoutesEqual(expectedPath, result));
		}

		TEST_METHOD(T004)
		{
			// Error case
			struct Map OGMap = populateMap();
			struct Point pt1 = {0, 0};
			struct Point pt2 = {0, 0};
			struct Route expectedPath = {{0},0,0};
			struct Route result = shortestPath(&OGMap, pt1, pt2);
			Assert::IsTrue(areRoutesEqual(expectedPath, result));
		}
		// member functions to help with testing
		private:
		bool areRoutesEqual(Route path1, Route path2)
		{
			if (path1.numPoints != path2.numPoints){
			    return false;
			}
			if (path1.numPoints == 0){
				return true; 
			}
			for (int i = 0; i < path1.numPoints; ++i)
			{
			    if (path1.points[i].col != path2.points[i].col || path1.points[i].row != path2.points[i].row)
				return false;
			}

			return true;
		}
	};
}
