//
// Created by jan on 02/03/2026.
//

#ifndef RALLYDAKAR_APPMENUS_H
#define RALLYDAKAR_APPMENUS_H

#include "../GameSession.h"

/**
 * @brief Representing the valid menu action IDs.
 */
typedef enum {
    ID_EXIT = 0,        // Universal exit or cancel action code.
    ID_ERROR,           // Generic error code.

    // GENERAL
    ID_DEBUG,           // Debug option used to bypass some functionality for testing purposes (only one ID_DEBUG is assumed while testing).
    ID_NEW_GAME,        // Start a new game.
    ID_LOAD_GAME,       // Load a saved game.
    ID_SAVE_GAME,       // Save game.
    ID_CREDITS,         // Display credits.

    // MAIN MENU SCREEN
    ID_NEW_CUP,         // Start a new cup (season).
    ID_CONTINUE_CUP,    // Continue the active cup (if any).
    ID_ADJUST_VEHICLES, // Adjust player's team vehicles.


} MenuActions;

/**
 * @brief Representing the initial menu screen.
 * @return ID of the selected menu item.
 * @details Possible values: ID_NEW_GAME, ID_LOAD_GAME, ID_CREDITS, ID_EXIT.
 */
int MenuWelcomeScreen(void);

/**
* @brief Representing the main menu screen after a game is loaded/created.
* @param session Active game session.
* @return ID of the selected option.
* @details Possible return values: ID_NEW_CUP, ID_CONTINUE_CUP, ID_ADJUST_VEHICLES, ID_EXIT
*/
int MenuMainScreen(GameSession *session);

#endif //RALLYDAKAR_APPMENUS_H