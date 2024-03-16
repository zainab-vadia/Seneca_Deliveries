#pragma once
#ifndef DELIVERY_H
#define DELIVERY_H

#include "mapping.h" 

// Define the maximum values for weight and volume for a truck
#define MAXIMUM_TRUCK_WEIGHT 1200
#define MAXIMUM_TRUCK_VOLUME 50

// Define the available box sizes
#define SMALL_BOX_SIZE_CBM 0.5f
#define MEDIUM_BOX_SIZE_CBM 1.0f
#define LARGE_BOX_SIZE_CBM 5.0f


// Structure for Truckload
struct Truckload {

    int truckId;
    int currentWeightKg;      // Current weight of truckload
    int currentVolumeCbm;      // Current volume of truckload
    double finalBoxSize;       //  size of box in cubic meters

};

// Structure for Delivery
struct Delivery {

    int weightKg;             // Weight of the shipment in kilograms
    double boxSize;         // choice of the size of the box in cubic meters
    struct Point dropOff;   // Destination of the shipment

};

#endif
#pragma once
