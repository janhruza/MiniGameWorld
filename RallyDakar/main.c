//
// Created by jan on 28/02/2026.
//

#include <stdio.h>
#include <stdlib.h>

#include "inc/Ansi.h"
#include "inc/GameSession.h"
#include "inc/UI/ConsoleMenu.h"
#include "inc/UI/AppMenus.h"
#include "inc/TerrainType.h"

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

void GenerateTestData(GameSession *session) {
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
    ClearScreen();
    CoDrawBanner();

    GameSession gs;
    GsInitialize(&gs);

    // create testing data
    GenerateTestData(&gs);

    // TODO create/load game session
    while (true) {
        const int iWelcome = MenuWelcomeScreen();
        switch (iWelcome) {
            default: // The Q key, etc.
            case ID_EXIT:
                goto exit;

            case ID_NEW_GAME:
            case ID_DEBUG:
                // create the save game file
                if (GsSave(&gs, sSaveFile) == false) {
                    fprintf(stderr, "Unable to create the save game file.\n");
                    break;
                }

                // run the game loop
                const StatusCode result = GsStartGameLoop(&gs);

                // handle the results
                EvaluateGame(result);
                break;

            case ID_LOAD_GAME:
                if (GsLoad(&gs, sSaveFile) == false) {
                    fprintf(stderr, "Unable to load the save game file.\n");
                    break;
                }

                break;

            case ID_CREDITS:
                CoShowCredits();
                break;
        }
    }

    // app exit
    exit:
    printf("Goodbye!\n");
    return EXIT_SUCCESS;
}
