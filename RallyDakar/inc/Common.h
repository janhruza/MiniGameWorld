//
// Common.h
// Created by jan on 28/02/2026.
// Contains various structs and definitions.
//

#ifndef RALLYDAKAR_COMMON_H
#define RALLYDAKAR_COMMON_H

#pragma once
#include <stdbool.h>

#define TRUE                1
#define FALSE               0

#define MAX_STAGES          14
#define MAX_TEAMS           30

#define SHORT_TEXT_LENGTH   33
#define NORMAL_TEXT_LENGTH  65
#define LONG_TEXT_LENGTH    129

#define MAX_TEAM_VEHICLES   4
#define MAX_CREW_SIZE       5

#define HEALTH_MAX          100.0f

/**
 * @brief Draws the application banner.
 */
void CoDrawBanner(void);

#endif //RALLYDAKAR_COMMON_H