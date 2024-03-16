#include "Finder.h"
#include <stdlib.h>
#include <limits.h>

void findValidPaths(struct Shipment shipment, struct Truck truck, const struct Map *map, struct Route routes[MAX_ROUTE], int *size)
{
    int validCount = 0;
    for (int i = 0; i < truck.allocated_shipments; i++)
    {

        if (truck.destination_counts[i] == hasDestination(&routes[i], shipment))
        {
            if (!isBuildingIntersected(routes[i], map))
            {
                routes[validCount++] = routes[i];
            }
        }
    }              
    *size = validCount; 
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

int findBestRoute(struct Route *routes[MAX_ROUTE], struct Shipment shipment, int size)
{
    int shortestDistance = INT_MAX;
    int shortestIndex = -1;

    for (int i = 0; i < size; i++)
    {
        int destinationDistance = distance(&routes[i]->points[0], &shipment.destination);
        if (destinationDistance < shortestDistance)
        {
            shortestDistance = destinationDistance;
            shortestIndex = i;
        }
    }

    return shortestIndex;
}
