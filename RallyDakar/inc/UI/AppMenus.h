//
// Created by jan on 02/03/2026.
//

#ifndef RALLYDAKAR_APPMENUS_H
#define RALLYDAKAR_APPMENUS_H

/**
 * @brief Representing the valid menu action IDs.
 */
typedef enum : int {
    ID_EXIT = 0,        // Universal exit or cancel action code.

    ID_DEBUG,           // Debug option used to bypass some functionality for testing purposes (only one ID_DEBUG is assumed while testing).
    ID_NEW_GAME,        // Start a new game.
    ID_LOAD_GAME,       // Load a saved game.
    ID_SAVE_GAME,       // Save game.
    ID_CREDITS,         // Display credits.

} MenuActions;

/**
 * @brief Representing the initial menu screen.
 * @return ID of the selected menu item.
 * @details Possible values: ID_NEW_GAME, ID_LOAD_GAME, ID_CREDITS, ID_EXIT.
 */
int MenuWelcomeScreen(void);

#endif //RALLYDAKAR_APPMENUS_H