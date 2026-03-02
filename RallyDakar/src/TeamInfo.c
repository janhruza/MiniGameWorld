//
// Created by jan on 28/02/2026.
//

#include <memory.h>
#include <stdio.h>

#include "../inc/TeamInfo.h"
#include "../inc/Common.h"

bool TeamInit(TeamInfo *team, char *teamName) {
    // check if the team is a valid pointer
    if (team == NULL) {
        return false;
    }

    // set the default team ID -> EOF
    team->Id = EOF;

    // set the initial values
    snprintf(team->TeamName, SHORT_TEXT_LENGTH, "%s", teamName);

    // initialize all vehicle objects
    for (int i = 0; i < MAX_TEAM_VEHICLES; i++) {
        VehicleInit(&team->Vehicles[i]);
    }

    // initialize the times
    team->TimePenalty = 0;
    team->TimeTotal = 0;
    return true;
}

bool TeamIsValid(const TeamInfo *team) {
    if (team == NULL) return false;

    if (team->Id <= EOF) {
        return false;
    }

    return true;
}