/*
* GameSession.h
* Representing the game session struct and other associated methods.
*/

#pragma once
#include "data/Player.h"
#include "data/Stock.h"
#include "Values.h"
#include <stdbool.h>
#include <memory.h>

/// <summary>
/// Representing the game session object.
/// This object contains information about the current session, e.g. which stocks are available and others.
/// </summary>
typedef struct
{
	/// <summary>
	/// Current player object.
	/// </summary>
	Player player;

	/// <summary>
	/// List of tradable stocks.
	/// </summary>
	Stock stocks[MAX_STOCK_SIZE];

} GameSession;

/// <summary>
/// Initializes the game session object.
/// </summary>
/// <param name="session">Game session object.</param>
/// <returns>true if the function succeeds, otherwise false.</returns>
inline static bool GsInitialize(GameSession *session)
{
	// check if the session exists
	if (session == NULL) return false;

	// clear the game session object
	memset(session, 0, sizeof(GameSession));
	return true;
}

inline static bool GsDisplayStatus(GameSession *session)
{
	// check if the session exists
	if (session == NULL) return false;

	// print the status
	printf_s("%s's stats:\nMoney : %.2lf USD\nStocks: %d\n", session->player.name, session->player.money, session->player.stockSize);
	return true;
}