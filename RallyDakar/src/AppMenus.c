//
// Created by jan on 02/03/2026.
//

#include "../inc/UI/AppMenus.h"
#include "../inc/UI/ConsoleMenu.h"
#include "../inc/UI/MenuActions.h"
#include "../inc/Debug.h"
#include <stdio.h>

#pragma region Main menus

int MenuWelcomeScreen(void) {
    ConsoleMenu menu;
    CmInitMenu(&menu);
    snprintf(menu.Header, SHORT_TEXT_LENGTH, PRODUCT);

    int idx = 0;

    menu.Items[idx++] = (MenuItem) {
        .Id = ID_NEW_GAME,
        .Header = "New Game"
    };

    menu.Items[idx++] = (MenuItem) {
        .Id = ID_LOAD_GAME,
        .Header = "Load Game"
    };

    CmMakeSeparator(&menu.Items[idx++]);

    menu.Items[idx++] = (MenuItem) {
        .Id = ID_CREDITS,
        .Header = "Credits"
    };

    CmMakeSeparator(&menu.Items[idx++]);

    menu.Items[idx++] = (MenuItem) {
        .Id = ID_EXIT,
        .Header = "Quit"
    };

    return CmSelectMenu(&menu);
}

int MenuMainScreen(GameSession *session)
{
    // session is invalid
    if (session == NULL)
    {
        return ID_ERROR;
    }

    // ID_NEW_CUP, ID_CONTINUE_CUP, ID_ADJUST_VEHICLES, ID_EXIT

    ConsoleMenu cm;
    CmInitMenu(&cm);
    snprintf(cm.Header, SHORT_TEXT_LENGTH, "MAIN MENU - %s", session->Teams[PLAYER_TEAM_INDEX].TeamName);

    int idx = 0;

    if (session->StageIndex > 0)
    {
        // continue cup
        cm.Items[idx++] = (MenuItem){
            .Id = ID_CONTINUE_CUP,
        };
        snprintf(cm.Items[idx - 1].Header, SHORT_TEXT_LENGTH, "Continue Cup (%d/%d)", session->StageIndex + 1, MAX_STAGES);
    }

    cm.Items[idx++] = (MenuItem){
        .Id = ID_NEW_CUP,
        .Header = "New Cup"
    };

    cm.Items[idx++] = (MenuItem){
        .Id = ID_GARAGE,
        .Header = "Garage"
    };

    CmMakeSeparator(&cm.Items[idx++]);

    cm.Items[idx++] = (MenuItem){
        .Id = ID_SAVE_GAME,
        .Header = "Save"
    };

    CmMakeSeparator(&cm.Items[idx++]);

    cm.Items[idx++] = (MenuItem){
        .Id = ID_EXIT,
        .Header = "Back"
    };

    return CmSelectMenu(&cm);
}

#pragma endregion

#pragma region Main Screen submenus

int MenuContinueCup(GameSession* session)
{
    ConsoleMenu menu;
    CmInitMenu(&menu);
    snprintf(menu.Header, SHORT_TEXT_LENGTH, "Continue Cup: Stage %d/%d", session->StageIndex + 1, MAX_STAGES);

    int idx = 0;

    menu.Items[idx++] = (MenuItem){
        .Id = ID_RACE,
        .Header = "Start Race"
    };

    CmMakeSeparator(&menu.Items[idx++]);

    menu.Items[idx++] = (MenuItem)
    {
        .Id = ID_SCOREBOARD,
        .Header = "View Scoreboard"
    };

    menu.Items[idx++] = (MenuItem)
    {
        .Id = ID_REPAIR_VEHICLES,
        .Header = "Service Vehicles"
    };

    CmMakeSeparator(&menu.Items[idx++]);

    menu.Items[idx++] = (MenuItem)
    {
        .Id = ID_EXIT,
        .Header = "Back"
    };

    return CmSelectMenu(&menu);
}

int MenuAdjustVehicles(GameSession* session)
{
    DbgNotImplemented("MenuAdjustVehicles");
    return ID_NOT_IMPLEMENTED;
}

#pragma endregion