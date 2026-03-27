//
// Created by jan on 22/03/2026.
//

#include "../../inc/UI/AppMenus.h"
#include "../../inc/UI/Screens.h"
#include "../../inc/UI/ConsoleMenu.h"

#include <stdio.h>
#include <stdlib.h>

#include "../../inc/GameSession.h"
#include "../../inc/UI/Ansi.h"

int ScrPause(void) {
    printf("\nPress any key to continue... ");
    return GetRawChar();
}

int ScrNotImplemented(void) {
    ClearScreen();
    printf("[%sFAIL%s] Not implemented.\n", ACCENT_DEBUG, RESET);
    return ScrPause();
}

int ScrError(const char *msg) {
    ClearScreen();
    printf("[%sFAIL%s] %s\n", ACCENT_DEBUG, RESET, msg);
    return ScrPause();
}

int ScrWelcomeScreen(GameSession *session) {
    while (TRUE) {
        ClearScreen();
        const int opt = AppWelcomeMenu();

        switch (opt) {
            default:
                break;

            case ID_EXIT:
                goto exit;

            case ID_NEW_GAME:
                ClearScreen();
                if (GsFree(session) != STATUS_OK) {
                    puts("Unable to free memory");
                    ScrPause();
                    break;
                }
                session = GsInit();
                if (session == NULL) {
                    puts("Unable to initialize game session");
                    ScrPause();
                    break;
                }

                // select rider
                int drvIdx = ScrSelectDriver();
                if (drvIdx == -1) {
                    puts("Unable to select driver");
                    ScrPause();
                    break;
                }

                // assign the driver index
                session->PlayerIdx = drvIdx;

                GsSave(session);
                ScrMainMenu(session);
                break;

            case ID_LOAD_GAME:
                ClearScreen();

                if (GsLoad(session) != STATUS_OK) {
                    puts("Unable to load game session");
                    ScrPause();
                    break;
                }

                ScrMainMenu(session);
                break;
        }
    }

    exit:
    return ID_EXIT;
}

int ScrMainMenu(GameSession *session) {
    BOOL inProgress = GsCupInProgress(session);
    while (TRUE) {
        ClearScreen();

        const int opt = AppMainMenu(inProgress);
        switch (opt) {
            case ID_EXIT:
                goto exit;

            case ID_CONTINUE_CUP:
                if (inProgress == FALSE) {
                    // no cup in progress
                    break;
                }

                ScrContinueCup(session);
                break;

            case ID_NEW_CUP:
                // reset the event index and continue
                session->CupIdx = 0;
                ScrContinueCup(session);
                break;

            case ID_SAVE_GAME:
                if (GsSave(session) == STATUS_OK) {
                    ClearScreen();
                    puts("Game saved!");
                    ScrPause();
                    break;
                }

                else {
                    ClearScreen();
                    puts("Unable to save game.");
                    ScrPause();
                    break;
                }
                break;

            case ID_OVERVIEW:
                // display riders, teams, etc.
                ClearScreen();
                GsDisplayData();
                ScrPause();
                break;

            default:
                break;
        }
    }

    exit:
    return ID_EXIT;
}

int ScrContinueCup(GameSession *session) {
    while (TRUE) {
        ClearScreen();
        const int opt = AppContinueCupMenu(session);
        switch (opt) {
            case ID_EXIT:
                goto exit;

            case ID_RACE:
                if (GsRace(session) != STATUS_OK) {
                    ClearScreen();
                    ScrError("Unable to start race.");
                }
                break;

            case ID_SCOREBOARD:
                ClearScreen();
                if (GsFinalResults(session) != STATUS_OK) {
                    ClearScreen();
                    ScrError("Unable to show scoreboard.");
                }
                break;

            default:
                break;
        }
    }

    exit:
    return ID_EXIT;
}

int ScrSelectDriver(void)
{
    ClearScreen();

    // print available drivers
    printf("%s--- Available Riders ---%s\n", BOLD, RESET);
    for (int i = 0; i < DRIVER_COUNT; i++) {
        printf("%2d: #%02d: %s%-*s%s %*s\n", i+1, gDrivers[i].Number, ACCENT_TEXT, TEXT_LENGTH, gDrivers[i].Name, RESET, 3, CoGetCountryName(gDrivers[i].Country));
    }

    // select driver
    int idx = -1;

    printf("\nEnter driver's ID [1-%d]: ", DRIVER_COUNT);
    scanf("%d", &idx);

    // adjust the index to the global gDrivers array
    idx--;

    // flush buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    return idx;
}