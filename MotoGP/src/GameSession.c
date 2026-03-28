//
// Created by jan on 21/03/2026.
//

#include "../inc/GameSession.h"
#include "../inc/UI/Ansi.h"
#include "../inc/Scoreboard.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

#include "../inc/UI/Screens.h"

#pragma region Globals

DriverInfo gDrivers[DRIVER_COUNT] = {
    (DriverInfo) {
        .Number = 5,
        .Country = COUNTRY_FRANCE,
        .IdxTeam = TEAM_LCR_HONDA,
        .Name = "Johann Zarco"
    },

    (DriverInfo) {
        .Number = 7,
        .Country = COUNTRY_TURKEY,
        .IdxTeam = TEAM_PRIMA_PRAMAC,
        .Name = "Toprak Razgatlioglu"
    },

    (DriverInfo) {
        .Number = 10,
        .Country = COUNTRY_ITALY,
        .IdxTeam = TEAM_HONDA_HRC,
        .Name = "Luca Marini"
    },

    (DriverInfo) {
        .Number = 11,
        .Country = COUNTRY_BRAZIL,
        .IdxTeam = TEAM_LCR_HONDA,
        .Name = "Diogo Moreira"
    },

    (DriverInfo) {
        .Number = 12,
        .Country = COUNTRY_SPAIN,
        .IdxTeam = TEAM_RED_BULL_TECH3,
        .Name = "Maverick Vinales"
    },

    (DriverInfo) {
        .Number = 20,
        .Country = COUNTRY_FRANCE,
        .IdxTeam = TEAM_MONSTER_ENERGY,
        .Name = "Fabio Quartararo"
    },

    (DriverInfo) {
        .Number = 21,
        .Country = COUNTRY_ITALY,
        .IdxTeam = TEAM_PERTAMINA_ENDURO,
        .Name = "Franco Morbidelli"
    },

    (DriverInfo) {
        .Number = 23,
        .Country = COUNTRY_ITALY,
        .IdxTeam = TEAM_RED_BULL_TECH3,
        .Name = "Enea Bastianini"
    },

    (DriverInfo) {
        .Number = 25,
        .Country = COUNTRY_SPAIN,
        .IdxTeam = TEAM_TRACKHOUSE,
        .Name = "Raul Fernandez"
    },

    (DriverInfo) {
        .Number = 33,
        .Country = COUNTRY_SOUTH_AFRICA,
        .IdxTeam = TEAM_RED_BULL_FACTORY,
        .Name = "Brad Binder"
    },

    (DriverInfo) {
        .Number = 36,
        .Country = COUNTRY_SPAIN,
        .IdxTeam = TEAM_HONDA_HRC,
        .Name = "Joan Mir"
    },

    (DriverInfo) {
        .Number = 37,
        .Country = COUNTRY_SPAIN,
        .IdxTeam = TEAM_RED_BULL_FACTORY,
        .Name = "Pedro Acosta"
    },

    (DriverInfo) {
        .Number = 42,
        .Country = COUNTRY_SPAIN,
        .IdxTeam = TEAM_MONSTER_ENERGY,
        .Name = "Alex Rins"
    },

    (DriverInfo) {
        .Number = 43,
        .Country = COUNTRY_OTHER,
        .IdxTeam = TEAM_PRIMA_PRAMAC,
        .Name = "Jack Miller"
    },

    (DriverInfo) {
        .Number = 49,
        .Country = COUNTRY_ITALY,
        .IdxTeam = TEAM_PERTAMINA_ENDURO,
        .Name = "Fabio Di Giannantonio"
    },

    (DriverInfo) {
        .Number = 54,
        .Country = COUNTRY_SPAIN,
        .IdxTeam = TEAM_GRESINI,
        .Name = "Fermin Alduguer"
    },

    (DriverInfo) {
        .Number = 63,
        .Country = COUNTRY_ITALY,
        .IdxTeam = TEAM_DUCATI_LENOVO,
        .Name = "Francesco Bagnaia"
    },

    (DriverInfo) {
        .Number = 72,
        .Country = COUNTRY_ITALY,
        .IdxTeam = TEAM_APRILIA,
        .Name = "Marco Bezzecchi"
    },

    (DriverInfo) {
        .Number = 73,
        .Country = COUNTRY_SPAIN,
        .IdxTeam = TEAM_GRESINI,
        .Name = "Alex Marquez"
    },

    (DriverInfo) {
        .Number = 79,
        .Country = COUNTRY_JAPAN,
        .IdxTeam = TEAM_TRACKHOUSE,
        .Name = "Ai Ogura"
    },

    (DriverInfo) {
        .Number = 89,
        .Country = COUNTRY_SPAIN,
        .IdxTeam = TEAM_APRILIA,
        .Name = "Jorgue Martin"
    },

    (DriverInfo) {
        .Number = 93,
        .Country = COUNTRY_SPAIN,
        .IdxTeam = TEAM_DUCATI_LENOVO,
        .Name = "Marc Marquez"
    }
};

