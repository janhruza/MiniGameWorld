//
// Created by jan on 28/02/2026.
//

#include <stdlib.h>
#include "../inc/GameSession.h"

#include <stdio.h>
#include <time.h>

#include "../inc/Ansi.h"
#include "../inc/UI/AppMenus.h"
#include "../inc/TeamInfo.h"

#pragma region Load/Save functions

bool GsSave(const GameSession *session, const char *fileName) {
    if (session == NULL || fileName == NULL) {
        return false;
    }

    FILE *file = fopen(fileName, "wb");
    if (file == NULL) {
        return false;
    }

    const size_t written = fwrite(session, sizeof(GameSession), 1, file);
    fclose(file);

    return written == 1;
}

bool GsLoad(GameSession *session, const char *fileName) {
    if (session == NULL || fileName == NULL) {
        return false;
    }

    FILE *file = fopen(fileName, "rb");
    if (file == NULL) {
        return false;
    }

    const size_t read = fread(session, sizeof(GameSession), 1, file);

    fclose(file);
    return read == 1;
}

#pragma endregion

#pragma region Main game logic

// Helper functions
#pragma region Helper functions

#pragma endregion

int GsValidTeamsCount(const GameSession *session) {
    if (session == NULL) return EOF;

    int counter = 0;
    for (int i = 0; i < MAX_TEAMS; i++) {
        if (TeamIsValid(&session->Teams[i]) == true) counter++;
    }

    return counter;
}

bool GsDisplayScoreboard(GameSession *session) {
    if (GsValidTeamsCount(session) <= 0) {
        // unable to get any valid teams
        return false;
    }

    // FIXME implement better scoreboard
    printf("%sCURRENT STANDINGS%s\n", ACCENT_BOLD, RESET);
    for (int i = 0; i < MAX_TEAMS; i++) {

        // filter out invalid teams
        if (TeamIsValid(&session->Teams[i]) == false) continue;

        printf("%*s %f (%f)\n", SHORT_TEXT_LENGTH, session->Teams[i].TeamName, session->Teams[i].TimeTotal, session->Teams[i].TimeTotal);
    }

    return true;
}

StatusCode GsStartGameLoop(GameSession *session) {
    if (session == NULL) {
        return STATUS_GAME_UNINITIALIZED;
    }

    // TODO missing implementation
    return STATUS_OK;
}

#pragma endregion