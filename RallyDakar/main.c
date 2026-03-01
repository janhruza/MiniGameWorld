//
// Created by jan on 28/02/2026.
//

#include <stdio.h>

#include "inc/Ansi.h"
#include "inc/GameSession.h"
#include "inc/UI/ConsoleMenu.h"
#include "inc/UI/AppMenus.h"

int main(int argc, const char *argv[]) {
    ConsoleMenu menu;
    CmInitMenu(&menu);

    snprintf(menu.Header, SHORT_TEXT_LENGTH, "%sMAIN MENU%s", ACCENT_TEXT, RESET);

    ClearScreen();
    CoDrawBanner();

    // select menu
    const int opt = MenuWelcomeScreen();

    ClearScreen();
    printf("Selected ID: %d\n", opt);

    return 0;
}
