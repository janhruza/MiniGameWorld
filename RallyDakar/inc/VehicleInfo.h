//
// Created by jan on 28/02/2026.
//

#ifndef RALLYDAKAR_VEHICLEINFO_H
#define RALLYDAKAR_VEHICLEINFO_H

#pragma once
#include "VehicleHealth.h"
#include "Common.h"

/**
 * @brief Representing a vehicle struct.
 */
typedef struct {

    /**
     * Representing the vehicle crew.
     */
    char *Drivers[MAX_CREW_SIZE];

    /**
     * Representing the total (aggregated) time.
     */
    float Time;

    /**
     * Representing the total (aggregated) penalty.
     */
    float Penalty;

    /**
     * Representing the vehicle health.
     */
    VehicleHealth Health;

} VehicleInfo;

/**
 * Initializes the given vehicle object.
 * @param vehicleInfo Target vehicle object.
 * @return Operation result.
 */
bool VehicleInit(VehicleInfo *vehicleInfo);

/**
 * @brief Initializes the vehicle and sets the driver and co-driver information.
 * @param vehicleInfo Target vehicle object.
 * @param drivers List of drivers, must be only up to MAX_CREW_SIZE.
 * @return Operation result.
 * @details Initializes the vehicleInfo object using the VehicleInit function and then assigns the drivers' details.
 */
bool VehicleCreate(VehicleInfo *vehicleInfo, char *drivers[]);

#endif //RALLYDAKAR_VEHICLEINFO_H