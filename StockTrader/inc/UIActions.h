/*
* UIActions.h
* Contains various performable UI actions.
*/

#pragma once
#include <stdio.h>
#include <string.h>
#include "GameSession.h"

/// <summary>
/// Attempts to update the player name.
/// </summary>
/// <param name="session">Active game session.</param>
/// <returns>true if the update is successful, otherwise false.</returns>
static inline bool UpdatePlayerName(GameSession* session)
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

	if (strnlen_s(playerName, MAX_NAME) == 0)
	{
		// name must not be empty
		return false;
	}

	// update the player name
	strcpy_s(session->player.name, MAX_NAME, playerName);
	return true;
}