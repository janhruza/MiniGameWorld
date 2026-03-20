//
// Created by jan on 28/02/2026.
//

#include <stdlib.h>
#include "../inc/GameSession.h"

#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <unistd.h>

#include "../inc/Ansi.h"
#include "../inc/UI/AppMenus.h"
#include "../inc/TeamInfo.h"
#include "../inc/TerrainType.h"
#include "../inc/Timespan.h"

#define min(a, b) ((a) < (b) ? (a) : (b))

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

void GsInitialize(GameSession *session) {
    memset(session, 0, sizeof(GameSession));
}

int GsValidTeamsCount(const GameSession *session) {
    if (session == NULL) return EOF;

    int counter = 0;
    for (int i = 0; i < MAX_TEAMS; i++) {
        if (TeamIsValid(&session->Teams[i]) == true) counter++;
    }
    
    return counter;
}

int GsSortTeams(GameSession* session, TeamInfo **teams) {
    if (session == NULL || teams == NULL) {
        return STATUS_GAME_UNINITIALIZED;
    }

    // 1. Initialize your malloc'd array with pointers to the original data
    for (int i = 0; i < MAX_TEAMS; i++) {
        teams[i] = &session->Teams[i];
    }

    // 2. Sort the pointers 
    for (int i = 0; i < MAX_TEAMS - 1; i++) {
        for (int j = 0; j < MAX_TEAMS - i - 1; j++) {

            float total = teams[j]->TimeRace + teams[j]->TimePenalty;
            float next = teams[j + 1]->TimeRace + teams[j + 1]->TimePenalty;
            if (total > next) {
                // Swap the pointers, not the structs
                TeamInfo* temp = teams[j];
                teams[j] = teams[j + 1];
                teams[j + 1] = temp;
            }
        }
    }

    return STATUS_OK;
}

// bool GsDisplayScoreboard(GameSession* session) {
//     if (GsValidTeamsCount(session) <= 0) {
//         // unable to get any valid teams
//         return false;
//     }
//
//     // 1. Allocate space for an array of POINTERS
//     TeamInfo** teams = calloc(MAX_TEAMS, sizeof(TeamInfo*));
//
//     // 2. Pass the array directly
//     GsSortTeams(session, teams);
//
//     printf("%sCURRENT STANDINGS%s\n", ACCENT_BOLD, RESET);
//
//     // Optional: Keep a separate rank counter if invalid teams cause gaps in numbering
//     int rank = 1;
//
//     for (int i = 0; i < MAX_TEAMS; i++) {
//         // 3. Pass the pointer directly to TeamIsValid (assuming it takes TeamInfo*)
//         if (TeamIsValid(teams[i]) == false) continue;
//
//         // 4. Check if the current sorted team is actually the player's team
//         bool isPlayerTeam = (teams[i] == &session->Teams[PLAYER_TEAM_INDEX]);
//
//         Timespan ts;
//         TsFromSeconds(teams[i]->TimeRace, &ts);
//
//         if (isPlayerTeam) {
//             // 5. Dereference the sorted pointers (teams[i]->) to get the data
//             printf("%s%2d. %-*s %02d:%02d (%.2f)%s\n", ACCENT_TEXT, rank, SHORT_TEXT_LENGTH,
//                 teams[i]->TeamName, ts.Minutes, ts.Seconds, teams[i]->TimePenalty, RESET);
//         }
//         else {
//             printf("%2d. %-*s %02d:%02d (%.2f)\n", rank, SHORT_TEXT_LENGTH,
//                 teams[i]->TeamName, ts.Minutes, ts.Seconds, teams[i]->TimePenalty);
//         }
//
//         rank++; // Increment rank only for valid teams
//     }
//
//     printf("\n");
//
//     free(teams);
//     return true;
// }

