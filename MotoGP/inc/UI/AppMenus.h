//
// Created by jan on 22/03/2026.
//

#ifndef MOTOGP_APPMENUS_H
#define MOTOGP_APPMENUS_H

#include "ConsoleMenu.h"

/**
 * @brief Representing the menu item ids.
 */
typedef enum tagMenuId : int
{
    ID_ERROR = -1,      // General error
    ID_EXIT,            // Exit menu
    ID_NEW_GAME,
    ID_LOAD_GAME,

} MenuId;

/**
 * Representing the main application menu.
 * @return Selected menu item identifier.
 */
int AppMainMenu(void);

#endif //MOTOGP_APPMENUS_H