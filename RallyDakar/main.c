//
// Created by jan on 28/02/2026.
//

#include <stdio.h>
#include <stdlib.h>

#include "inc/Ansi.h"
#include "inc/GameSession.h"
#include "inc/UI/ConsoleMenu.h"
#include "inc/UI/AppMenus.h"

int main(int argc, const char *argv[]) {
    ClearScreen();
    CoDrawBanner();

    GameSession gs;

    // TODO create/load game session
    while (true) {
        const int iWelcome = MenuWelcomeScreen();
        switch (iWelcome) {
            default: // The Q key, etc.
            case ID_EXIT:
                goto exit;

            case ID_NEW_GAME:
            case ID_DEBUG:

                // run the game loop
                const StatusCode result = GsStartGameLoop(&gs);

                // handle the results
                switch (result) {
                    default:
                    case STATUS_ERROR:
                        fprintf(stderr, "An error occurred. Error code: %d\n", result);
                        break;

                    case STATUS_OK:
                        fprintf(stdout, "Game exited successfully!\n");
                        break;

                    case STATUS_GAME_UNINITIALIZED:
                        fprintf(stderr, "Game session is not initialized.\n");
                        break;
                }

            case ID_LOAD_GAME:
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
