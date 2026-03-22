//
// Created by jan on 21/03/2026.
//

#include "../inc/GameSession.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        .Country = COUNTRY_QUATAR,
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
    return STATUS_OK;
}

BOOL GsCupInProgress(const GameSession *session) {
    // [1, TRACK_COUNT - 1] => in progress, otherwise not
    return (session->CupIdx > 0 && session->CupIdx < TRACK_COUNT) ? TRUE : FALSE;
}