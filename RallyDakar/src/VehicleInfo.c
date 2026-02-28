//
// Created by jan on 28/02/2026.
//

#include <stdlib.h>
#include <memory.h>
#include "../inc/VehicleInfo.h"

bool VehicleInit(VehicleInfo *vehicleInfo) {
    if (vehicleInfo == NULL) {
        return false;
    }

    // clear the driver names list
    vehicleInfo->Drivers[0] = "\0";
    vehicleInfo->Drivers[1] = "\0";
    vehicleInfo->Drivers[2] = "\0";
    vehicleInfo->Drivers[3] = "\0";
    vehicleInfo->Drivers[4] = "\0";

    // initialize the vehicle health
    vehicleInfo->Health = (VehicleHealth)
    {
        .Engine = HEALTH_MAX,
        .Suspension = HEALTH_MAX,
        .Electronics = HEALTH_MAX,
        .Tires = HEALTH_MAX,
    };

    // initializes the time and penalty fields
    vehicleInfo->Time = 0;
    vehicleInfo->Penalty = 0;
    return true;
}