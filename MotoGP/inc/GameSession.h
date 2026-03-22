//
// Created by jan on 21/03/2026.
//

#ifndef MOTOGP_GAMESESSION_H
#define MOTOGP_GAMESESSION_H

#include "Common.h"
#include "DriverInfo.h"
#include "TeamInfo.h"
#include "TrackInfo.h"

#pragma region Global Variables

/**
 * @brief Representing all driver objects.
 */
extern DriverInfo gDrivers[DRIVER_COUNT];

/**
 * @brief Representing all team objects.
 */
extern TeamInfo gTeams[TEAM_COUNT];

/**
 * @brief Representing all track objects.
 */
extern TrackInfo gTracks[TRACK_COUNT];

#pragma endregion

/**
 * @brief Representing a game session object.
 */
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