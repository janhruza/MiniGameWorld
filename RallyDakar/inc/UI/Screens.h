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

int ScrShowError(const char* msg);
int ScrShowMessage(const char* msg);

/*
* Vehicle and teams initialization screens
*/
#pragma region Teams and vehicles

int ScrCreateTeam(TeamInfo* team);
int ScrCreateVehicle(VehicleInfo* vehicle);

#pragma endregion

int ScrWelcome(GameSession* session);
int ScrMainMenu(GameSession* session);
int ScrContinueCup(GameSession* session);

#endif