TeamInfo gTeams[TEAM_COUNT] = {
    (TeamInfo) {
        .TeamId = TEAM_APRILIA,
        .Bike = BIKE_APRILIA,
        .Name = "Aprilia Racing"
    },

    (TeamInfo) {
        .TeamId = TEAM_GRESINI,
        .Bike = BIKE_DUCATI,
        .Name = "BK8 Gresini Racing MotoGP"
    },

    (TeamInfo) {
        .TeamId = TEAM_DUCATI_LENOVO,
        .Bike = BIKE_DUCATI,
        .Name = "Ducati Lenovo Team"
    },

    (TeamInfo) {
        .TeamId = TEAM_HONDA_HRC,
        .Bike = BIKE_HONDA,
        .Name = "Honda HRC Castrol"
    },

    (TeamInfo) {
        .TeamId = TEAM_LCR_HONDA,
        .Bike = BIKE_HONDA,
        .Name = "LCR Honda"
    },

    (TeamInfo) {
        .TeamId = TEAM_MONSTER_ENERGY,
        .Bike = BIKE_YAMAHA,
        .Name = "Monster Energy Yamaha MotoGP"
    },

    (TeamInfo) {
        .TeamId = TEAM_PERTAMINA_ENDURO,
        .Bike = BIKE_DUCATI,
        .Name = "Pertamina Enduro VR46 Racing Team"
    },

    (TeamInfo) {
        .TeamId = TEAM_PRIMA_PRAMAC,
        .Bike = BIKE_YAMAHA,
        .Name = "Prima Pramac Yamaha MotoGP"
    },

    (TeamInfo) {
        .TeamId = TEAM_RED_BULL_FACTORY,
        .Bike = BIKE_KTM,
        .Name = "Red Bull KTM Factory Racing"
    },

    (TeamInfo) {
        .TeamId = TEAM_RED_BULL_TECH3,
        .Bike = BIKE_KTM,
        .Name = "Red Bull KTM Tech3"
    },

    (TeamInfo) {
        .TeamId = TEAM_TRACKHOUSE,
        .Bike = BIKE_APRILIA,
        .Name = "Trackhouse MotoGP Team"
    }
};

