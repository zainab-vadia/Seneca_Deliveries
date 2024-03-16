#ifndef FINDER_H
#define FINDER_H
#include <stdio.h>
#include "mapping.h"


struct Shipment
{
    float weight;
    float volume;
    struct Point destination;
};
// Milestone 3_ Function Specification

void findValidPaths(struct Shipment shipment, struct Truck truck, const struct Map* map, struct Route routes[MAX_ROUTE], int* size);
/**
 * Function: findValidTruckPaths
 * - Populates the "routes" array with routes that reach the given shipment destination.
 * @param shipment - Shipment struct containing the destination coordinates (row and column) of the shipment.
 * @param truck - Truck struct containing the route the truck travels on the map.
 * @param map - Map struct containing all the points (squares) in the map.
 * @param routes - Array of pointers to Route structs to store the valid routes.
 * @param size - Pointer to an integer to store the number of valid routes.
 * @returns - void, populates the "routes" array and updates the "size" variable.
 */


int findBestRoute(struct Route* routes[MAX_ROUTE], struct Shipment shipment, int size);
/*
* Function:getBestRoute
finds the index of the route with the shortest distance among the valid routes in the routes array that reach the given shipment destination.
routes (struct Route *[MAX_ROUTE]): An array of pointers to Route structures representing different routes
shipment (struct Shipment): A Shipment struct containing the destination coordinates (row and column) of the shipment.
size (int): An integer representing the number of valid routes in the routes array.
returns an integer value, which is the index of the route in the routes array with the shortest distance. If no valid route is found, the function returns -1.
*/


int hasDestination(const struct Route* route, struct Shipment shipment);
/*
* Function:hasDestination
checks if a given route reaches the specified destination of a shipment.*/

void printRoute(struct Route route, struct Shipment shipment);
/*
* Function:printRoute
 * - Prints the points (coordinates) of a route to the console.
 * @param route - Route struct containing the points (coordinates) of the route.
 * @param shipment - Shipment struct containing the destination coordinates (row and column) of the shipment.
 * @returns - void, does not return a value, only prints to the console.
 */

int isBuildingIntersected(const struct Route route, const struct Map* map);
/*
* Function:isBuildingIntersected
checks if a given route intersects with any buildings on the map.
route (const struct Route): The route to check for intersections with buildings.
map (const struct Map *): A pointer to the Map structure containing the buildings on the map.
returns an integer value: 1 if the route intersects with a building, and 0 if it does not
*/


#endif // FINDER_H#pragma once
