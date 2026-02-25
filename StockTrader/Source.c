/*
* Source.c
* Main application entry point.
*/

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

	UiClearScreen();

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

	PlayerSetMoney(&gs.player, 1000000);

	// start the game session
	unsigned char statusCode = UiGameLoop(&gs);
	UiClearScreen();

	// display the final result
	switch (statusCode)
	{
		case GAME_OK:
			printf("\nYou progressed through %d days!\n\nGame completed successfully!\n", gs.day);
			break;

		case GAME_ERROR:
			fprintf(stderr, "Game error!\n");
			break;

		default:
			fprintf(stderr, "Unknown error!\n");
			break;
	}

	// TODO post-exit cleanup
	printf(CRESET);

	// successful exit
	return EXIT_SUCCESS;
}