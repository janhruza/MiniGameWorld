/*
* GameSession.h
* Representing the game session struct and other associated methods.
*/

#pragma once
#include "data/GlobalData.h"
#include "data/Player.h"
#include "data/Stock.h"
#include "Values.h"
#include <memory.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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

	srand(time(NULL));

	// clear the game session object
	memset(session, 0, sizeof(GameSession));

	// set the available stocks
	for (int i = 0; i < MAX_STOCK_SIZE; i++)
	{
		CreateStock(g_stockNames[i], g_stockCodes[i], g_stockValues[i], &session->stocks[i]);
	}

	return true;
}

/// <summary>
/// Displays the current game state.
/// </summary>
/// <param name="session">The active game session.</param>
/// <returns>true if the operation succeeds, otherwise false.</returns>
inline static bool GsDisplayStatus(GameSession *session)
{
	// check if the session exists
	if (session == NULL) return false;

	// print the player status
	printf_s("%s's stats:\nMoney : %.2lf USD\nStocks: %d\n\n", session->player.name, session->player.money, StockValidCount(session->player.stocks, MAX_STOCK_SIZE));

	// print the session state
	printf_s("List of stocks:\n");
	for (int i = 0; i < MAX_STOCK_SIZE; i++)
	{
		if (StockIsValid(&session->stocks[i]) == false)
		{
			continue;
		}
		printf("%s - %-32s %.2lf\n", g_stockCodes[i], g_stockNames[i], g_stockValues[i]);
	}

	return true;
}

/// <summary>
/// Updates the global stock values.
/// </summary>
inline static void GsUpdateStockValues(void)
{
	for (int i = 0; i < MAX_STOCK_SIZE; i++)
	{
		double oldValue = g_stockValues[i];
		int det = rand() % 10 + 1;
		if (det % 2 == 0)
		{
			oldValue += det;
		}

		else
		{
			oldValue -= det;
		}

		g_stockValues[i] = max(oldValue, 0);
	}
	return;
}