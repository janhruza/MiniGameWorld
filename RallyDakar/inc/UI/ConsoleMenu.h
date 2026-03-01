//
// Created by jan on 01/03/2026.
//

#ifndef RALLYDAKAR_CONSOLEMENU_H
#define RALLYDAKAR_CONSOLEMENU_H

#define MENU_MAX_ITEMS      16
#define MENU_ITEM_WIDTH     40

#include "../Common.h"

/**
 * @brief Representing a single console menu item object.
 * @date 01/03/2026
 */
typedef struct {
    /**
     * @brief Representing the header text of the item.
     */
    char Header[SHORT_TEXT_LENGTH];

    /**
     * @brief Representing the unique menu item identifier.
     * @details Use this field as an identifier to a particular user action.
     */
    int Id;

} MenuItem;

/**
 * @brief Representing a base struct for an interactive console menu.
 */
typedef struct {
    /**
     * @brief Representing the list of menu items.
     */
    MenuItem Items[MENU_MAX_ITEMS];

    /**
     * @brief Representing the index of the active (selected) menu item from the Items array.
     */
    int ActiveIdx;

} ConsoleMenu;

#pragma region Methods

/**
 * @brief Initializes the console menu object.
 * @param menu A pointer to the target menu object.
 * @return true if the operation succeeded, otherwise false.
 */
bool CmInitMenu(ConsoleMenu *menu);

/**
 * @brief Helper function to draw a console menu to the terminal screen.
 * @param menu Pointer to a menu that should be drawn.
 * @return true if the function succeeds, otherwise false.
 */
bool CmDrawMenu(ConsoleMenu *menu);

/**
 * @brief Selects an item from the menu of items.
 * @param menu A pointer to the menu from which the user will pick the action item.
 * @return ID of the selected menu item or EOF if no item was selected or the method failed for any other reason.
 */
int CmSelectMenu(ConsoleMenu *menu);

#pragma endregion

#endif //RALLYDAKAR_CONSOLEMENU_H