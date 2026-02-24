/*
* Source.c
* Main application entry point.
*/

#pragma once
#include "inc/GameSession.h"
#include "inc/UIActions.h"
#include <stdio.h>

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1

/**
 * Main application entry point.
 * @param argc Number of command line arguments.
 * @param argv Command line arguments.
 * @return Application's exit code.
 */
int main(const int argc, const char* argv[])
{
	if (argc > 1)
	{
		// arguments are disabled
		fprintf(stderr, "Arguments are disabled.\n");
		return EXIT_FAILURE;
	}

	// print the header
	printf("StockTrader\n(c) 2026, Jan Hruza\n\n");

	// initialize the session
	GameSession gs;
	if (GsInitialize(&gs) == false)
	{
		fprintf(stderr, "Unable to initialize the game session.\n");
		return EXIT_FAILURE;
	}

	// get the player name
	if (UiUpdatePlayerName(&gs) == false)
	{
		fprintf(stderr, "Unable to get the player name.\n");
		return EXIT_FAILURE;
	}

	// start the game session
	unsigned char statusCode = UiGameLoop(&gs);

	// TODO display the final result
	switch (statusCode)
	{
		case GAME_OK:
			printf("Game completed successfully!\n");
			break;

		case GAME_ERROR:
			fprintf(stderr, "Game error!\n");
			break;

		default:
			fprintf(stderr, "Unknown error!\n");
			break;
	}

	// TODO post-exit cleanup

	// successful exit
	return EXIT_SUCCESS;
}