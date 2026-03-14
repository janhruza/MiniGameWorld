/*
* Screens.h
* Game screens (pages).
* This header contains declarations for all in-game screens.
* These screens handle all inputs themselves - should be
* used as wrapper for lower-level functions.
*/

#ifndef RALLYDAKAR_SCREENS_H
#define RALLYDAKAR_SCREENS_H

#include "../GameSession.h"

/**
* @brief Helper function to pause the execution until any key is pressed.
*/
int ScrPause(void);

int ScrShowError(const char* msg);
int ScrShowMessage(const char* msg);

/*
* Vehicle and teams initialization screens
*/
#pragma region Teams and vehicles

/**
* @brief Representing the create team screen.
* @param team Pointer to the target team info object.
* @returns Operation result.
*/
int ScrCreateTeam(TeamInfo* team);

/**
* @brief Representing the vehicle creation screen.
* @param vehicle Pointer to the target vehicle info object.
* @returns Operation result.
*/
int ScrCreateVehicle(VehicleInfo* vehicle);

#pragma endregion

int ScrGarage(TeamInfo* team);

int ScrWelcome(GameSession* session);
int ScrMainMenu(GameSession* session);
int ScrContinueCup(GameSession* session);

int ScrStartRace(GameSession* session);
int ScrCupEnded(GameSession* session);
int ScrShowScoreboard(const GameSession* session);
int ScrServiceVehicles(GameSession* session);

#endif