#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "inc/UI/Ansi.h"
#include "inc/Common.h"

static STATUS AppInit(void) {
    srand(time(NULL));
    ClearScreen();
    return STATUS_OK;
}

static STATUS AppCleanup(void) {
    ClearScreen();
    return STATUS_OK;
}

#ifndef _WIN32

int min(const int a, const int b)
{
    return (a < b) ? a : b;
}

#endif // !_WIN32

int main(void) {

    if (AppInit() != STATUS_OK) {
        fprintf(stderr, "Initialization failed.\n");
    }

    // TODO main logic goes here
    CoDrawBanner();

    printf("%sWELCOME!%s\n", ACCENT_TEXT, RESET);
    CoPause();

    if (AppCleanup() != STATUS_OK) {
        fprintf(stderr, "Cleanup failed.\n");
    }

    return EXIT_SUCCESS;
}
