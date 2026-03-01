//
// Created by jan on 28/02/2026.
//

#include <stdlib.h>
#include "../inc/GameSession.h"

#include <stdio.h>

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

bool GsDisplayScoreboard(GameSession *session) {
    // TODO missing implementation
    return false;
}

StatusCode GsStartGameLoop(GameSession *session) {
    if (session == NULL) {
        return STATUS_GAME_UNINITIALIZED;
    }

    return STATUS_OK;
}

#pragma endregion