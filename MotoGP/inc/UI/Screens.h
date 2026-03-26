//
// Created by jan on 22/03/2026.
//

#ifndef MOTOGP_SCREENS_H
#define MOTOGP_SCREENS_H

#include "../GameSession.h"

int ScrNotImplemented(void);

int ScrError(const char *msg);

/**
 * Pauses the execution until any key is pressed.
 * @return Pressed key identifier.
 */
int ScrPause(void);

/**
 * @brief Representing the welcome screen.
 * @param session Pointer to the active game session.
 * @return Operation result.
 */
int ScrWelcomeScreen(GameSession *session);

/**
 * @brief Representing the main application menu.
 * @param session Pointer to the active game session.
 * @return Operation result.
 */
int ScrMainMenu(GameSession *session);

/**
 * @brief Representing the cup menu.
 * @param session Pointer to the active game session.
 * @return Operation result.
 */
int ScrContinueCup(GameSession *session);

#endif //MOTOGP_SCREENS_H