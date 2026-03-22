//
// Created by jan on 21/03/2026.
//

#include "../inc/GameSession.h"

DriverInfo gDrivers[DRIVER_COUNT] = {
    (DriverInfo) {
        .Number = 5,
        .Country = FRANCE,
        .IdxBike = 0,
        .IdxTeam = TEAM_LCR_HONDA,
        .Name = "Johann Zarco"
    },

    (DriverInfo) {
        .Number = 7,
        .Country = TURKEY,
        .IdxBike = 0,
        .IdxTeam = TEAM_PRIMA_PRAMAC,
        .Name = "Toprak Razgatlioglu"
    },

    (DriverInfo) {
        .Number = 10,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = TEAM_HONDA_HRC,
        .Name = "Luca Marini"
    },

    (DriverInfo) {
        .Number = 11,
        .Country = BRAZIL,
        .IdxBike = 0,
        .IdxTeam = TEAM_LCR_HONDA,
        .Name = "Diogo Moreira"
    },

    (DriverInfo) {
        .Number = 12,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = TEAM_RED_BULL_TECH3,
        .Name = "Maverick Vinales"
    },

    (DriverInfo) {
        .Number = 20,
        .Country = FRANCE,
        .IdxBike = 0,
        .IdxTeam = TEAM_MONSTER_ENERGY,
        .Name = "Fabio Quartararo"
    },

    (DriverInfo) {
        .Number = 21,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = TEAM_PERTAMINA_ENDURO,
        .Name = "Franco Morbidelli"
    },

    (DriverInfo) {
        .Number = 23,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = TEAM_RED_BULL_TECH3,
        .Name = "Enea Bastianini"
    },

    (DriverInfo) {
        .Number = 25,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = TEAM_TRACKHOUSE,
        .Name = "Raul Fernandez"
    },

    (DriverInfo) {
        .Number = 33,
        .Country = SOUTH_AFRICA,
        .IdxBike = 0,
        .IdxTeam = TEAM_RED_BULL_FACTORY,
        .Name = "Brad Binder"
    },

    (DriverInfo) {
        .Number = 36,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = TEAM_HONDA_HRC,
        .Name = "Joan Mir"
    },

    (DriverInfo) {
        .Number = 37,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = TEAM_RED_BULL_FACTORY,
        .Name = "Pedro Acosta"
    },

    (DriverInfo) {
        .Number = 42,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = TEAM_MONSTER_ENERGY,
        .Name = "Alex Rins"
    },

    (DriverInfo) {
        .Number = 43,
        .Country = OTHER,
        .IdxBike = 0,
        .IdxTeam = TEAM_PRIMA_PRAMAC,
        .Name = "Jack Miller"
    },

    (DriverInfo) {
        .Number = 49,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = TEAM_PERTAMINA_ENDURO,
        .Name = "Fabio Di Giannantonio"
    },

    (DriverInfo) {
        .Number = 54,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = TEAM_GRESINI,
        .Name = "Fermin Alduguer"
    },

    (DriverInfo) {
        .Number = 63,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = TEAM_DUCATI_LENOVO,
        .Name = "Francesco Bagnaia"
    },

    (DriverInfo) {
        .Number = 72,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = TEAM_APRILIA,
        .Name = "Marco Bezzecchi"
    },

    (DriverInfo) {
        .Number = 73,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = TEAM_GRESINI,
        .Name = "Alex Marquez"
    },

    (DriverInfo) {
        .Number = 79,
        .Country = JAPAN,
        .IdxBike = 0,
        .IdxTeam = TEAM_TRACKHOUSE,
        .Name = "Ai Ogura"
    },

    (DriverInfo) {
        .Number = 89,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = TEAM_APRILIA,
        .Name = "Jorgue Martin"
    },

    (DriverInfo) {
        .Number = 93,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = TEAM_DUCATI_LENOVO,
        .Name = "Marc Marquez"
    }
};

TeamInfo gTeams[DRIVER_COUNT] = {
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