//
// Created by jan on 22/03/2026.
//

#include "../../inc/UI/AppMenus.h"
#include "../../inc/UI/Screens.h"
#include "../../inc/UI/ConsoleMenu.h"

#include <stdio.h>

#include "../../inc/GameSession.h"
#include "../../inc/UI/Ansi.h"

int ScrPause(void) {
    printf("\nPress any key to continue... ");
    return GetRawChar();
}

int ScrNotImplemented(void) {
    ClearScreen();
    printf("[%sFAIL%s] Not implemented.\n", ACCENT_TEXT, RESET);
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
                ScrNotImplemented();
                break;

            case ID_PRACTICE:
                ScrNotImplemented();
                break;

            case ID_SCOREBOARD:
                ClearScreen();
                printf("%s%-*s %-*s%s\n", ACCENT_BOLD, TEXT_LENGTH, "Name", 10, "Points", RESET);
                for (int j = 0; j < DRIVER_COUNT; j++) {
                    // print rider's score
                    RaceResult *rr = &session->Standings.Riders[session->CupIdx][j];
                    printf("%-*s %06d\n", TEXT_LENGTH, gDrivers[rr->EntityId].Name, rr->Pts);
                }

                ScrPause();
                break;

            default:
                break;
        }
    }

    exit:
    return ID_EXIT;
}