TrackInfo gTracks[TRACK_COUNT] = {
    (TrackInfo) {
        .Id = 1,
        .Country = COUNTRY_THAILAND,
        .Name = "PT GRAND PRIX OF THAILAND",
        .Circuit = "Chang International Circuit"
    },

    (TrackInfo) {
        .Id = 2,
        .Country = COUNTRY_BRAZIL,
        .Name = "ESTRELLA GALICIA 0,0 GRAND PRIX OF BRAZIL",
        .Circuit = "Autódromo Internacional de Goiania"
    },

    (TrackInfo) {
        .Id = 3,
        .Country = COUNTRY_USA,
        .Name = "RED BULL GRAND PRIX OF THE UNITED STATES",
        .Circuit = "Circuit Of The Americas"
    },

    (TrackInfo) {
        .Id = 4,
        .Country = COUNTRY_SPAIN,
        .Name = "ESTRELLA GALICIA 0,0 GRAND PRIX OF SPAIN",
        .Circuit = "Circuito de Jerez"
    },

    (TrackInfo) {
        .Id = 5,
        .Country = COUNTRY_FRANCE,
        .Name = "MICHELIN(R) GRAND PRIX OF FRANCE",
        .Circuit = "Le Mans"
    },

    (TrackInfo) {
        .Id = 6,
        .Country = COUNTRY_CATALONIA,
        .Name = "MONSTER ENERGY GRAND PRIX OF CATALUNYA",
        .Circuit = "Circuit de Barcelona"
    },

    (TrackInfo) {
        .Id = 7,
        .Country = COUNTRY_ITALY,
        .Name = "BREMBO GRAND PRIX OF ITALY",
        .Circuit = "Autodromo Internazionale del Mugello"
    },

    (TrackInfo) {
        .Id = 8,
        .Country = COUNTRY_HUNGARY,
        .Name = "GRAND PRIX OF HUNGARY",
        .Circuit = "Balaton Park"
    },

    (TrackInfo) {
        .Id = 9,
        .Country = COUNTRY_CZECHIA,
        .Name = "GRAND PRIX OF CZECHIA",
        .Circuit = "Automotodrom Brno"
    },

    (TrackInfo) {
        .Id = 10,
        .Country = COUNTRY_NETHERLANDS,
        .Name = "GRAND PRIX OF THE NETHERLANDS",
        .Circuit = "TT Circuit Assen"
    },

    (TrackInfo) {
        .Id = 11,
        .Country = COUNTRY_GERMANY,
        .Name = "LIQUI MOLY GRAND PRIX OF GERMANY",
        .Circuit = "Sachsenring"
    },

    (TrackInfo) {
        .Id = 12,
        .Country = COUNTRY_GREAT_BRITAIN,
        .Name = "QATAR AIRWAYS GRAND PRIX OF GREAT BRITAIN",
        .Circuit = "Silverstone Circuit"
    },

    (TrackInfo) {
        .Id = 13,
        .Country = COUNTRY_ARAGON,
        .Name = "GRAND PRIX OF ARAGON",
        .Circuit = "MotorLand Aragon"
    },

    (TrackInfo) {
        .Id = 14,
        .Country = COUNTRY_SAN_MARINO,
        .Name = "RED BULL GRAND PRIX OF SAN MARINO AND THE RIMINI RIVIERA",
        .Circuit = "Misano World Circuit Marco Simoncelli"
    },

    (TrackInfo) {
        .Id = 15,
        .Country = COUNTRY_AUSTRIA,
        .Name = "GRAND PRIX OF AUSTRIA",
        .Circuit = "Red Bull Ring"
    },

    (TrackInfo) {
        .Id = 16,
        .Country = COUNTRY_JAPAN,
        .Name = "MOTUL GRAND PRIX OF JAPAN",
        .Circuit = "Mobility Resort Motegi"
    },

    (TrackInfo) {
        .Id = 17,
        .Country = COUNTRY_INDONESIA,
        .Name = "PERTAMINA GRAND PRIX OF INDONESIA",
        .Circuit = "Pertamina Mandalika International Circuit"
    },

    (TrackInfo) {
        .Id = 18,
        .Country = COUNTRY_AUSTRALIA,
        .Name = "GRAND PRIX OF AUSTRALIA",
        .Circuit = "Phillip Island"
    },

    (TrackInfo) {
        .Id = 19,
        .Country = COUNTRY_MALAYSIA,
        .Name = "PETRONAS GRAND PRIX OF MALAYSIA",
        .Circuit = "Petronas Sepang International Circuit"
    },

    (TrackInfo) {
        .Id = 20,
        .Country = COUNTRY_QATAR,
        .Name = "QATAR AIRWAYS GRAND PRIX OF QATAR",
        .Circuit = "Lusail International Circuit"
    },

    (TrackInfo) {
        .Id = 21,
        .Country = COUNTRY_PORTUGAL,
        .Name = "REPSOL GRAND PRIX OF PORTUGAL",
        .Circuit = "Autódromo Internacional do Algarve"
    },

    (TrackInfo) {
        .Id = 22,
        .Country = COUNTRY_VALENCIA,
        .Name = "MOTUL GRAND PRIX OF VALENCIA",
        .Circuit = "Circuit Ricardo Tormo"
    }
};

#pragma endregion

GameSession* GsInit() {
    // calloc - we want to initialize the memory with zeros
    GameSession *session = calloc(1, sizeof(GameSession));
    if (session == NULL) {
        return NULL;
    }
    return session;
}

STATUS GsFree(GameSession *session) {
    if (session == NULL) {
        return STATUS_UNINITIALIZED;
    }

    free(session);
    return STATUS_OK;
}

