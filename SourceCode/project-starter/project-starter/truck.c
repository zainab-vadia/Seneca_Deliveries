#include <stdio.h>
#include "truck.h"
#include "mapping.h"
#include "shipment.h"

struct Truck configureTruck(struct Route route, char color)
{
    struct Truck truck = { 0 };
    struct Point location = { 'A', 'A' };
    truck.presentVolumeInM = 0.0;
    truck.presentWeightInKg = 0.0;
    truck.route = route;
    truck.location = location;
    truck.pathColor = color;

    return truck;
}

void appropriateTruck(struct Truck trucks[], int numTrucks, struct Shipment shipment, const struct Map* map)
{
    int i = -1;
    int leastDistance = -1;
    int truckIndex = -1;
    struct Route BestRoute = { 0 };

    for (i = 0; i < numTrucks; i++)
    {
        if (enoughSpace(trucks[i], shipment))
        {

            struct Route route = findClosestPoint(map, trucks[i].route, shipment.destination);

            if (route.numPoints > 0 &&
                (route.numPoints < leastDistance ||
                    leastDistance == -1 ||
                    (leastDistance == route.numPoints && moreSpace(trucks[i], trucks[truckIndex]))))
            {
                BestRoute = route;
                truckIndex = i;
                leastDistance = BestRoute.numPoints;
            }
        }
    }

    if (truckIndex != -1)
    {
        loadShipmentDiversions(&trucks[truckIndex], shipment);
        printf("Ship on ");
        if (trucks[truckIndex].pathColor == 'B')
        {
            printf("BLUE LINE, ");
        }
        else if (trucks[truckIndex].pathColor == 'Y')
        {
            printf("YELLOW LINE, ");
        }
        else if (trucks[truckIndex].pathColor == 'G')
        {
            printf("GREEN LINE, ");
        }
        truckDiversions(&BestRoute);
    }
    else
    {
        printf("Ships tomorrow");
    }
    printf("\n");
}


int enoughSpace(struct Truck truck, struct Shipment shipment) {
    double availableWeight = MAX_WEIGHT - truck.presentWeightInKg;
    double availableVolume = MAX_VOLUME - truck.presentVolumeInM;

    int isWeightSufficient = availableWeight >= shipment.weight;
    int isVolumeSufficient = availableVolume >= shipment.volume;

    return isWeightSufficient && isVolumeSufficient;
}

int moreSpace(struct Truck truck1, struct Truck truck2)
{
    return availablePercentageLeft(truck1) > availablePercentageLeft(truck2);
}

double availablePercentageLeft(struct Truck truck)
{
    return ((((truck.presentVolumeInM * 100) / MAX_VOLUME) + ((truck.presentWeightInKg * 100) / MAX_WEIGHT)) / 2);
}

void truckDiversions(struct Route* route)
{
    if (route->numPoints == 2)
    {
        printf("no diversion");
    }
    else if (route->numPoints > 2)
    {
        int i = 0;
        printf("divert: ");
        for (i = 0; i < route->numPoints - 1; i++)
        {
            printf("%d%c,", route->points[i].row + 1, route->points[i].col + 'A');
        }
        printf("%d%c", route->points[i].row + 1, route->points[i].col + 'A');
    }
}

void loadShipmentDiversions(struct Truck* truck, const struct Shipment shipment)
{
    if (enoughSpace(*truck, shipment))
    {
        truck->presentVolumeInM += shipment.volume;
        truck->presentWeightInKg += shipment.weight;
        truck->location = shipment.destination;
    }
}
