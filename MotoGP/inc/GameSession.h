//
// Created by jan on 21/03/2026.
//

#ifndef MOTOGP_GAMESESSION_H
#define MOTOGP_GAMESESSION_H

#include "Common.h"
#include "DriverInfo.h"
#include "TeamInfo.h"

#pragma region Global Variables

/**
 * @brief Representing the driver objects.
 */
extern DriverInfo gDrivers[DRIVER_COUNT];
extern TeamInfo gTeams[DRIVER_COUNT];

#pragma endregion

typedef struct tagGameSession {
    /**
     * @brief Pointer to the player's associated driver object.
     */
    DriverInfo *Player;
} GameSession;

/**
 * @brief Initializes a new game session.
 * @param session Pointer to the new game session object.
 * @return Status code.
 */
STATUS GsInit(GameSession *session);

/**
 * Frees all resources used by the given game session.
 * @param session Pointer to the active game session.
 * @return Operation result.
 */
STATUS GsFree(GameSession *session);

#endif //MOTOGP_GAMESESSION_H