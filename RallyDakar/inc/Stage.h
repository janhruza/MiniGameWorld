//
// Created by jan on 28/02/2026.
//

#ifndef RALLYDAKAR_STAGE_H
#define RALLYDAKAR_STAGE_H

#include "Common.h"

/**
 * @brief Representing the stage information.
 */
typedef struct {
    /**
     * @brief Representing the stage ID, usually the stage number.
     */
    unsigned int Id;

    /**
     * @brief Representing the stage's location.
     */
    char Location[NORMAL_TEXT_LENGTH];

    /**
     * Representing the stage's distance.
     */
    float Distance;

    /**
     * Representing the overall difficulty.
     */
    float Difficulty;

    /**
     * Representing the stage terrain types (can be mixed).
     */
    unsigned int Terrain;
} Stage;

/**
 * @brief Initializes the given stage object.
 * @param stage Pointer to the stage that should be initialized.
 * @return Operation result.
 */
bool StageInit(Stage *stage);

#endif //RALLYDAKAR_STAGE_H