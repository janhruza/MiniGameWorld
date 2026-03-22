//
// Created by jan on 22/03/2026.
//

#ifndef MOTOGP_SCOREBOARD_H
#define MOTOGP_SCOREBOARD_H
#include "Common.h"

/**
 * @brief Representing a single race result struct.
 */
typedef struct tagRaceResult {
    /**
     * @brief Representing the ID of the entity (driver, team or manufacturer).
     */
    int EntityId;

    /**
     * @brief Representing the points gained in the event (single race).
     * @details Can be used as the overall score in the final standings.
     */
    int Pts;

} RaceResult;

typedef struct tagScoreboard {
    /**
     * @brief Representing the Riders' Championship standings.
     */
    RaceResult Riders[TRACK_COUNT][DRIVER_COUNT];

    /**
     * @brief Representing the Teams' Championship standings.
     */
    RaceResult Teams[TRACK_COUNT][TEAM_COUNT];

    /**
     * @brief Representing the Constructors' Championship standings.
     */
    RaceResult Constructors[TRACK_COUNT][MANUFACTURERS_COUNT];
} Scoreboard;

#endif //MOTOGP_SCOREBOARD_H