/*
* UIActions.h
* Contains various performable UI actions.
*/

#pragma once
#include <stdio.h>
#include <string.h>
#include "GameSession.h"
#include "Ansi.h"

/// <summary>
/// Representing possible return values for the game loop function.
/// </summary>
enum GAME_RESULT : unsigned char
{
	GAME_OK = 0,
	GAME_ERROR
};

/// <summary>
/// Clears the terminal screen (not the buffer).
/// </summary>
/// <remarks>
/// This method clears the terminal screen and moves the cursor to the home position using the ANSI escape codes.
/// </remarks>
static void UiClearScreen(void) {
	AnsiClearScreen();
}

/// <summary>
/// Attempts to update the player name.
/// </summary>
/// <param name="session">Active game session.</param>
/// <returns>true if the update is successful, otherwise false.</returns>
static bool UiUpdatePlayerName(GameSession* session)
{
	if (session == NULL)
	{
		// session is unavailable
		return false;
	}

	char playerName[MAX_NAME];
	printf(INPUT_PLAYER_NAME);
	if (fgets(playerName, MAX_NAME, stdin) == NULL)
	{
		// Unable to get new player name
		return false;
	}

	// remove the trailing line feed character
	playerName[strlen(playerName) - 1] = 0;

	if (strlen(playerName) == 0)
	{
		// name must not be empty
		return false;
	}

	// update the player name
	strcpy(session->player.name, playerName);
	return true;
}

/// <summary>
/// Flushes the input buffer.
/// </summary>
static void UiFlushInputBuffer(void) {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {}
}

static void UiPauseTerminal(void) {
	printf(INPUT_PAUSE);
	getchar();
	UiFlushInputBuffer();
}

static int UiGetInteger(const char *inputPrompt) {
	int result = EOF;
	printf("%s", inputPrompt);
	const int sfResult = scanf("%d", &result);
	switch (sfResult) {
		case EOF:
		case 0:
			UiFlushInputBuffer();
			return EOF;

		default:
			return result;
	}
}

#pragma region "Player's action methods"
static bool UiViewDashboard(GameSession* session) {
	// TODO use a better display method
	return GsDisplayStatus(session);
}

static bool UiBuyStocks(GameSession* session) {
	// FIXME add implementation
	printf("Buy Stocks\n");
	return false;
}

static bool UiSellStocks(GameSession* session) {
	// FIXME add implementation
	printf("Sell Stocks\n");
	return false;
}

static bool UiViewTrends(GameSession* session) {
	// FIXME add implementation
	printf("View Trends\n");
	return false;
}

static bool UiExecuteActions(GameSession* session) {
	// FIXME add implementation
	printf("Execute Actions\n");
	return false;
}

#pragma endregion "Player's action methods"

/// <summary>
/// Starts the game loop and handles the lifetime of it until the game state is not STATUS_RUNNING.
/// </summary>
/// <param name="session">The game session to use.</param>
/// <returns>
/// Game loop exit code. If the game ended the normal way, GAME_OK is returned. If an error occurs, GAME_ERROR is returned.
/// Any other invalid states are defined by the <see cref="GAME_RESULT"/> enum.
/// </returns>
/// <remarks>
/// This method sets the <paramref name="session"/>'s state to STATE_RUNNING and keeps looping until the state is change to any other value.
/// </remarks>
static unsigned char UiGameLoop(GameSession *session) {
	if (session == NULL)
		return GAME_ERROR;

	// set the game session state to running
	session->gameState = STATE_RUNNING;

	// THE main game loop
	while (session->gameState == STATE_RUNNING) {

		/*
		 *	1. List player's options
		 *	2. Get player's inputs (can be multiple actions per day)
		 *	3. Process player's inputs
		 *	4. When all actions are taken, process the day and evaluate the results
		 *		- Update the global state of assets like stocks, money, day counter
		 *		- Display a day summary
		 *	5. Start anew
		 */

		//	1. List player's options
		bool userInputs = true;
		while (userInputs == true) {
			UiClearScreen();
			printf("---------------------------\n");
			printf("1. View Dashboard\n");
			printf("2. Buy Stocks\n");
			printf("3. Sell Stocks\n");
			printf("4. View Trends\n");
			printf("5. Execute Actions\n");
			printf("---------------------------\n");
			printf("0. Quit\n\n");

			//	2. Get player's inputs
			int option = UiGetInteger(INPUT_GAME_ACTION);
			if (option == EOF) {
				printf("Only integers are allowed.\n");
				continue;
			}

			switch (option) {
				case 0:
					// exit the game loop option
					userInputs = false;
					session->gameState = STATE_ENDED;
					break;

				case 1:
					// View Dashboard option
					if (UiViewDashboard(session) == false) {
						// TODO handle error
					}

					printf("\n");
					UiPauseTerminal();

					break;

				case 2:
					// Buy Stocks option
					if (UiBuyStocks(session) == false) {
						// TODO handle error

					}

					printf("\n");
					UiPauseTerminal();

					break;

				case 3:
					// Sell Stocks option
					if (UiSellStocks(session) == false) {
						// TODO handle error
					}

					printf("\n");
					UiPauseTerminal();
					break;

				case 4:
					// View Trends option
					if (UiViewTrends(session) == false) {
						// TODO handle error
					}

					printf("\n");
					UiPauseTerminal();
					break;

				case 5:
					// Execute Actions options
					userInputs = false;
					if (UiExecuteActions(session) == false) {
						// unable to continue - error or player reached a point of no return
						// exit is the valid
						session->gameState = STATE_ENDED;
					}
					break;

				default:
					// invalid option
					printf(OUTPUT_INVALID_OPTION);
					break;
			}
		}

		//	3. TODO Process player's inputs (process changes)

		//	4. TODO Evaluate the results
	}

	return GAME_OK;
}