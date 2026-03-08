//
// Created by jan on 28/02/2026.
//

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "../inc/VehicleInfo.h"

bool VehicleInit(VehicleInfo *vehicleInfo) {
    if (vehicleInfo == NULL) {
        return false;
    }

    // clear the driver names list
    snprintf(vehicleInfo->Drivers[0], SHORT_TEXT_LENGTH, "\0");
    snprintf(vehicleInfo->Drivers[1], SHORT_TEXT_LENGTH, "\0");
    snprintf(vehicleInfo->Drivers[2], SHORT_TEXT_LENGTH, "\0");
    snprintf(vehicleInfo->Drivers[3], SHORT_TEXT_LENGTH, "\0");
    snprintf(vehicleInfo->Drivers[4], SHORT_TEXT_LENGTH, "\0");

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

bool VehicleCreate(VehicleInfo *vehicleInfo, char* drivers[]) {
    // initialize the object first
    if (VehicleInit(vehicleInfo) == false) {
        return false;
    }

    // assign the drivers objects
    for (int i = 0; i < MAX_TEAM_VEHICLES; i++) {
        snprintf(vehicleInfo->Drivers[i], SHORT_TEXT_LENGTH, drivers[i]);
    }

    return true;
}