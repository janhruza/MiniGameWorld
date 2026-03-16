//
// Common.h
// Created by jan on 28/02/2026.
// Contains various structs and definitions.
//

#ifndef RALLYDAKAR_COMMON_H
#define RALLYDAKAR_COMMON_H

#pragma once
#include <stdbool.h>
#include <string.h>

#define AUTHOR              "@jendahruza"
#define PRODUCT             "RALLY DAKAR MANAGER"
#define PRODUCT_NAME        "Rally Dakar Manager"

#define PLAYER_TEAM_INDEX   0

#define MAX_STAGES          14
#define MAX_TEAMS           30

#define SHORT_TEXT_LENGTH   33
#define NORMAL_TEXT_LENGTH  65
#define LONG_TEXT_LENGTH    129

#define MAX_TEAM_VEHICLES   4
#define MAX_CREW_SIZE       5

#define HEALTH_MAX          1.0f

/**
 * @brief Representing the game exit code enum.
 */
typedef enum {
    STATUS_OK = 0,              // Success status code.
    STATUS_ERROR,               // Error status code.
    STATUS_GAME_UNINITIALIZED,  // Game unitialized status code.
} StatusCode;

int GetRawChar();

/**
 * @brief Representing the global storage place for the last app message.
 */
static char gLastMessage[NORMAL_TEXT_LENGTH];

/**
 * @brief Draws the application banner.
 */
void CoDrawBanner(void);

/**
* @brief Displays the extended application banner and extra information.
*/
void CoDrawBannerEx(void);

/**
 * @brief Shows the about and credits screen.
 */
void CoShowCredits(void);

/**
* Sets the terminal emulator window title.
* @param text New window title.
* @details This method assumes the ANSI processing-able terminal.
*/
void SetConsoleTitle(const char* text);

#endif //RALLYDAKAR_COMMON_H