STATUS GsLoad(GameSession *session) {
    if (session == NULL) {
        return STATUS_UNINITIALIZED;
    }

    FILE* f = fopen(SAVEGAME, "rb");
    if (f == NULL) {
        return STATUS_ERROR;
    }

    fread(session, sizeof(GameSession), 1, f);
    fclose(f);
    return STATUS_OK;
}

STATUS GsSave(const GameSession *session) {
    if (session == NULL) {
        return STATUS_UNINITIALIZED;
    }

    FILE* f = fopen(SAVEGAME, "wb");
    if (f == NULL) {
        return STATUS_ERROR;
    }

    fwrite(session, sizeof(GameSession), 1, f);
    fclose(f);

    return GsPrintAsMarkdown(session);
}

BOOL GsCupInProgress(const GameSession *session) {
    // [1, TRACK_COUNT - 1] => in progress, otherwise not
    return (session->CupIdx > 0 && session->CupIdx < TRACK_COUNT) ? TRUE : FALSE;
}

STATUS GsDisplayData(void) {
    printf("%s--- DRIVERS ---%s\n", BOLD, RESET);
    for (int i = 0; i < DRIVER_COUNT; i++) {
        printf("%02d: #%02d: %s%s%s (%s)\n", i+1, gDrivers[i].Number, ACCENT_TEXT, gDrivers[i].Name, RESET, gTeams[gDrivers[i].IdxTeam].Name);
    }

    printf("\n%s--- TEAMS ---%s\n", BOLD, RESET);
    for (int i = 0; i < TEAM_COUNT; i++) {
        printf("%02d: %s%-*s%s (%d)\n", i+1, ACCENT_TEXT, DRIVER_COUNT, gTeams[i].Name, RESET, gTeams[i].Bike);
    }

    printf("\n%s--- TRACKS ---%s\n", BOLD, RESET);
    for (int i = 0; i < TRACK_COUNT; i++) {
        printf("%02d: %s%s%s (%s)\n", i+1, ACCENT_TEXT, gTracks[i].Name, RESET, gTracks[i].Circuit);
    }

    return STATUS_OK;
}

int comp_score(const void *a, const void *b) {
    RaceResult *r1 = (RaceResult*)a;
    RaceResult *r2 = (RaceResult*)b;

    if (r1->Pts > r2->Pts) return -1;
    else if (r1->Pts < r2->Pts) return 1;
    else return 0;
}

STATUS GsDisplayScoreboard(const GameSession *session) {
    if (session == NULL) {
        return STATUS_UNINITIALIZED;
    }

    // sort the leaderboard by points
    const int cupIdx = max(0, session->CupIdx-1);

    qsort((void*)session->Standings.Riders[cupIdx], DRIVER_COUNT, sizeof(RaceResult), comp_score);

    ClearScreen();
    printf("%s%-*s %-*s%s\n", ACCENT_BOLD, TEXT_LENGTH, "Name", 10, "Points", RESET);
    for (int j = 0; j < DRIVER_COUNT; j++) {
        // print rider's score
        const RaceResult rr = session->Standings.Riders[cupIdx][j];
        printf("%-*s %6d\n", TEXT_LENGTH, gDrivers[rr.EntityId].Name, rr.Pts);
    }

    return STATUS_OK;
}

int GsGetPoints(const GameSession *session, const int driverIdx) {
    if (session == NULL) {
        return -1;
    }

    if (driverIdx < 0 || driverIdx >= DRIVER_COUNT) {
        return -1;
    }

    int count = 0;
    for (int i = 0; i < TRACK_COUNT; i++) {
        const int pts = session->Standings.Riders[i][driverIdx].Pts;
        if (pts < 0 || pts > 10) {
            // must be in range 0-10
            continue;
        }

        // adjust points
        count += pts;
    }

    return count;
}

