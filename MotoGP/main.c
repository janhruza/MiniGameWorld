#include <stdio.h>

#include "inc/Common.h"
#include "inc/GameSession.h"
#include "inc/UI/Ansi.h"
#include "inc/Debug.h"

static void AppInit(void) {
    debug_open();
    printf(CURSOR_HIDE);
}

static void AppCleanup(void) {
    debug_close();
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
        fprintf(stderr, "%s: Arguments are disabled.\n", argv[0]);
        return 1;
    }

    AppInit();
    CoDrawBanner();

    // main code goes here
    Test();

    AppCleanup();
    return 0;
}