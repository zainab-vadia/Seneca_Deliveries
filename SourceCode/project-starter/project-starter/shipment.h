#pragma once
#ifndef SHIPMENT_H
#define SHIPMENT_H

#include "mapping.h"
#include "truck.h"

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