/*
* GameSession.h
* Representing the game session struct and other associated methods.
*/

#pragma once
#include "data/GlobalData.h"
#include "data/Player.h"
#include "data/Stock.h"
#include "Values.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/// <summary>
/// Representing the game state enum.
/// </summary>
enum GAME_STATE : unsigned char
{
	STATE_RUNNING = 0,
	STATE_INITIALIZED,
	STATE_ENDED,
	STATE_ERROR
};

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

	/// <summary>
	/// Gets the current day (game progress).
	/// </summary>
	unsigned int day;

	/// <summary>
	/// Representing the game state.
	/// </summary>
	enum GAME_STATE gameState;

} GameSession;

/// <summary>
/// Initializes the game session object.
/// </summary>
/// <param name="session">Game session object.</param>
/// <returns>true if the function succeeds, otherwise false.</returns>
inline static bool GsInitialize(GameSession *session)
{
	// check if the session exists
	if (session == nullptr) return false;

	srand(time(nullptr));

	// clear the game session object
	memset(session, 0, sizeof(GameSession));

	// set tje first day
	session->day = 1;

	// set the available stocks
	for (int i = 0; i < MAX_STOCK_SIZE; i++)
	{
		CreateStock(g_stockNames[i], g_stockCodes[i], g_stockValues[i], &session->stocks[i]);
	}

	// initialize the game session (not the same as start)
	session->gameState = STATE_INITIALIZED;
	return true;
}

/// <summary>
/// Displays the current game state.
/// </summary>
/// <param name="session">The active game session.</param>
/// <returns>true if the operation succeeds, otherwise false.</returns>
inline static bool GsDisplayStatus(const GameSession *session)
{
	// check if the session exists
	if (session == nullptr) return false;

	// print the player status
	printf("%s's stats:\nMoney : %.2lf USD\nStocks: %d\n\n", session->player.name, session->player.money, StockValidCount((Stock**)session->player.stocks, MAX_STOCK_SIZE));

	// print the session state
	printf("List of stocks:\n");
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
///
/// </summary>
/// <param name="a">First value.</param>
/// <param name="b">Second value.</param>
/// <returns>The maximum of <paramref name="a"/> and <paramref name="b"/>.</returns>
/// <remarks>
/// Function created solely because of the CMake build that was unable to locate the standard max function.
/// </remarks>
static double local_max(const double a, const double b) {
	return (a > b) ? a : b;
}

#pragma region Daily balance

static double g_dailyBalance = 0;

static void GsSetDailyBalance(const double value) {
	g_dailyBalance = value;
}

static double GsGetDailyBalance(void) {
	return g_dailyBalance;
}

#pragma endregion

/// <summary>
/// Updates the global stock values using a percentage-based delta.
/// </summary>
/// <param name="values">Stock values.</param>
/// <param name="size">Number of stocks.</param>
/// <param name="volatilities">Array of stocks' volatilities.</param>
static void GsUpdateStockValuesEx(double values[], const int size, const double volatilities[])
{
	for (int i = 0; i < size; i++)
	{
		// 1. Generate a multiplier between -VOLATILITY and +VOLATILITY
		// (rand() / (double)RAND_MAX) gives 0.0 to 1.0
		double changePercent = ((rand() / (double)RAND_MAX) * (volatilities[i] * 2)) - volatilities[i];

		// 2. Apply the change: New = Old * (1 + change)
		values[i] *= (1.0 + changePercent);

		// 3. Simple floor: prevents stocks from becoming negative or "worthless"
		if (values[i] < 0.01)
		{
			values[i] = 0.01;
		}
	}
}

/// <summary>
/// Updates the global stock values.
/// </summary>
static void GsUpdateStockValues(void)
{
	GsUpdateStockValuesEx(g_stockValues, MAX_STOCK_SIZE, g_stockVolatilities);
}