STATUS GsRace(GameSession *session) {
    if (session == NULL) {
        return STATUS_UNINITIALIZED;
    }

    if (session->CupIdx < 0 || session->CupIdx >= TRACK_COUNT) {
        return STATUS_ERROR;
    }

    int pts[DRIVER_COUNT];

    for (int x = 0; x < DRIVER_COUNT; x++) {
        pts[x] = (x < 10) ? (10 - x) : 1;
    }

    for (int x = DRIVER_COUNT - 1; x > 0; x--) {
        int other = rand() % (x + 1);
        int temp = pts[x];
        pts[x] = pts[other];
        pts[other] = temp;
    }

    for (int i = 0; i < DRIVER_COUNT; i++) {
        session->Standings.Riders[session->CupIdx][i] = (RaceResult) {
            .EntityId = i,
            .Pts = pts[i]
        };
    }

    session->CupIdx++;

    if (session->CupIdx == TRACK_COUNT) {
        const STATUS result = GsFinalResults(session);
        session->CupIdx = 0;
        memset(&session->Standings, 0, sizeof(Scoreboard));

        return result;
    }

    return STATUS_OK;
}

STATUS GsFinalResults(const GameSession *session) {
    RaceResult results[DRIVER_COUNT];
    for (int i = 0; i < DRIVER_COUNT; i++) {
        results[i].EntityId = i;
        results[i].Pts = GsGetPoints(session, i);
    }

    qsort((void*)results, DRIVER_COUNT, sizeof(RaceResult), comp_score);
    ClearScreen();
    printf("%s%-*s %-10s%s\n", ACCENT_BOLD, TEXT_LENGTH, "Name", "Points", RESET);

    for (int i = 0; i < DRIVER_COUNT; i++) {
        int driverId = results[i].EntityId;
        int points = results[i].Pts;

        if (driverId == session->PlayerIdx) {
            printf("%s%-*s %6d%s\n",
                   ACCENT_TEXT, TEXT_LENGTH, gDrivers[driverId].Name, points, RESET);
        }
        else {
            printf("%-*s %6d\n", TEXT_LENGTH, gDrivers[driverId].Name, points);
        }
    }

    ScrPause();
    return STATUS_OK;
}

int GsPrintAsMarkdown(const GameSession *session) {
    if (session == NULL) {
        return STATUS_UNINITIALIZED;
    }

    FILE *file = fopen("game_state.md", "w");
    if (file == NULL) {
        fprintf(stderr, "Unable to open game_state.md\n");
        return STATUS_ERROR;
    }

    // print the header
    fprintf(file, "# Game Session dump\n");

    // print working data - global drivers, tracks, etc
    fprintf(file, "## Game data\n");

    // teams
    fprintf(file, "### Teams\n");

    fprintf(file, "|Id|Name|\n");
    fprintf(file, "|--|----|\n");
    for (int i = 0; i < TEAM_COUNT; i++) {
        fprintf(file, "|%d|%s|\n", gTeams[i].TeamId, gTeams[i].Name);
    }

    fprintf(file, "\n");

    // print drivers
    fprintf(file, "### Riders\n");
    fprintf(file, "|Id|Name|Number|Team|\n");
    fprintf(file, "|--|----|------|----|\n");
    for (int i = 0; i < DRIVER_COUNT; i++) {
        fprintf(file, "|%d|%s|%d|%s|\n", i, gDrivers[i].Name, gDrivers[i].Number, gTeams[gDrivers[i].IdxTeam].Name);
    }

    fprintf(file, "\n");

    // tracks
    fprintf(file, "### Tracks\n");

    fprintf(file, "|Id|Country|Name|Circuit|\n");
    fprintf(file, "|--|-------|----|-------|\n");

    for (int i = 0; i < TRACK_COUNT; i++) {
        fprintf(file, "|%d|%s|%s|%s|\n", gTracks[i].Id, CoGetCountryName(gTracks[i].Country), gTracks[i].Name, gTracks[i].Circuit);
    }

    fprintf(file, "\n---\n\n");

    fprintf(file, "## Scoreboard\n");

    for (int i = 0; i < TRACK_COUNT; i++) {
        // print active track
        fprintf(file, "### Track %d/%d\n", i+1, TRACK_COUNT);

        fprintf(file, "|Id|Name|Points|\n");
        fprintf(file, "|--|----|------|\n");

        for (int j = 0; j < DRIVER_COUNT; j++) {
            // print driver's stat
            fprintf(file, "|%d|%s|%d|\n", session->Standings.Riders[i][j].EntityId, gDrivers[j].Name, session->Standings.Riders[i][j].Pts);
        }

        fprintf(file, "\n");
    }

    fclose(file);
    return STATUS_OK;
}