//
// Created by jan on 28/02/2026.
//

#include <memory.h>
#include <stdio.h>

#include "../inc/TeamInfo.h"
#include "../inc/Common.h"

bool TeamInit(TeamInfo *team, char *teamName, char *driverName, char *coDriverName) {
    if (team == NULL) {
        return false;
    }

    // set the initial values
    snprintf(team->TeamName, SHORT_TEXT_LENGTH, "%s", teamName);

    for (int i = 0; i < MAX_TEAM_VEHICLES; i++) {
        VehicleInit(&team->Vehicles[i]);
    }

    // initialize the times
    team->TimePenalty = 0;
    team->TimeTotal = 0;
    return true;
}