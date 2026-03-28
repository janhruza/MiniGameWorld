//
// Created by jan on 21/03/2026.
//

#ifndef MOTOGP_GAMESESSION_H
#define MOTOGP_GAMESESSION_H

#include "Common.h"
#include "DriverInfo.h"
#include "TeamInfo.h"
#include "TrackInfo.h"
#include "Scoreboard.h"

#pragma region Global Variables

#define SAVEGAME        "data.sav"

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
     * @brief Index of the player object in the global driver's array.
     * @details Global arrays keep the indexes, no need to store the object itself.
     */
    int PlayerIdx;

    /**
     * @brief Representing the current event index in the active cup. Must be in range [0, TRACK_COUNT - 1]
     * @details Values other than the defined range will be treated as no cup is in progress.
     */
    int CupIdx;

    /**
     * @brief Representing the in-progress cup standings.
     */
    Scoreboard Standings;

} GameSession;

/**
 * @brief Initializes a new game session.
 * @return Status code.
 * @details This method allocates the object's memory on heap, manual freeing is required. Can be freed using the GsFree method.
 */
GameSession* GsInit();

/**
 * Frees all resources used by the given game session.
 * @param session Pointer to the active game session.
 * @return Operation result.
 */
STATUS GsFree(GameSession *session);

/**
 * @brief Loads the saved game session.
 * @param session Pointer to the game session object.
 * @return Operation result.
 */
STATUS GsLoad(GameSession *session);

/**
 * @brief Saves the active game session.
 * @param session Pointer to the game session object.
 * @return Operation result.
 */
STATUS GsSave(const GameSession *session);

/**
 * @brief Displays the game data.
 * @return Operation result.
 */
STATUS GsDisplayData(void);

/**
 * @brief Determines whether a cup is in progress.
 * @param session Pointer to the active game session object.
 * @return TRUE if the cup is in progress, otherwise FALSE.
 */
BOOL GsCupInProgress(const GameSession *session);

/**
 * @brief Displays the current cup scoreboard.
 * @param session Pointer to the game session object.
 * @return Operation result.
 */
STATUS GsDisplayScoreboard(const GameSession *session);

/**
 * @brief Starts the next race in cup.
 * @param session Pointer to the game session object.
 * @return Operation result.
 */
STATUS GsRace(GameSession *session);

/**
 * @brief Displays the final leaderboard.
 * @param session Pointer to the game session object.
 * @return Operation result.
 */
STATUS GsFinalResults(const GameSession *session);

/**
 * @brief Gets the driver points.
 * @param session Pointer to the active game session object.
 * @param driverIdx Index of the driver.
 * @return Total driver points or -1, if an error has occurred.
 */
int GsGetPoints(const GameSession *session, const int driverIdx);

/**
 * @brief Prints the given session as a Markdown .md file.
 * @param session Pointer to the game session object.
 * @return Operation result.
 */
int GsPrintAsMarkdown(const GameSession *session);

#endif //MOTOGP_GAMESESSION_H