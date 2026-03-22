//
// Created by jan on 22/03/2026.
//

#ifndef MOTOGP_APPMENUS_H
#define MOTOGP_APPMENUS_H

#include "../GameSession.h"

/**
 * @brief Representing the menu item ids.
 */
typedef enum tagMenuId : int
{
    ID_ERROR = -1,      // General error
    ID_EXIT,            // Exit menu
    ID_NEW_GAME,
    ID_LOAD_GAME,
    ID_CONTINUE_CUP,
    ID_NEW_CUP,
    ID_OVERVIEW,
    ID_SCOREBOARD,
    ID_SAVE_GAME,
    ID_RACE,            // Start race
    ID_PRACTICE,


} MenuId;

/**
 * Representing the application's welcome menu.
 * @return Selected menu item identifier.
 */
int AppWelcomeMenu(void);

/**
 * @brief Representing the main application menu.
 * @return Selected menu item identifier.
 */
int AppMainMenu(int bCupInProgress);

/**
 * @brief Representing the cup menu.
 * @param session Pointer to the active game session object.
 * @return Selected menu item identifier.
 */
int AppContinueCupMenu(GameSession *session);

#endif //MOTOGP_APPMENUS_H