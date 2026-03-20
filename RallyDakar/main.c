//
// Created by jan on 28/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

#include "inc/Ansi.h"
#include "inc/GameSession.h"
#include "inc/UI/ConsoleMenu.h"
#include "inc/UI/AppMenus.h"
#include "inc/TerrainType.h"
#include "inc/UI/Screens.h"
#include "inc/UI/MenuActions.h"

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
    SetConsoleTitle(PRODUCT_NAME);

    // set the random seed
    srand((unsigned int)time(NULL));

    GameSession *pSession = malloc(sizeof(GameSession));
    GsInitialize(pSession);

    int result = 0xFFFF;
    do
    {
        result = ScrWelcome(pSession);
    } while (result != ID_EXIT);

    // app exit
exit:
    free(pSession);
    ClearScreen();
    printf("Goodbye!\n");
    return EXIT_SUCCESS;
}
