#include "pch.h"
#include "CppUnitTest.h"
#include "fuctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(ValidPackageBlackBox)
	{
	public:

		//TEST CASES FOR PACKAGE
		TEST_METHOD(T001)
		{
			int expected = 1; // True
			double weight = 1200;
			double volume = 1;
			struct Point destination = { 24 - 1 , 'Y' - 'A' };
			// represents the address '24Y'
			int result = validateShipment(weight, volume, destination);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(T002)
		{
			int expected = 0; // False
			double weight = 1100;
			double volume = 2;
			struct Point destination = { 8 - 1 , 'Y' - 'A' };
			// represents the address '8Y'
			int result = validateShipment(weight, volume, destination);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(T003)
		{
			int expected = 0; // False
			double weight = 800;
			double volume = 1;
			struct Point destination = { 28 - 1 , 'Q' - 'A' };
			// represents the address '28Q'
			int result = validateShipment(weight, volume, destination);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T004)
		{
			int expected = 0; // False
			double weight = 1500;
			double volume = 1.5;
			struct Point destination = { 40 - 1 , 'S' - 'A' };
			// represents the address '40S'
			int result = validateShipment(weight, volume, destination);
			Assert::AreEqual(expected, result);
		}
	};


	TEST_CLASS(enoughSpaceBlackBox)
	{
	public:
		TEST_METHOD(T005)
		{	//Truck has enough capacity for shipment.
			int expected = 1; // True 
			struct Truck truck = { 1000, 40, getBlueRoute(), { 18 - 1 , 'Y' - 'A' } };
			struct Shipment shipment = { 200, 10, {12 - 1 , 'M' - 'A'} };
			int result = enoughSpace(truck, shipment);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T006)
		{	// Truck exceeding the weight limit.
			int expected = 0; // False 
			struct Truck truck = { 1150, 20, getYellowRoute(), { 15 - 1 , 'R' - 'A' } };
			struct Shipment shipment = { 100, 0.5, {5 - 1 , 'G' - 'A'} };
			int result = enoughSpace(truck, shipment);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T007)
		{	// Truck exceeding the volume limmit.
			int expected = 0; // False
			struct Truck truck = { 200, 40, getGreenRoute(), { 5 - 1 , 'D' - 'A' } };
			struct Shipment shipment = { 100, 15, {10 - 1 , 'F' - 'A'} };
			int result = enoughSpace(truck, shipment);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T008)
		{	//Truck cannot ship package due to weight and volume constraints.
			int expected = 0; // False 
			struct Truck truck = { 1190, 40, getBlueRoute(), { 9 - 1 , 'I' - 'A' } };
			struct Shipment shipment = { 20, 12, {7 - 1 , 'H' - 'A'} };
			int result = enoughSpace(truck, shipment);
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(distanceBlackBox)
	{
	public:
		//TEST CASES FOR PACKAGE
		TEST_METHOD(T009)
		{
			double expected = 5.6568542494923806;
			struct Point p1 = { 2, 3 };
			struct Point p2 = { 6, 7 };
			double result = distance(&p1, &p2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T010)
		{
			double expected = 5.0;
			struct Point p1 = { 1.5, 2.5 };
			struct Point p2 = { 4.5, 6.5 };
			double result = distance(&p1, &p2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T011)
		{
			double expected = 33.941125496954278;
			struct Point p1 = { 1 - 1, 'A' - 'A' };
			struct Point p2 = { 25 - 1, 'Y' - 'A' };
			double result = distance(&p1, &p2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T012)
		{
			double expected = 0.0;
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 0, 0 };
			double result = distance(&p1, &p2);
			Assert::AreEqual(expected, result);
		}
	};


	TEST_CLASS(getClosestPointBlackBox)
	{
	public:
		//TEST CASES FOR PACKAGE
		TEST_METHOD(T013)
		{
			int expected = -1;
			struct Route route = { 0 };
			struct Point target = { 25 - 1, 'Y' - 'A' };
			int result = getClosestPoint(&route, target);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T014)
		{
			int expected = 0;
			struct Route route = getBlueRoute();
			struct Point target = { 1 - 1, 'A' - 'A' };
			int result = getClosestPoint(&route, target);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T015)
		{
			int expected = 41;
			struct Route route = getGreenRoute();
			struct Point target = { 8 - 1, 'Y' - 'A' };
			int result = getClosestPoint(&route, target);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(T016)
		{
			int expected = 47;
			struct Route route = getYellowRoute();
			struct Point target = { 22 - 1, 'Y' - 'A' };
			int result = getClosestPoint(&route, target);
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(LoadShipmentBlackBox)
	{
	public:

		TEST_METHOD(T017)
		{
			Truck truck;
			truck.presentVolumeInM = 20;
			truck.presentWeightInKg = 1190; // Only 10 kg of capacity left.
			Shipment shipment = { 20, 5 }; // Shipment exceeds weight capacity by 10 kg.

			loadShipmentDiversions(&truck, shipment);

			// Verify the truck's load has not been updated.
			Assert::AreEqual(1190.0, truck.presentWeightInKg);
			Assert::AreEqual(20.0, truck.presentVolumeInM);
		}

		TEST_METHOD(T018)
		{
			Truck truck;
			truck.presentVolumeInM = 48; // Only 2 m^3 of capacity left.
			truck.presentWeightInKg = 500;
			Shipment shipment = { 200, 3 }; // Shipment exceeds volume capacity by 1 m^3.

			loadShipmentDiversions(&truck, shipment);

			// Verify the truck's load has not been updated.
			Assert::AreEqual(500.0, truck.presentWeightInKg);
			Assert::AreEqual(48.0, truck.presentVolumeInM);
		}

		TEST_METHOD(T019)
		{
			Truck truck;
			truck.presentVolumeInM = 45; // 5 m^3 left to reach MAX_VOLUME
			truck.presentWeightInKg = 1150; // 50 kg left to reach MAX_WEIGHT
			Shipment shipment = { 50, 5 }; // Shipment that exactly matches the remaining capacity.

			loadShipmentDiversions(&truck, shipment);

			Assert::AreEqual(static_cast<double>(MAX_WEIGHT), truck.presentWeightInKg);
			Assert::AreEqual(static_cast<double>(MAX_VOLUME), truck.presentVolumeInM);

		}

		TEST_METHOD(T020)
		{
			Truck truck;
			truck.presentVolumeInM = MAX_VOLUME;
			truck.presentWeightInKg = MAX_WEIGHT; // Truck is already full.
			Shipment shipment = { 200, 10 }; // Any shipment should not be loaded.

			loadShipmentDiversions(&truck, shipment);

			// Verify the truck's load remains unchanged.
			Assert::AreEqual(static_cast<double>(MAX_WEIGHT), truck.presentWeightInKg);
			Assert::AreEqual(static_cast<double>(MAX_VOLUME), truck.presentVolumeInM);
		}
	};


	TEST_CLASS(readShipmentDetailsBlackBox) {
public:

	TEST_METHOD(T021) {
		// Manual Test: Testing invalid weight input (exceeding the maximum weight limit).
		// Test Data: "1600 1 17G"
		// Expected Result: Function should indicate the weight is invalid (must be 1-1200 Kg.)

		// Note: This test must be conducted manually due to the nature of the readShipmentDetails function.
		// The following code is a placeholder and represents the manual test process.
		printf("Manual Test T009: Run the program and enter '1100 2 17G' when prompted for shipment details.\n");
		printf("Expected Result: The input should be rejected with an appropriate message indicating the weight violation.\n");
	}

	TEST_METHOD(T022) {
		// Manual Test: Testing invalid weight input (exceeding the maximum weight limit).
		// Test Data: "1100 2 17G"
		// Expected Result: Function should indicate the weight is invalid (must be 1-1200 Kg.)

		// Note: This test must be conducted manually due to the nature of the readShipmentDetails function.
		// The following code is a placeholder and represents the manual test process.
		printf("Manual Test T010: Run the program and enter '1100 2 17G' when prompted for shipment details.\n");
		printf("Expected Result: The input should be rejected with an appropriate message indicating the size violation.\n");
	}

	TEST_METHOD(T023) {
		// Manual Test: Testing invalid weight input (exceeding the maximum weight limit).
		// Test Data: "1100 5 29G"
		// Expected Result: Function should indicate the weight is invalid (must be 1-1200 Kg.)

		// Note: This test must be conducted manually due to the nature of the readShipmentDetails function.
		// The following code is a placeholder and represents the manual test process.
		printf("Manual Test T011: Run the program and enter '1100 5 29G' when prompted for shipment details.\n");
		printf("Expected Result: The input should be rejected with an appropriate message indicating the incorrect destination.\n");
	}

	TEST_METHOD(T024) {
		// Manual Test: Testing invalid weight input (exceeding the maximum weight limit).
		// Test Data: "500 1 3E"
		// Expected Result: Function should indicate the weight is invalid (must be 1-1200 Kg.)

		// Note: This test must be conducted manually due to the nature of the readShipmentDetails function.
		// The following code is a placeholder and represents the manual test process.
		printf("Manual Test T012: Run the program and enter '500 1 3E' when prompted for shipment details.\n");
		printf("Expected Result: An initialized and valid shipment with weight: 500 kg, volume: 1 cubic meters, destination: point 3E.\n");
	}
	};

	TEST_CLASS(ValidPackageWhiteBox)
	{
	public:
		//TEST CASES FOR PACKAGE
		TEST_METHOD(TW001)
		{
			int expected = 1; // True
			double weight = 1200;
			double volume = 0.5;
			struct Point destination = { 24 - 1 , 'Y' - 'A' };
			// represents the address '24Y'
			int result = validateShipment(weight, volume, destination);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW002)
		{
			int expected = 0; // False
			double weight = 1600;
			double volume = 2;
			struct Point destination = { 8 - 1 , 'Y' - 'A' };
			// represents the address '8Y'
			int result = validateShipment(weight, volume, destination);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW003)
		{
			int expected = 0; // False
			double weight = 1501;
			double volume = 2.5;
			struct Point destination = { 28 - 1 , 'X' - 'A' };
			// represents the address '28X'
			int result = validateShipment(weight, volume, destination);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW004)
		{
			int expected = 0; // False
			double weight = -1;
			double volume = 0;
			struct Point destination = { 1 - 1 , 'A' - 'A' };
			// represents the address '1A'
			int result = validateShipment(weight, volume, destination);
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(areNeighbourWhiteBox)
	{
	public:
		//TEST CASES FOR PACKAGE
		TEST_METHOD(TW009)
		{
			int expected = 1; // True
			struct Point p1 = { 5 - 1 , 'J' - 'A' };
			struct Point p2 = { 5 - 1, 'K' - 'A' };
			int result = areDirectNeighbors(p1, p2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW010)
		{
			int expected = 1; // True
			struct Point p1 = { 7 - 1 , 'T' - 'A' };
			struct Point p2 = { 8 - 1 , 'T' - 'A' };
			int result = areDirectNeighbors(p1, p2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW011)
		{
			int expected = 0; // False
			struct Point p1 = { 1 - 1 , 'J' - 'A' };
			struct Point p2 = { 3 - 1, 'S' - 'A' };
			int result = areDirectNeighbors(p1, p2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW012)
		{
			int expected = 0; // False
			struct Point p1 = { 13 - 1 , 'H' - 'A' };
			struct Point p2 = { 13 - 1 , 'H' - 'A' };
			int result = areDirectNeighbors(p1, p2);
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(canShipWhiteBox)
	{
	public:
		//TEST CASES FOR PACKAGE
		TEST_METHOD(TW013)
		{
			int expected = 1; // True
			struct Truck truck = { 200, 35,getBlueRoute(), { 12 - 1 , 'Y' - 'A'   } };
			struct Shipment shipment = { 700, 5, {7 - 1 , 'K' - 'A'} };
			int result = enoughSpace(truck, shipment);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW014)
		{
			int expected = 0; // False
			struct Truck truck = { 1200,  40,getYellowRoute(), { 18 - 1, 'F' - 'A'   } };
			struct Shipment shipment = { 50, 1, {24 - 1 , 'G' - 'A'} };
			int result = enoughSpace(truck, shipment);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW015)
		{
			int expected = 1; // True
			struct Truck truck = { 950, 49.5,getGreenRoute(), { 2 - 1, 'T' - 'A'   } };
			struct Shipment shipment = { 250, 0.5,{ 12 - 1 , 'Y' - 'A'} };
			int result = enoughSpace(truck, shipment);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW016)
		{
			int expected = 0; // Flase
			struct Truck truck = { 1000, 50, getBlueRoute(), { 8 - 1 , 'S' - 'A'   } };
			struct Shipment shipment = { 120, 1, {5 - 1, 'H' - 'A'} };
			int result = enoughSpace(truck, shipment);
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(distanceWhiteBox)
	{
	public:
		//TEST CASES FOR PACKAGE
		TEST_METHOD(TW017)
		{
			double expected = 0;
			struct Point p1 = { 2, 5 };
			struct Point p2 = { 2, 5 };
			double result = distance(&p1, &p2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW018)
		{
			double expected = 5;
			struct Point p1 = { 1.5, 2.5 };
			struct Point p2 = { 4.5, 6.5 };
			double result = distance(&p1, &p2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW019)
		{
			double expected = 0;
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 0, 0 };
			double result = distance(&p1, &p2);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW020)
		{
			double expected = 25;
			struct Point p1 = { 1, 'A' - 'A' };
			struct Point p2 = { 8, 'Y' - 'A' };
			double result = distance(&p1, &p2);
			Assert::AreEqual(expected, result);
		}
	};

	TEST_CLASS(getClosestPointWhiteBox)
	{
	public:
		//TEST CASES FOR PACKAGE
		TEST_METHOD(TW021)
		{
			int expected = -1;
			struct Route route = { 0 };
			struct Point target = { 0 };
			int result = getClosestPoint(&route, target);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW022)
		{
			int expected = 8;
			struct Route route = getBlueRoute();
			struct Point target = { 7 - 1, 'E' - 'A' };
			int result = getClosestPoint(&route, target);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW023)
		{
			int expected = 24;
			struct Route route = getGreenRoute();
			struct Point target = { 2 - 1, 'Q' - 'A' };
			int result = getClosestPoint(&route, target);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TW024)
		{
			int expected = 44;
			struct Route route = getYellowRoute();
			struct Point target = { 3 - 1, 'V' - 'A' };
			int result = getClosestPoint(&route, target);
			Assert::AreEqual(expected, result);
		}
	};
};
