//
// Created by jan on 02/03/2026.
//

#ifndef RALLYDAKAR_APPMENUS_H
#define RALLYDAKAR_APPMENUS_H

#include "../GameSession.h"

#pragma region Main menus

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

#pragma endregion

#pragma region Main Screen submenus

/**
* @brief Representing the continue cup menu. This shall be called both on continuing a cup and after starting a new cup.
* @param session Active game session.
* @return ID of the selected item.
*/
int MenuContinueCup(GameSession* session);

/**
* @brief Representing the new cup menu. After starting a new cup, MenuContinueCup method shall be called.
* @param session Active game session.
* @return ID of the selected item.
*/
int MenuNewCup(GameSession* session);

/**
* @brief Representing the adjust team vehicles menu.
* @param session Active game session.
* @return ID of the selected item.
*/
int MenuAdjustVehicles(GameSession* session);

#pragma endregion

#endif //RALLYDAKAR_APPMENUS_H