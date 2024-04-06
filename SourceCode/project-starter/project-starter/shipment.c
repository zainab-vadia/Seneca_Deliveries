#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include "shipment.h"
#include "mapping.h"
#include "truck.h"
#include <stdlib.h> 

// Read shipment details from the user input
struct Shipment readShipmentDetails() {

    struct Shipment shipment = { 0, 0, {0, 0} };
    int validInput, check = 0;
    char temp[4]; // Using a string to capture the column character

    while (1) {

        printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
        validInput = scanf("%lf %lf %s", &shipment.weight, &shipment.volume, temp);

        if (shipment.weight == 0 && shipment.volume == 0 && toupper(temp[0]) == 'X' && temp[1] == '\0') {
            printf("Thanks for shipping with Seneca!\n");
            break;  
        }

        if (validInput == 3) {  // Check if the input is in the correct format
            // Process the destination
            int num;
            char col;
            if (sscanf(temp, "%d%c", &num, &col) == 2) {
                shipment.destination.row = num - 1;
                shipment.destination.col = toupper(col) - 'A';

                if (validateShipment(shipment.weight, shipment.volume, shipment.destination)) {
                    break;  // Exit the loop if the shipment is valid
                }
            }

        }

        while (getchar() != '\n');
    }

    return shipment;
}
// Validates the details of the shipment
int validateShipment(double weight, double volume, struct Point destination)
{
    double validSize[3] = VALID_BOX_SIZE;
    int isValid = 1; // Assume the shipment is valid initially
    struct Map map = populateMap(); // Assume this function populates a map of valid destinations

    // Weight validation
    if (weight > MAX_WEIGHT || weight < MIN_WEIGHT)
    {
        printf("Invalid weight (must be %.lf-%.lf Kg.)\n", (double)(MIN_WEIGHT), (double)(MAX_WEIGHT));
        isValid = 0;
    }

    // Volume validation
    int volumeIsValid = 0;
    for (int i = 0; i < sizeof(validSize) / sizeof(validSize[0]); i++) {
        if (volume == validSize[i]) {
            volumeIsValid = 1;
            break;
        }
    }
    if (!volumeIsValid) {
        printf("Invalid  size\n");
        isValid = 0;
    }

    // Destination validation
    if (!BuildingBlock(destination, map)) {
        printf("Invalid destination\n");
        isValid = 0;
    }

    return isValid;
}