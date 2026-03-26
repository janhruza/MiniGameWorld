//
// Created by jan on 22/03/2026.
//

#include "../../inc/UI/AppMenus.h"

#include <stdio.h>

#include "../../inc/Common.h"
#include "../../inc/GameSession.h"
#include "../../inc/UI/ConsoleMenu.h"

int AppWelcomeMenu(void) {
    ConsoleMenu cm;
    CmInitMenu(&cm);

    snprintf(cm.Header, MENU_ITEM_HEADER_WIDTH, "%s", PRODUCT_NAME);

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

int AppMainMenu(int bCupInProgress) {
    ConsoleMenu cm;
    CmInitMenu(&cm);

    /*
     *  MAIN MENU
     *  Continue Championship (if in progress)
     *  New Championship
     *  ---
     *  Overview (riders, tracks, teams, etc.)
     *  ---
     *  Back
     */

    int idx = 0;
    if (bCupInProgress == TRUE) {
        cm.Items[idx++] = (MenuItem)
        {
            .Header = "Continue Championship",
            .Id = ID_CONTINUE_CUP
        };
    }

    cm.Items[idx++] = (MenuItem)
    {
        .Header = "New Championship",
        .Id = ID_NEW_CUP
    };

    CmMakeSeparator(&cm.Items[idx++]);

    cm.Items[idx++] = (MenuItem){
        .Header = "Overview",
        .Id = ID_OVERVIEW
    };

    CmMakeSeparator(&cm.Items[idx++]);

    cm.Items[idx++] = (MenuItem){
        .Header = "Save",
        .Id = ID_SAVE_GAME
    };

    CmMakeSeparator(&cm.Items[idx++]);

    cm.Items[idx++] = (MenuItem)
    {
        .Header = "Back",
        .Id = ID_EXIT
    };

    return CmSelectMenu(&cm);
}

int AppContinueCupMenu(GameSession *session) {
    ConsoleMenu cm;
    CmInitMenu(&cm);

    snprintf(cm.Header, MENU_ITEM_HEADER_WIDTH, "Continue Cup (%02d/%02d)", session->CupIdx + 1, TRACK_COUNT);

    int idx = 0;
    cm.Items[idx++] = (MenuItem) {
        .Header = "Race",
        .Id = ID_RACE
    };

    CmMakeSeparator(&cm.Items[idx++]);

    cm.Items[idx++] = (MenuItem) {
        .Header = "Scoreboard",
        .Id = ID_SCOREBOARD
    };

    CmMakeSeparator(&cm.Items[idx++]);

    cm.Items[idx++] = (MenuItem) {
        .Header = "Back",
        .Id = ID_EXIT
    };

    return CmSelectMenu(&cm);
}