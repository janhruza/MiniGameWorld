//
// Game.h
// Created by jan on 28/02/2026
// Representing various game logic functions.
//

#ifndef HIGHERLOWER_GAME_H
#define HIGHERLOWER_GAME_H

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Values.h"

/// <summary>
/// Determines whether the game is initialized (1) or not (0).
/// </summary>
static int initialized = 0;

/// <summary>
/// Gets the ISO 8601 date and time string.
/// </summary>
/// <param name="buf">Output string buffer.</param>
/// <returns>Always 0.</returns>
/// <remarks>
/// This method will write at most ISO_DATE_TIME_LENGTH bytes to the output buffer (buf).
/// </remarks>
static int GetISO8601Time(char* buf) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    snprintf(buf, ISO_DATE_TIME_LENGTH, "%02d-%02d-%02dT%02d:%02d:%02dZ", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
    return 0;
}

/// <summary>
/// Writes the given message along the current date and time to the log file.
/// </summary>
/// <param name="msg">The message to be written.</param>
/// <returns>
/// If the message is written, 0 is returned. If the file cannot be opened, EOF is returned.
/// </returns>
/// <remarks>
/// This method adds the new line character at the end of the given message (msg).
/// </remarks>
static int WriteLog(const char *msg) {
    char buf[ISO_DATE_TIME_LENGTH];
    GetISO8601Time(buf);

    FILE *f = fopen("log.txt", "a");
    if (f == NULL) {
        return EOF;
    }

    fprintf(f, "%s: %s\n", buf, msg);
    fclose(f);
    return 0;
}

static void GameInit(void) {
    srand(time(NULL));
    initialized = 1;
    WriteLog("Game initialized");
}

static int GamePlay(const int range_min, const int range_max, const int max_attempts) {
    if (!initialized) {
        return EOF;
    }

    // get the target number and input counter
    const int num = rand() % (range_max - range_min) + range_min;
    int counter = 0;

    printf("Guess a number between %s%d%s and %s%d%s\n", HIGHLIGHT3, range_min, CRESET, HIGHLIGHT3, range_max, CRESET);
    printf("Maximum attempts: %s%d%s\n\n", HIGHLIGHT3, max_attempts, CRESET);

    // main loop
    while (counter < max_attempts) {
        counter += 1;

        printf("Your guess: ");
        int guess = EOF;
        printf(HIGHLIGHT3);
        scanf("%d", &guess);
        printf(CRESET);

        if (guess == num) {
            printf("Correct! The number was %s%d%s!\nYou found it in %s%d%s attempts!\n", HIGHLIGHT3, num, CRESET, HIGHLIGHT3, counter, CRESET);
            return counter;
        }

        printf("Number %s%d%s is ", HIGHLIGHT3, guess, CRESET);
        if (guess < num) {
            printf("%sLOWER%s", HIGHLIGHT1, CRESET);
        }

        else {
            printf("%sHIGHER%s", HIGHLIGHT2, CRESET);
        }

        printf(" than the target number.\n");
    }

    // target number was not found in the set time (attempts)

    printf("You lost. The target number was %s%d%s.", HIGHLIGHT3, num, CRESET);
    return EOF;
}

#endif //HIGHERLOWER_GAME_H