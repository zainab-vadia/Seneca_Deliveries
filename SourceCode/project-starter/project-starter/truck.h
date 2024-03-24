#pragma once
#ifndef TRUCK_H
#define TRUCK_H

#include "shipment.h"
#include "mapping.h"

#define MAX_VOLUME 50
#define MAX_WEIGHT 1200
#define MIN_WEIGHT 1


/**
* A truck represents a delivery vehicle with weight and volume capacity.
*/
struct Truck
{
    double currentWeight;  // Current weight in the truck
    double currentVolume;  // Current volume in the truck
    struct Route route;  // Route of the truck
    struct Point location; // loaction of the truck
    char color; 
    // the location must lie on the route
};


/**
* Initialize a truck with the specified weight, volume, and route.
* @param route - the route of the truck
* @returns - an initialized truck
*/
struct Truck initializeTruck(struct Route route, char color);

/**
* Find the best truck to deliver a package based on available space ,volume and distance. 
* @param trucks - array of trucks available for delivery
* @param numTrucks - the number of trucks in the array
* @param shipment - the package to be delivered
* @param map - the map to be referenced
* @returns - the index of the best truck to deliver the package, or -1 if no suitable truck is found
*/
void findBestTruck(struct Truck trucks[], int numTrucks, struct Shipment shipment, const struct Map* map);

/**
* checks whether the truck has enough space for the Shipment
* @param truck - truck that is being checked
* @param shipment - the package to be delivered
* @returns - true if the package can be added to a truck, false otherwise
*/
int canShip(struct Truck truck, struct Shipment shipment);

/**
* checks which truck has more space
* @param truck1 - truck to be comapred
* @param truck2 - truck to be compared 
* @returns - true if truck 1 has more space false otherwise
*/
int isMoreEmpty(struct Truck truck1, struct Truck truck2);

/**
* evaluate how much space is available in percentage 
* @param truck - truck to be evaluated
* @returns - the percentage value of the space
*/
double spacePercentage(struct Truck truck);

/**
* print the diversion seprated by commas
* @param route - route to be printed
*/
void printDiversions(struct Route* route);

/**
* print the diversion seprated by commas
* @param truck - truck, to which the shipment should be added
* @param shipment - shipment to be added
*/
void loadShipment(struct Truck *truck, const struct Shipment shipment);

#endif