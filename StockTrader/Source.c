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

int main(int argc, const char* argv[])
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
	if (UpdatePlayerName(&gs) == false)
	{
		fprintf(stderr, "Unable to get the player name.\n");
		return EXIT_FAILURE;
	}

	printf("\n");
	GsDisplayStatus(&gs);
	printf("\n");

	GsUpdateStockValues();
	GsDisplayStatus(&gs);

	// successful exit
	return EXIT_SUCCESS;
}