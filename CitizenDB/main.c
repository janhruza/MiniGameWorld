#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#include "inc/Common.h"
#include "inc/UI/Ansi.h"
#include "inc/UI/Screens.h"
#include "inc/AppState.h"
#include "inc/Person.h"

static AppState* state = NULL;

static STATUS AppInit(void) {
    srand(time(NULL));

    // initialize globals
    state = (AppState*)malloc(sizeof(AppState));

    if (state == NULL)
    {
        fprintf(stderr, "Malloc failed.\n");
        return STATUS_CRITICAL;
    }

    ClearScreen();
    return STATUS_OK;
}

static STATUS AppCleanup(void) {
    ClearScreen();
    if (state != NULL)
    {
        free(state);
        state = NULL;
    }

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
    CoSetConsoleTitle("My Awesome Citizen Database!");
    CoDrawBanner();
    CoPause();

    if (AppCleanup() != STATUS_OK) {
        fprintf(stderr, "Cleanup failed.\n");
    }

    return EXIT_SUCCESS;
}
