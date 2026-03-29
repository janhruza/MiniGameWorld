#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "inc/UI/Ansi.h"
#include "inc/Common.h"

STATUS AppInit(void) {
    srand(time(NULL));
    ClearScreen();
    return STATUS_OK;
}

STATUS AppCleanup(void) {
    ClearScreen();
    return STATUS_OK;
}

int min(const int a, const int b) {
    return (a < b) ? a : b;
}

int main(void) {

    if (AppInit() != STATUS_OK) {
        fprintf(stderr, "Initialization failed.\n");
    }

    // TODO main logic goes here
    CoDrawBanner();

    if (AppCleanup() != STATUS_OK) {
        fprintf(stderr, "Cleanup failed.\n");
    }

    return EXIT_SUCCESS;
}
