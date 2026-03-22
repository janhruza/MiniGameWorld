#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inc/Common.h"
#include "inc/GameSession.h"
#include "inc/UI/Ansi.h"
#include "inc/Debug.h"
#include "inc/UI/AppMenus.h"

#define CMD_HELP        "--help"

/**
 * @brief Representing the global active game session pointer.
 */
GameSession *pSession = NULL;

static void ShowHelp(void) {
    // prints the help/about
    CoDrawBanner();
    printf("\n");

    printf("%sABOUT %s%s\n", BOLD, PRODUCT_NAME, RESET);
    puts("This app is a simple random MotoGP manager. It was made solely for learning purposes.\n");

    printf("%sCREDITS%s\n", BOLD, RESET);
    printf("Made with %s\u2764%s by %s!\n", ACCENT_TEXT, RESET, AUTHOR);
    return;
}

static void AppInit(void) {
    debug_open();
    pSession = GsInit();
    printf(CURSOR_HIDE);
}

static void AppCleanup(void) {
    debug_close();
    GsFree(pSession);
    printf(CURSOR_SHOW);
}

static void Test(void) {
    printf("--- DRIVERS ---\n");
    for (int i = 0; i < DRIVER_COUNT; i++) {
        printf("%02d: #%02d: %s (%s)\n", i+1, gDrivers[i].Number, gDrivers[i].Name, gTeams[gDrivers[i].IdxTeam].Name);
    }

    printf("\n--- TEAMS ---\n");
    for (int i = 0; i < TEAM_COUNT; i++) {
        printf("%02d: %-*s (%d)\n", i+1, DRIVER_COUNT, gTeams[i].Name, gTeams[i].Bike);
    }

    printf("\n--- TRACKS ---\n");
    for (int i = 0; i < TRACK_COUNT; i++) {
        printf("%02d: %s (%s)\n", i+1, gTracks[i].Name, gTracks[i].Circuit);
    }
}

int main(int argc, const char **argv) {
    if (argc > 1) {

        // help is allowed
        if (strcmp(argv[1], CMD_HELP) == 0) {
            ShowHelp();
            return EXIT_SUCCESS;
        }

        // arguments are disabled
        fprintf(stderr, "%s: Arguments are disabled.\n", argv[0]);
        return EXIT_FAILURE;
    }

    AppInit();
    CoDrawBanner();

    // main code goes here
    AppCleanup();
    return EXIT_SUCCESS;
}