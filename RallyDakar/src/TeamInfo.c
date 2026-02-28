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

    // clear the team object
    memset(team, 0, sizeof(TeamInfo));

    // set the initial values
    snprintf(team->TeamName, SHORT_TEXT_LENGTH, "%s", teamName);
    snprintf(team->DriverName, SHORT_TEXT_LENGTH, "%s", driverName);
    snprintf(team->CoDriverName, SHORT_TEXT_LENGTH, "%s", coDriverName);

    // initialize the times
    team->TimePenalty = 0;
    team->TimeTotal = 0;
    return true;
}