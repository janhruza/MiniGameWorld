//
// Created by jan on 28/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "inc/Ansi.h"
#include "inc/GameSession.h"
#include "inc/UI/ConsoleMenu.h"
#include "inc/UI/AppMenus.h"
#include "inc/TerrainType.h"
#include "inc/UI/Screens.h"
#include "inc/UI/MenuActions.h"

void EvaluateGame(const StatusCode exitCode) {
    switch (exitCode) {
        default:
        case STATUS_ERROR:
            fprintf(stderr, "An error occurred. Error code: %d\n", exitCode);
            break;

        case STATUS_OK:
            fprintf(stdout, "Game exited successfully!\n");
            break;

        case STATUS_GAME_UNINITIALIZED:
            fprintf(stderr, "Game session is not initialized.\n");
            break;
    }
}

static void GenerateTestData(GameSession *session) {
    if (session == NULL) {
        return;
    }

    const char *locations[] = {
        "Sea Camp", "Alula", "Ha'il", "Ha'il Loop", "Shaybah",
        "Empty Quarter", "Marathon Stage", "Haradh", "Al-Hofuf", "Dammam",
        "Riyadh", "Al-Duwadimi", "Tabuk", "Yanbu"
    };

    for (int i = 0; i < 14; i++) {
        session->Stages[i] = (Stage){
            .Id = i + 1,
            .Distance = 150.0 + (rand() % 400),
            .Difficulty = (float)(i + 1) / 14.0,
            .Terrain = (i % 2 == 0) ? SAND : (DIRT | ROCKS)
        };

        snprintf(session->Stages[i].Location, 50, "%s", locations[i]);
    }

    const char *teamNames[] = {
        "Red Bull Desert Wings", "Monster Energy Honda", "Toyota Gazoo Racing",
        "Kamal Dakar Team", "Bahrain Raid Xtreme", "Audi Sport",
        "Czech Buggyra Academy", "Fantic Rally Team", "Sherco Factory", "KTM Factory"
    };

    for (int i = 0; i < 30; i++) {
        if (i < 10) {
            session->Teams[i].Id = i + 1;
            snprintf(session->Teams[i].TeamName, SHORT_TEXT_LENGTH, "%s", teamNames[i]);
        } else {
            session->Teams[i].Id = i + 1;
            snprintf(session->Teams[i].TeamName, SHORT_TEXT_LENGTH, "Privateer No. %d", i + 1);
        }

        session->Teams[i].TimeTotal = 0;
        session->Teams[i].TimePenalty = 0;

        VehicleInit(&session->Teams[i].Vehicles[0]);
        session->Teams[i].Vehicles[0] = (VehicleInfo){
            .Drivers = {"Driver A", "Co-Driver B", "Mechanic C", "", ""},
            .Time = 0,
            .Penalty = 0,
            .Health = HEALTH_MAX
        };
    }
}

int main(int argc, const char *argv[]) {
    SetConsoleTitle(PRODUCT_NAME);
    GameSession *pSession = malloc(sizeof(GameSession));
    GsInitialize(pSession);

    // create testing data
    GenerateTestData(pSession);

    int result = 0xFFFF;
    do
    {
        result = ScrWelcome(pSession);
    } while (result != ID_EXIT);

    // app exit
exit:
    free(pSession);
    printf("Goodbye!\n");
    return EXIT_SUCCESS;
}
