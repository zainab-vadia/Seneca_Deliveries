#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include "shipment.h"
#include "mapping.h"
#include "truck.h"

struct Shipment inputShipment()
{
    struct Shipment shipment = { 0,0 ,{0,0} };
    int temp1 = 0, valid, check = 0;
    char temp2 = 0; 

    do {
        printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
        valid = scanf("%lf %lf %d%c", &shipment.weight, &shipment.volume, &temp1, &temp2);
        if(valid == 4)
        {
            shipment.destination.row = temp1 - 1; 
            shipment.destination.col = toupper(temp2)-'A';
            check = isValidPackage(shipment.weight, shipment.volume, shipment.destination); 
        }
        else
        {
            check = 1;
        }
    } while (!check);

    while ((temp1 = getchar()) != '\n' && temp1 != EOF);
    return shipment;
}

int isValidPackage(double weight, double volume,struct Point destination)
{
    double validVolume[3] = VALID_BOX_VOLUME;
    int flag = 1;
    struct Map map = populateMap(); 

    if (weight > MAX_WEIGHT || weight <= MIN_WEIGHT)
    {
        printf("Invalid weight (must be %.lf-%.lf Kg.)\n", (double)(MIN_WEIGHT), (double)(MAX_WEIGHT));
        flag = 0;
    }
    if (!(volume == validVolume[0] || volume == validVolume[1] || volume == validVolume[2]))
    {
        printf("Invalid size\n");
        flag = 0;
    }
    if (!isBuilding(destination, map))
    {
        printf("Invalid destination\n");
        flag = 0;
    }
    return flag;
}
