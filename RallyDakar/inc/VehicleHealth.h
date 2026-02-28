//
// Created by jan on 28/02/2026.
//

#ifndef RALLYDAKAR_VEHICLEHEALTH_H
#define RALLYDAKAR_VEHICLEHEALTH_H

#include "Common.h"

/**
 * @brief Representing the vehicle health struct.
 */
typedef struct {
    /**
     * @brief Representing the health status of the vehicle's engine.
     */
    float Engine;

    /**
     * @brief Representing the health status of the vehicle's suspension.
     */
    float Suspension;

    /**
     * @brief Representing the health status of the vehicle's electronics.
     */
    float Electronics;

    /**
     * @brief Representing the health status of the vehicle's tires.
     */
    float Tires;
} VehicleHealth;

#endif //RALLYDAKAR_VEHICLEHEALTH_H