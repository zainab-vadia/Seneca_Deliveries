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

