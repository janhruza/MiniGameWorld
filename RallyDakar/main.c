//
// Created by jan on 28/02/2026.
//

#include <stdio.h>
#include <stdlib.h>

#include "inc/Ansi.h"
#include "inc/GameSession.h"
#include "inc/UI/ConsoleMenu.h"
#include "inc/UI/AppMenus.h"

void EvaluateGame(const StatusCode exitCode) {
    switch (exitCode) {
        default:
        case STATUS_ERROR:
            fprintf(stderr, "An error occurred. Error code: %d\n", exitCode);
            break;

        case STATUS_OK:
            fprintf(stdout, "Game exited successfully!\n");
            break;

        case STATUS_GAME_UNINITIALIZED:
            fprintf(stderr, "Game session is not initialized.\n");
            break;
    }
}

int main(int argc, const char *argv[]) {
    ClearScreen();
    CoDrawBanner();

    GameSession gs;
    GsInitialize(&gs);

    // TODO create/load game session
    while (true) {
        const int iWelcome = MenuWelcomeScreen();
        switch (iWelcome) {
            default: // The Q key, etc.
            case ID_EXIT:
                goto exit;

            case ID_NEW_GAME:
            case ID_DEBUG:
                // create the save game file
                if (GsSave(&gs, sSaveFile) == false) {
                    fprintf(stderr, "Unable to create the save game file.\n");
                    break;
                }

                // run the game loop
                const StatusCode result = GsStartGameLoop(&gs);

                // handle the results
                EvaluateGame(result);
                break;

            case ID_LOAD_GAME:
                if (GsLoad(&gs, sSaveFile) == false) {
                    fprintf(stderr, "Unable to load the save game file.\n");
                    break;
                }

                break;

            case ID_CREDITS:
                CoShowCredits();
                break;
        }
    }

    // app exit
    exit:
    printf("Goodbye!\n");
    return EXIT_SUCCESS;
}
