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
    for (int i = 0; i < DRIVER_COUNT; i++) {
        debug_print("%02d: #%02d: %s\n", i+1, gDrivers[i].Number, gDrivers[i].Name);
    }
}

int main(int argc, const char **argv) {
    if (argc > 1) {
        fprintf(stderr, "%s: Arguments are disabled.\n", argv[0]);
        return 1;
    }

    AppInit();
    CoDrawBanner();

    Test();

    AppCleanup();
    return 0;
}