//
// Created by jan on 02/03/2026.
//

#ifndef RALLYDAKAR_APPMENUS_H
#define RALLYDAKAR_APPMENUS_H

typedef enum : int {
    ID_EXIT = 0,
    ID_PLAY,        // debug option
    ID_NEW_GAME,
    ID_LOAD_GAME,
    ID_SAVE_GAME,
    ID_CREDITS

} MenuActions;

/**
 * @brief Representing the initial menu screen.
 * @return ID of the selected menu item.
 * @details Possible values: ID_NEW_GAME, ID_LOAD_GAME, ID_CREDITS, ID_EXIT.
 */
int MenuWelcomeScreen(void);

#endif //RALLYDAKAR_APPMENUS_H