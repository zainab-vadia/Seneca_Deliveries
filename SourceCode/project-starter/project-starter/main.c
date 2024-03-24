#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "shipment.h"
#include "truck.h"


int main(void)
{
    int option;
    struct Map baseMap;
    struct Route blueRoute, greenRoute, yellowRoute;
    struct Shipment shipment = { 0 };
    struct Truck trucks[3];

    do
    {
        for (int i = 0; i < 50; i++) printf("\n");

        printf("Choose an option:\n");
        printf("1. Perform Shipment Handling\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        while (scanf("%d", &option) != 1)
        {
            printf("Invalid input. Please enter a number: ");
            while (getchar() != '\n');
        }

        for (int i = 0; i < 50; i++) printf("\n");

        switch (option)
        {
        case 1:
            baseMap = populateMap();
            blueRoute = getBlueRoute();
            greenRoute = getGreenRoute();
            yellowRoute = getYellowRoute();

            trucks[0] = initializeTruck(blueRoute, 'B');
            trucks[1] = initializeTruck(yellowRoute, 'Y');
            trucks[2] = initializeTruck(greenRoute, 'G');

            do
            {
                shipment = inputShipment();
                if (shipment.weight != 0)
                {
                    findBestTruck(trucks, 3, shipment, &baseMap);
                }
            } while (shipment.weight != 0);
            break;

        case 0:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid option. Please try again.\n");
        }

        printf("Press Enter to continue...");
        while (getchar() != '\n');

    } while (option != 0);

    return 0;
}
