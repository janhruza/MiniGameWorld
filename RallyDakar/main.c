//
// Created by jan on 28/02/2026.
//

#include <stdio.h>

#include "inc/Ansi.h"
#include "inc/GameSession.h"
#include "inc/UI/ConsoleMenu.h"

int main(int argc, const char *argv[]) {
    ConsoleMenu menu;
    CmInitMenu(&menu);

    snprintf(menu.Header, SHORT_TEXT_LENGTH, "%sMAIN MENU%s", ACCENT_TEXT, RESET);

    ClearScreen();

    CoDrawBanner();

    for (int i = 0; i < 10; i++) {
        menu.Items[i].Id = i;
        snprintf(menu.Items[i].Header, SHORT_TEXT_LENGTH, "Item #%02d", i+1);
    }

    // select menu
    const int opt = CmSelectMenu(&menu);

    ClearScreen();
    printf("Selected ID: %d\n", opt);

    return 0;
}
