#include "pch.h"
#include "CppUnitTest.h"
#include "fuctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	struct Map OGMap = populateMap();
  
	TEST_CLASS(distanceBlackBox)
	{
	public:
		TEST_METHOD(T001)
    {
				struct Point pt1 = {0,0};
				struct Point pt2 = {0,3};
				struct Route exp_res = {{0,1},{0,2},{0,3},3,0};
				struct Route res = shortestPath(OGMap, pt1, pt2);
				Assert::IsTrue(areRoutesEqual(expectedPath, result));
    }

    TEST_METHOD(T002)
		{
				// Test case for 2 possible paths
				struct Point pt1 = {11, 1};
				struct Point pt2 = {11, 6};
				struct Route expectedPath1 = {{10, 2}, {10, 3}, {10, 4}, {10, 5}, {11, 6},5,0};
				struct Route expectedPath1 = {{12, 2}, {12, 3}, {12, 4}, {12, 5}, {11, 6},5,0};
				struct Route result = shortestPath(OGMap, pt1, pt2);
				Assert::IsTrue(arePathsEqual(expectedPath, result));
		}

		TEST_METHOD(T003)
		{
				// Error Case
				struct Point pt1 = {-1, 1};
				struct Point pt2 = {11, 7};
				struct Route expectedPath1 = {{0},0,0};
				struct Route result = shortestPath(OGMap, pt1, pt2);
				Assert::IsTrue(arePathsEqual(expectedPath, result));
		}

		TEST_METHOD(T004)
		{
				// Error case
				struct Point pt1 = {0, 0};
				struct Point pt2 = {0, 0};
				struct Route expectedPath1 = {{0},0,0};
				struct Route result = shortestPath(OGMap, pt1, pt2);
				Assert::IsTrue(arePathsEqual(expectedPath, result));
		}
		// member functions to help with testing
		private:
    bool areRouteEqual(const std::vector<std::pair<int, int>>& path1, const std::vector<std::pair<int, int>>& path2)
    {
        if (path1.numPoints != path2.numPoints)
            return false;
				}
				if (path1.numPoints == 0){
						return true; 
				}
        for (int i = 0; i < path1.numPoits; ++i)
        {
            if (path1.points[i] != path2.points[i])
                return false;
        }

        return true;
    }
	};

	
}
