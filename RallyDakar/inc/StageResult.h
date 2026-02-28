//
// Created by jan on 28/02/2026.
//

#ifndef RALLYDAKAR_STAGERESULT_H
#define RALLYDAKAR_STAGERESULT_H

#include "Common.h"

/**
 * Representing the stage result struct.
 */
typedef struct {
    /**
     * @brief Representing the team ID.
     */
    unsigned int TeamId;

    /**
     * Representing the driven time of the stage.
     */
    float TimeStage;

    /**
     * Representing the penalty time (if any).
     */
    float TimePenalty;

    /**
     * Representing the total number of mechanical issues.
     */
    unsigned int Issues;
} StageResult;

#endif //RALLYDAKAR_STAGERESULT_H