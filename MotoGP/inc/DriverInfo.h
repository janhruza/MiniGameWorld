//
// Created by jan on 21/03/2026.
//

#ifndef MOTOGP_DRIVERINFO_H
#define MOTOGP_DRIVERINFO_H

#include "Common.h"

typedef enum tagCountry {
    OTHER,          FRANCE,     TURKEY,
    ITALY,          BRAZIL,     SPAIN,
    SOUTH_AFRICA,   AUSTRALIA,  JAPAN
} Country;

typedef struct {
    /**
     * @brief Driver's number.
     */
    int Number;

    Country Country;

    /**
     * @brief Index of the driver's bike in the bikes array.
     */
    int IdxBike;

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