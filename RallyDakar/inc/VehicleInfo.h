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

#endif //RALLYDAKAR_VEHICLEINFO_H