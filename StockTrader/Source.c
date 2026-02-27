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

	// print the banner
	UiClearScreen();
	UiDisplayBanner();

	// initialize the session
	GameSession gs;
	if (GsInitialize(&gs) == false)
	{
		fprintf(stderr, "Unable to initialize the game session.\n");
		return EXIT_FAILURE;
	}

	// update the stock values upon startup
	// otherwise the initial state will be the same
	// for all program executions
	GsUpdateStockValues();

	// get the player name
	if (UiUpdatePlayerName(&gs) == false)
	{
		fprintf(stderr, "%sUnable to get the player name.%s\n", ERROR_TEXT, CRESET);
		return EXIT_FAILURE;
	}

	PlayerSetMoney(&gs.player, INITIAL_MONEY);

	// start the game session
	const unsigned char statusCode = UiGameLoop(&gs);
	UiClearScreen();
	UiDisplayBanner();

	// display the final result
	switch (statusCode)
	{
		case GAME_OK:
			printf("You progressed through %s%d%s days!\n\nGame completed successfully!\n", ACCENT_TEXT, gs.day, CRESET);
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