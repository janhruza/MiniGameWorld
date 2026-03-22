//
// Created by jan on 22/03/2026.
//

#ifndef MOTOGP_TEAMINFO_H
#define MOTOGP_TEAMINFO_H

#include "Common.h"

/**
 * @brief Representing the racing teams identifiers.
 */
typedef enum tagTeamId : int {
    TEAM_APRILIA,
    TEAM_GRESINI,
    TEAM_DUCATI_LENOVO,
    TEAM_HONDA_HRC,
    TEAM_LCR_HONDA,
    TEAM_MONSTER_ENERGY,
    TEAM_PERTAMINA_ENDURO,
    TEAM_PRIMA_PRAMAC,
    TEAM_RED_BULL_FACTORY,
    TEAM_RED_BULL_TECH3,
    TEAM_TRACKHOUSE
} TeamId;

/**
 * @brief Representing the bike manufacturers.
 */
typedef enum tagBikeManufacturer : int {
    BIKE_OTHER,     BIKE_DUCATI,    BIKE_APRILIA,
    BIKE_HONDA,     BIKE_YAMAHA,    BIKE_KTM,
} Manufacturer;

/**
 * @brief Representing the team information.
 */
typedef struct tagTeamInfo {
    int TeamId;
    Manufacturer Bike;
    char Name[TEXT_LENGTH];
} TeamInfo;

#endif //MOTOGP_TEAMINFO_H