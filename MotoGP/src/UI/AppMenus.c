//
// Created by jan on 22/03/2026.
//

#include "../../inc/UI/AppMenus.h"

int AppMainMenu(void) {
    ConsoleMenu cm;
    CmInitMenu(&cm);

    int idx = 0;
    cm.Items[idx++] = (MenuItem)
    {
        .Header = "New Game",
        .Id = ID_NEW_GAME,
    };

    cm.Items[idx++] = (MenuItem) {
        .Header = "Load Game",
        .Id = ID_LOAD_GAME
    };

    CmMakeSeparator(&cm.Items[idx++]);

    cm.Items[idx++] = (MenuItem) {
        .Header = "Quit",
        .Id = ID_EXIT
    };

    return CmSelectMenu(&cm);
}