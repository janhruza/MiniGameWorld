//
// Created by jan on 28/02/2026.
//

#ifndef RALLYDAKAR_TEAMINFO_H
#define RALLYDAKAR_TEAMINFO_H

#pragma once
#include "Common.h"
#include "VehicleInfo.h"

/**
 * @brief Representing the team information.
 */
typedef struct {
    /**
     * @brief Representing the team name.
     */
    char TeamName[SHORT_TEXT_LENGTH];

    /**
     * @brief Representing the total racing time (from all stages, aggregated).
     */
    float TimeTotal;

    /**
     * @brief Representing the total penalty time.
     */
    float TimePenalty;

    /**
     * Representing the list of team vehicles.
     */
    VehicleInfo Vehicles[MAX_TEAM_VEHICLES];
} TeamInfo;

/**
 *@brief Initializes the team object.
 * @param team Pointer to a team object to be initialized.
 * @param teamName Name of the new team.
 */
bool TeamInit(TeamInfo *team, char *teamName);

#endif //RALLYDAKAR_TEAMINFO_H