bool GsDisplayScoreboard(GameSession* session) {
    if (session == NULL || GsValidTeamsCount(session) <= 0) {
        return false;
    }

    TeamInfo** teams = calloc(MAX_TEAMS, sizeof(TeamInfo*));
    if (teams == NULL) return false;

    GsSortTeams(session, teams);

    printf("%s%-4s %-*s %-15s %-12s %-15s%s\n",
           ACCENT_BOLD, "POS", SHORT_TEXT_LENGTH, "TEAM", "RACE TIME", "PENALTY", "TOTAL TIME", RESET);
    printf("------------------------------------------------------------------------------\n");

    int rank = 1;
    for (int i = 0; i < MAX_TEAMS; i++) {
        if (teams[i] == NULL || TeamIsValid(teams[i]) == false) continue;

        bool isPlayerTeam = (teams[i] == &session->Teams[PLAYER_TEAM_INDEX]);
        float totalSeconds = (float)teams[i]->TimeRace + teams[i]->TimePenalty;

        Timespan tsRace, tsTotal;
        TsFromSeconds((float)teams[i]->TimeRace, &tsRace);
        TsFromSeconds(totalSeconds, &tsTotal);

        const char* rowColor = isPlayerTeam ? ACCENT_TEXT : "";
        const char* endColor = isPlayerTeam ? RESET : "";

        printf("%s%2d.  %-*s %02d:%02d          +%6.2fs      %02d:%02d%s\n",
               rowColor,
               rank,
               SHORT_TEXT_LENGTH, teams[i]->TeamName,
               tsRace.Minutes, tsRace.Seconds,
               teams[i]->TimePenalty,
               tsTotal.Minutes, tsTotal.Seconds,
               endColor);

        rank++;
    }

    printf("\n");
    free(teams);
    return true;
}

StatusCode GsStartGameLoop(GameSession *session) {
    if (session == NULL) {
        return STATUS_GAME_UNINITIALIZED;
    }

    return STATUS_OK;
}

int GsGenerateData(GameSession* session)
{
    if (session == NULL) {
        return STATUS_GAME_UNINITIALIZED;
    }

    const char* locations[] = {
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

    const char* teamNames[] = {
        "Red Bull Desert Wings", "Monster Energy Honda", "Toyota Gazoo Racing",
        "Kamal Dakar Team", "Bahrain Raid Xtreme", "Audi Sport",
        "Czech Buggyra Academy", "Fantic Rally Team", "Sherco Factory", "KTM Factory"
    };

    // generate other teams than the player's
    for (int i = 0; i < MAX_TEAMS; i++) {
        if (i > 9)
        {
            TeamInit(&session->Teams[i], "Team");
            continue;
        }

        if (i > PLAYER_TEAM_INDEX)
        {
            TeamInit(&session->Teams[i], teamNames[i]);
            session->Teams[i].Id = min(i, time(NULL));
            session->Teams[i].TimeRace = 0;
            session->Teams[i].TimePenalty = 0;
            snprintf(session->Teams[i].TeamName, SHORT_TEXT_LENGTH, teamNames[i]);

            VehicleInit(&session->Teams[i].Vehicles[0]);
            session->Teams[i].Vehicles[0] = (VehicleInfo){
                .Drivers = {"Driver A", "Co-Driver B", "Mechanic C", "", ""},
                .Time = 0,
                .Penalty = 0,
                .Health = HEALTH_MAX
            };
        }
        
        // fabricate race times for testing purposes
        // session->Teams[i].TimeTotal = rand() % 100;
    }

    return STATUS_OK;
}

int GsStartRace(GameSession *session)
{
    if (session == NULL) {
        return STATUS_GAME_UNINITIALIZED;
    }

    float stageLength = session->Stages[session->StageIndex].Distance;

    for (int i = 0; i < MAX_TEAMS; i++) {
        unsigned long int baseTime = (unsigned long int)((stageLength / RACE_AVG_PACE) * 3600.0f);
        long int deviation = (rand() % (2 * RACE_AVG_DEVIATION + 1)) - RACE_AVG_DEVIATION;
        long int totalStageTime = (long int)baseTime + deviation;
        if (totalStageTime < 0) totalStageTime = (long int)baseTime;
        session->Teams[i].TimeRace += (unsigned long int)totalStageTime;
        if (totalStageTime % 2 == 0) {
            float penalty = (float)(rand() % 95 + 5);
            TeamAddPenalty(&session->Teams[i], penalty);
        }
    }
    return STATUS_OK;
}

#pragma endregion