//
// Created by jan on 21/03/2026.
//

#include "../inc/GameSession.h"

DriverInfo gDrivers[DRIVER_COUNT] = {
    (DriverInfo) {
        .Number = 5,
        .Country = FRANCE,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Johann Zarco"
    },

    (DriverInfo) {
        .Number = 7,
        .Country = TURKEY,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Toprak Razgatlioglu"
    },

    (DriverInfo) {
        .Number = 10,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Luca Marini"
    },

    (DriverInfo) {
        .Number = 11,
        .Country = BRAZIL,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Diogo Moreira"
    },

    (DriverInfo) {
        .Number = 12,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Maverick Vinales"
    },

    (DriverInfo) {
        .Number = 20,
        .Country = FRANCE,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Fabio Quartararo"
    },

    (DriverInfo) {
        .Number = 21,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Franco Morbidelli"
    },

    (DriverInfo) {
        .Number = 23,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Enea Bastianini"
    },

    (DriverInfo) {
        .Number = 25,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Raul Fernandez"
    },

    (DriverInfo) {
        .Number = 33,
        .Country = SOUTH_AFRICA,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Brad Binder"
    },

    (DriverInfo) {
        .Number = 36,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Joan Mir"
    },

    (DriverInfo) {
        .Number = 37,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Pedro Acosta"
    },

    (DriverInfo) {
        .Number = 42,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Alex Rins"
    },

    (DriverInfo) {
        .Number = 43,
        .Country = OTHER,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Jack Miller"
    },

    (DriverInfo) {
        .Number = 49,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Fabio Di Giannantonio"
    },

    (DriverInfo) {
        .Number = 54,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Fermin Alduguer"
    },

    (DriverInfo) {
        .Number = 63,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Francesco Bagnaia"
    },

    (DriverInfo) {
        .Number = 72,
        .Country = ITALY,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Marco Bezzecchi"
    },

    (DriverInfo) {
        .Number = 73,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Alex Marquez"
    },

    (DriverInfo) {
        .Number = 79,
        .Country = JAPAN,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Ai Ogura"
    },

    (DriverInfo) {
        .Number = 89,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Jorgue Martin"
    },

    (DriverInfo) {
        .Number = 93,
        .Country = SPAIN,
        .IdxBike = 0,
        .IdxTeam = 0,
        .Name = "Marc Marquez"
    }
};