//
// Created by jan on 01/03/2026.
//

#ifndef RALLYDAKAR_CONSOLEMENU_H
#define RALLYDAKAR_CONSOLEMENU_H

#define MENU_ITEM_HEADER_WIDTH  SHORT_TEXT_LENGTH
#define MENU_MAX_ITEMS          16
#define MENU_ITEM_WIDTH         (MENU_ITEM_HEADER_WIDTH + 4)
#define MENU_LEFT_PADDING       4
#define MENU_ID_SEPARATOR       0xFFFF

#include "../Common.h"

/**
 * @brief Representing a single console menu item object.
 * @date 01/03/2026
 */
typedef struct {
    /**
     * @brief Representing the header text of the item.
     */
    char Header[MENU_ITEM_HEADER_WIDTH];

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

    /**
     * @brief Menu header text.
     */
    char Header[MENU_ITEM_HEADER_WIDTH];

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

/**
 * @brief Determines whether the item is marked as separator.
 * @param item Target menu item.
 * @return true, if the menu is a separator, otherwise false.
 */
bool CmIsSeparator(const MenuItem *item);

/**
 * @Makes the target item a separator.
 * @param item Target menu item.
 * @return Operation result.
 */
bool CmMakeSeparator(MenuItem *item);

#pragma endregion

#endif //RALLYDAKAR_CONSOLEMENU_H