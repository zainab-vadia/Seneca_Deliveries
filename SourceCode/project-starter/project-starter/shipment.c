#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include "shipment.h"
#include "mapping.h"
#include "truck.h"

// Read shipment details from the user input
struct Shipment readShipmentDetails()
{
    struct Shipment shipment = {0, 0, {0, 0}};
    int temp1 = 0, validInput, isShipmentValid = 0;
    char temp2 = 0;

    do {
        printf("Enter shipment weight, box size, and destination (0 0 x to stop): ");
        validInput = scanf("%lf %lf %d%c", &shipment.weight, &shipment.volume, &temp1, &temp2);
        if (validInput == 4) { // if the user input matches the expected format
            shipment.destination.row = temp1 - 1; // Adjusting user input to zero-based index
            shipment.destination.col = toupper(temp2) - 'A'; // Convert column to zero-based index
            isShipmentValid = validateShipment(shipment.weight, shipment.volume, shipment.destination);
        } else {
            isShipmentValid = 1; // If input doesn't match expected format, try again
        }
    } while (!isShipmentValid);

    // Clear the input buffer
    while ((temp1 = getchar()) != '\n' && temp1 != EOF);
    return shipment;
}

// Validates the details of the shipment
int validateShipment(double weight, double volume, struct Point destination)
{
    double validVolume[3] = VALID_BOX_VOLUME;
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
    for (int i = 0; i < sizeof(validVolume) / sizeof(validVolume[0]); i++) {
        if (volume == validVolume[i]) {
            volumeIsValid = 1;
            break;
        }
    }
    if (!volumeIsValid) {
        printf("Invalid box size\n");
        isValid = 0;
    }

    // Destination validation
    if (!BuildingBlock(destination, map)) {
        printf("Invalid destination\n");
        isValid = 0;
    }

    return isValid;
}
