/*
* Source.c
* Main application entry point.
*/

#pragma once
#include <stdio.h>
#include <string.h>
#include "inc/GameSession.h"

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1

/// <summary>
/// Attempts to update the player name.
/// </summary>
/// <param name="session">Active game session.</param>
/// <returns>true if the update is successful, otherwise false.</returns>
static inline bool UpdatePlayerName(GameSession *session)
{
	if (session == NULL)
	{
		// session is unavailable
		return false;
	}

	char playerName[MAX_NAME];
	printf_s(INPUT_PLAYER_NAME);
	if (fgets(playerName, MAX_NAME, stdin) == NULL)
	{
		// Unable to get new player name
		return false;
	}

	// remove the trailing line feed character
	playerName[strnlen_s(playerName, MAX_NAME) - 1] = 0;

	// update the player name
	strcpy_s(session->player.name, MAX_NAME, playerName);
	return true;
}

int main(int argc, const char* argv[])
{
	if (argc > 1)
	{
		// arguments are disabled
		fprintf_s(stderr, "Arguments are disabled.\n");
		return EXIT_FAILURE;
	}

	// print the header
	printf_s("StockTrader\n(c) 2026, Jan Hruza\n\n");

	// initialize the session
	GameSession gs;
	if (GsInitialize(&gs) == false)
	{
		fprintf_s(stderr, "Unable to initialize the game session.\n");
		return EXIT_FAILURE;
	}

	// get the player name
	if (UpdatePlayerName(&gs) == false)
	{
		fprintf_s(stderr, "Unable to get the player name.\n");
		return EXIT_FAILURE;
	}

	printf_s("\n");
	GsDisplayStatus(&gs);

	// successful exit
	return EXIT_SUCCESS;
}