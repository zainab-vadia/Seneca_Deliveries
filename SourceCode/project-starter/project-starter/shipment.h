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



#endif