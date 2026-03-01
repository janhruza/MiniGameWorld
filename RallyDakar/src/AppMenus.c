//
// Created by jan on 02/03/2026.
//

#include "../inc/UI/AppMenus.h"
#include "../inc/UI/ConsoleMenu.h"

int MenuWelcomeScreen(void) {
    ConsoleMenu menu;
    CmInitMenu(&menu);

    menu.Items[0] = (MenuItem) {
        .Id = 1,
        .Header = "Play"
    };

    menu.Items[1] = (MenuItem) {
        .Id = 2,
        .Header = "About Rally Dakar"
    };

    CmMakeSeparator(&menu.Items[2]);

    menu.Items[3] = (MenuItem) {
        .Id = 3,
        .Header = "Exit"
    };

    return CmSelectMenu(&menu);
}
