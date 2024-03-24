#include <stdio.h>
#include "truck.h"
#include "mapping.h"
#include "shipment.h"

struct Truck initializeTruck(struct Route route, char color)
{
    struct Truck truck = {0};
    struct Point location = {'A', 'A'};
    truck.currentVolume = 0.0;
    truck.currentWeight = 0.0;
    truck.route = route;
    truck.location = location;
    truck.color = color;

    return truck;
}

void findBestTruck(struct Truck trucks[], int numTrucks, struct Shipment shipment, const struct Map *map)
{
    int i = -1;
    int shortestDistance = -1;
    int truckIndex = -1;
    struct Route shortestRoute = {0};

    for (i = 0; i < numTrucks; i++)
    {
        if (canShip(trucks[i], shipment))
        {
            // int index = getClosestPoint(&trucks[i].route, shipment.destination);
            struct Route route = nearestPoint(map, trucks[i].route, shipment.destination);

            if (route.numPoints > 0 &&                                                                 // if there is a route that can reach the destination
                (route.numPoints < shortestDistance ||                                                 // if the route is shorter than the previous shortest
                 shortestDistance == -1 ||                                                             // or the previous shortest is -1(meaning there were no previous shortest route discovered)
                 (shortestDistance == route.numPoints && isMoreEmpty(trucks[i], trucks[truckIndex])))) // if the new route is as long as the previous one and the new truck is more empty
            {
                shortestRoute = route;
                truckIndex = i;
                shortestDistance = shortestRoute.numPoints;
            }
        }
    }

    if (truckIndex != -1)
    {
        loadShipment(&trucks[truckIndex], shipment);
        printf("Ship on ");
        if (trucks[truckIndex].color == 'B')
        {
            printf("BLUE LINE, ");
        }
        else if (trucks[truckIndex].color == 'Y')
        {
            printf("YELLOW LINE, ");
        }
        else if (trucks[truckIndex].color == 'G')
        {
            printf("GREEN LINE, ");
        }
        printDiversions(&shortestRoute);
    }
    else
    {
        printf("Ships tomorrow");
    }
    printf("\n");
}

int canShip(struct Truck truck, struct Shipment shipment)
{
    return MAX_WEIGHT - truck.currentWeight >= shipment.weight && MAX_VOLUME - truck.currentVolume >= shipment.volume;
}

int isMoreEmpty(struct Truck truck1, struct Truck truck2)
{
    return spacePercentage(truck1) > spacePercentage(truck2);
}

double spacePercentage(struct Truck truck)
{
    return ((((truck.currentVolume * 100) / MAX_VOLUME) + ((truck.currentWeight * 100) / MAX_WEIGHT)) / 2);
}

void printDiversions(struct Route *route)
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

void loadShipment(struct Truck *truck, const struct Shipment shipment)
{
    if (canShip(*truck, shipment))
    {
        truck->currentVolume += shipment.volume;
        truck->currentWeight += shipment.weight;
        truck->location = shipment.destination;
    }
}

