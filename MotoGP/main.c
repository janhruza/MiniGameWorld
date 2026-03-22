#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inc/Common.h"
#include "inc/GameSession.h"
#include "inc/UI/Ansi.h"
#include "inc/Debug.h"
#include "inc/UI/Screens.h"

#define CMD_HELP        "--help"

/**
 * @brief Representing the global active game session pointer.
 */
GameSession *pSession = NULL;

static void ShowHelp(void) {
    // prints the help/about
    CoDrawBanner();

    printf("%sABOUT %s%s\n", BOLD, PRODUCT_NAME, RESET);
    puts("This app is a simple random MotoGP manager. It was made solely for learning purposes.\n");

    printf("%sCREDITS%s\n", BOLD, RESET);
    printf("Made with %s\u2764%s by %s!\n", ACCENT_TEXT, RESET, AUTHOR);
    return;
}

static void AppInit(void) {
    debug_open();
    pSession = GsInit();
}

static void AppCleanup(void) {
    debug_close();
    GsFree(pSession);
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

    ScrWelcomeScreen(pSession);

    // main code goes here
    AppCleanup();
    return EXIT_SUCCESS;
}