#pragma once
#ifndef TRUCK_H
#define TRUCK_H


#include "mapping.h"

#define MAX_VOLUME 50
#define MAX_WEIGHT 1200
#define MIN_WEIGHT 0
#define VALID_BOX_VOLUME {0.5, 1, 5} 

/**
* A package represents a delivery item with weight, volume, and destination.
*/
struct Shipment
{
    double weight;  // Weight of the package in kilograms
    double volume;  // Volume of the package in cubic meters
    struct Point destination;  // Destination of the package
};


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
* input a valid shipment from the terminal
* @returns - an initialized package if valid, otherwise an empty shipment
*/
struct Shipment inputShipment();

/**
* validate the package and provide an error message
* @param weight - the weight of the package
* @param volume - the volume of the package
* @param destination - the destination of the package
* @returns - true if the shipment is valid, false otherwise
*/
int isValidPackage(double weight, double volume, struct Point destination);



#endif