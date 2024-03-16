#include "Finder.h"
#include <stdlib.h>
#include <limits.h>

void findValidTruckPaths(struct Shipment shipment, struct Truck truck, const struct Map* map, struct Route routes[MAX_ROUTE], int* size)
{
    int count = 0;
    for (int i = 0; i < truck.allocated_shipments; i++)
    {
        if (truck.destination_counts[i] == hasDestination(&routes[i], shipment))
        {
            if (!isBuildingIntersected(routes[i], map))
            {
                routes[count++] = routes[i];
            }
        }
    }
    *size = count;
}

int hasDestination(const struct Route* route, struct Shipment shipment)
{
    for (int i = 0; i < route->numPoints; i++)
    {
        if (route->points[i].row == shipment.destination.row && route->points[i].col == shipment.destination.col)
        {
            return 1;
        }
    }
    return 0;
}

void printRoute(struct Route route, struct Shipment shipment)
{
    printf("Route to Shipment (Destination: (%d, %d)):\n", shipment.destination.row, shipment.destination.col);
    for (int i = 0; i < route.numPoints; i++) {
        printf("(%d, %d) ", route.points[i].row, route.points[i].col);
    }
    printf("\n");
}

int isBuildingIntersected(const struct Route route, const struct Map* map)
{
    for (int i = 0; i < route.numPoints; i++)
    {
        if (map->squares[route.points[i].row][route.points[i].col] == 2)
        {
            return 1;
        }
    }
    return 0;
}

int getBestRoute(struct Route* routes[MAX_ROUTE], struct Shipment shipment, int size)
{
    int shortestDistance = INT_MAX;
    int shortestIndex = -1;

    for (int i = 0; i < size; i++)
    {
        int routeDistance = distance(&routes[i]->points[0], &shipment.destination);
        if (routeDistance < shortestDistance)
        {
            shortestDistance = routeDistance;
            shortestIndex = i;
        }
    }

    return shortestIndex;
}

int isTruckOverloaded(struct Truck truck, struct Shipment ship)
{
    int result = 0;

    if (truck.weight_capacity <= 1000)
    {
        truck.weight_capacity += ship.weight;

        if (truck.weight_capacity <= 1000)
        {
            result = 1;
        }
    }

    return result;
}

int isBoxSizeExceeded(struct Truck truck, float boxSize)
{
    int result = 0;

    if (truck.volume_capacity <= 36)
    {
        truck.volume_capacity += boxSize;

        if (truck.volume_capacity <= 36)
        {
            result = 1;
        }
    }

    return result;
}

int validCargo(float boxsize)
{
    const double minSize = 0.25;
    const double halfSize = 0.5;
    const double maxSize = 1.0;
    int result = 0;

    if (boxsize == minSize || boxsize == halfSize || boxsize == maxSize)
    {
        result = 1;
    }
    else
    {
        printf("Box size is not valid.\n");
    }

    return result;
}

void postCommitHook()
{
    printf("This edit is to test post commit hook");
}

void preCommitHook()
{
    printf("another test");
}
