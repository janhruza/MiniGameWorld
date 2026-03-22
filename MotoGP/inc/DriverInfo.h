//
// Created by jan on 21/03/2026.
//

#ifndef MOTOGP_DRIVERINFO_H
#define MOTOGP_DRIVERINFO_H

#include "Common.h"

typedef struct {
    /**
     * @brief Driver's number.
     */
    int Number;

    /**
     * @brief Representing the driver's nationality.
     */
    Country Country;

    /**
     * @brief Index of the driver's team in the teams array.
     */
    int IdxTeam;

    /**
     * @brief Driver's name.
     */
    char Name[TEXT_LENGTH];
} DriverInfo;

/**
 * @brief Initializes the driver object.
 * @param driver Pointer to the driver's object.
 * @return Operation result.
 */
STATUS DriverInit(DriverInfo *driver);

#endif //MOTOGP_DRIVERINFO_H