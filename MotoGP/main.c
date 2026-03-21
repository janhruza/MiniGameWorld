#include <stdio.h>

#include "inc/Common.h"
#include "inc/GameSession.h"
#include "inc/UI/Ansi.h"

FILE* debug_fd;

static void AppInit(void) {
    debug_fd = fopen("debug.txt", "w+");
    printf(CURSOR_HIDE);
}

static void AppCleanup(void) {
    fclose(debug_fd);
    printf(CURSOR_SHOW);
}

static void Test(void) {
    for (int i = 0; i < DRIVER_COUNT; i++) {
        fprintf(debug_fd, "%02d: #%02d: %s%s%s\n", i+1, gDrivers[i].Number, ACCENT_DEBUG, gDrivers[i].Name, RESET);
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