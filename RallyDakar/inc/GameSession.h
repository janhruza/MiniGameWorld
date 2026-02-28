//
// Created by jan on 28/02/2026.
//

#ifndef RALLYDAKAR_GAMESESSION_H
#define RALLYDAKAR_GAMESESSION_H

#include "Common.h"
#include "TeamInfo.h"
#include "Stage.h"

/**
 * @brief Representing the game session struct.
 */
typedef struct {
    /**
     * @brief Representing all cup stages.
     */
    Stage Stages[MAX_STAGES];

    /**
     * @brief Representing the current stage index in range from 0 to MAX_STAGES - 1.
     */
    int StageIndex;

    /**
     * @brief Representing all active teams.
     */
    TeamInfo Teams[MAX_TEAMS];
} GameSession;

/**
 * @brief Saves the given session into the output file.
 * @param session Pointer to the session object.
 * @param fileName Target save file path.
 * @return Operation result.
 */
bool GsSave(const GameSession *session, const char* fileName);

/**
 * @brief Loads a saved session from the input file.
 * @param session Pointer to the session object.
 * @param fileName Target input file path.
 * @return Operation result.
 */
bool GsLoad(GameSession *session, const char* fileName);

#endif //RALLYDAKAR_GAMESESSION_H