//
// Created by jan on 02/03/2026.
//

#include "../inc/UI/AppMenus.h"
#include "../inc/UI/ConsoleMenu.h"

int MenuWelcomeScreen(void) {
    ConsoleMenu menu;
    CmInitMenu(&menu);

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
    if (session == NULL) return ID_ERROR;

    // ID_NEW_CUP, ID_CONTINUE_CUP, ID_ADJUST_VEHICLES, ID_EXIT

    ConsoleMenu cm;
    CmInitMenu(&cm);



    return ID_EXIT;
}