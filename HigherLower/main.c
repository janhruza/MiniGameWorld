/*
 * main.c
 * Main application's entry point.
 */

#include "inc/Game.h"

int main(int argc, const char *argv[]) {
    GameInit();
    printf("Higher or Lower\nMade by %s@jendahruza%s\n\n", HIGHLIGHT3, CRESET);

    if (argc == 4) {
        // range_min, range_max and attempts specified
        const int range_min = atoi(argv[1]);
        const int range_max = atoi(argv[2]);
        const int attempts = atoi(argv[3]);

        return GamePlay(range_min, range_max, attempts);
    }

    else {
        return GamePlay(RANGE_MIN, RANGE_MAX, ATTEMPTS);
    }

}
