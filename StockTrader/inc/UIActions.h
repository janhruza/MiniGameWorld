/*
* UIActions.h
* Contains various performable UI actions.
*/

#pragma once
#include <ctype.h>
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

static void UiDisplayBanner(void) {
	// printf("███████╗████████╗ ██████╗  ██████╗██╗  ██╗    ████████╗██████╗  █████╗ ██████╗ ███████╗██████╗\n");
	// printf("██╔════╝╚══██╔══╝██╔═══██╗██╔════╝██║ ██╔╝    ╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔══██╗\n");
	// printf("███████╗   ██║   ██║   ██║██║     █████╔╝        ██║   ██████╔╝███████║██║  ██║█████╗  ██████╔╝\n");
	// printf("╚════██║   ██║   ██║   ██║██║     ██╔═██╗        ██║   ██╔══██╗██╔══██║██║  ██║██╔══╝  ██╔══██╗\n");
	// printf("███████║   ██║   ╚██████╔╝╚██████╗██║  ██╗       ██║   ██║  ██║██║  ██║██████╔╝███████╗██║  ██║\n");
	// printf("╚══════╝   ╚═╝    ╚═════╝  ╚═════╝╚═╝  ╚═╝       ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚══════╝╚═╝  ╚═╝\n");
	// printf("By %s@jendahruza%s\n\n", ACCENT_TEXT, CRESET);

	printf("Stock Trader\nMade by %s@jendahruza%s\n\n", ACCENT_BOLD, CRESET);
}

/// <summary>
/// Flushes the input buffer.
/// </summary>
static void UiFlushInputBuffer(void) {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF) {}
}

static bool UiReadString(const char *prompt, char *buf) {
	printf("%s", prompt);
	printf(ACCENT_TEXT);

	if (fgets(buf, MAX_NAME, stdin) == NULL) {
		printf(CRESET);
		return false;
	}
	printf(CRESET);

	if (strcmp(buf, "\n") == 0) {
		return false;
	}

	size_t len = strlen(buf);
	if (len <= 0) return false;

	if (buf[len - 1] == '\n')
	{
		buf[len - 1] = '\0';
	}

	else
	{
		UiFlushInputBuffer();
	}

	return true;
}

static long UiGetInteger(const char *inputPrompt) {
	char buf[MAX_NAME];
	if (!UiReadString(inputPrompt, buf)) return EOF;

	char *endptr;
	long num = strtol(buf, &endptr, 10);
	if (endptr == buf) return EOF;

	while (*endptr != '\0') {
		if (!isspace((unsigned char)*endptr)) return EOF;
		endptr++;
	}

	return num;
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
	if (UiReadString(INPUT_PLAYER_NAME, playerName) == false) {
		return false;
	}

	// update the player name
	strcpy(session->player.name, playerName);
	return true;
}

static void UiPauseTerminal(void) {
	printf(INPUT_PAUSE);
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

#pragma region "Player's action methods"

/// <summary>
/// Displays the dashboard - player's overview.
/// </summary>
/// <param name="session">Current session.</param>
/// <returns>Operation value.</returns>
static bool UiViewDashboard(GameSession* session) {
	if (session == nullptr) return false;

	UiClearScreen();
	UiDisplayBanner();
	printf("Player:  %s%s%s\nBalance: %s%.2lf%s %s\n", ACCENT_TEXT, session->player.name, CRESET, ACCENT_TEXT, session->player.money, CRESET, CURRENCY);
	printf("Day:     %s%d%s\n\n", ACCENT_TEXT, session->day, CRESET);
	printf("Portfolio:\n");

	// count valid stocks
	int count = 0;
	for (int i = 0; i < MAX_STOCK_SIZE; i++) {
		if (session->player.stocks[i].count > 0) {
			count += 1;
		}
	}

	if (count == 0) {
		printf("No stocks.\n");
		return true;
	}

	double sum = 0;

	for (int i = 0; i < MAX_STOCK_SIZE; i++) {
		if (session->player.stocks[i].count > 0) {
			double value = (double)session->player.stocks[i].count * g_stockValues[i];
			sum += value;
			count += 1;
			printf("Stock Name: %-20s %-8lu %.2lf %s\n", g_stockNames[i], session->player.stocks[i].count, value, CURRENCY);
		}
	}

	printf("\nTotal: %s%.2lf%s %s\n", ACCENT_TEXT, sum, CRESET, CURRENCY);
	return true;
}

static bool UiBuyStocks(GameSession* session) {
	UiClearScreen();
	UiDisplayBanner();

	for (int i = 0; i < MAX_STOCK_SIZE - 3; i += 4) {
		printf("%02d. %s %02d. %s %02d. %s %02d. %s\n", i+1,  session->stocks[i].code, i+2,  session->stocks[i + 1].code, i+3, session->stocks[i + 2].code, i+4, session->stocks[i + 3].code);
	}
	printf("\n");

	// get stock id
	long id = UiGetInteger(INPUT_STOCK_INDEX);
	if (id < 1 || id > MAX_STOCK_SIZE) {
		// invalid input
		fprintf(stderr, FORMAT_INVALID_STOCK_INDEX, id);
		return false;
	}

	// adjust the id to index
	id -= 1;

	printf("\n%s: %s%s%s", g_stockCodes[id], ACCENT_TEXT, g_stockNames[id], CRESET);
	printf("\nUnit value: %s%.2lf%s %s\n", ACCENT_TEXT, g_stockValues[id], CRESET, CURRENCY);
	printf("Your money: %s%.2lf%s %s\n\n", ACCENT_TEXT, session->player.money, CRESET, CURRENCY);

	long amount = UiGetInteger(INPUT_AMOUNT);
	printf("\n");
	if (amount <= 0) {
		// invalid amount
		fprintf(stderr, ERROR_INVALID_STOCK_NUMBER);
		return false;
	}

	// calculate total price
	double total = g_stockValues[id] * (double)amount;

	if (session->player.money < total) {
		// insufficient money
		fprintf(stderr, "Insufficient funds.\n");
		return false;
	}

	// transfer stocks
	// updating only the count is alright as the game state values are stored in the global variables
	session->player.money -= total;
	session->player.stocks[id].count += amount;
	GsSetDailyBalance(GsGetDailyBalance() - total);
	return true;
}

/// <summary>
/// Sells the player's stocks.
/// </summary>
/// <param name="session">Active game session.</param>
/// <returns>Operation result.</returns>
/// <remarks>
/// Writes to the stderr on every failed check.
/// When the function fails a check, it immediately returns false.
/// </remarks>
static bool UiSellStocks(GameSession* session) {
	if (session == nullptr) return false;

	UiClearScreen();
	UiDisplayBanner();

	int idx = 0;
	int stockIdxs[MAX_STOCK_SIZE] = {EOF};

	// get only the valid stocks (by their indexes)
	for (int i = 0; i < MAX_STOCK_SIZE; i++) {
		if (session->player.stocks[i].count > 0) {
			stockIdxs[idx++] = i;
		}
	}

	// list the sellable stocks
	if (idx == 0) {
		fprintf(stderr, "No stocks to sell.\n");
		return false;
	}

	for (int i = 0; i < MAX_STOCK_SIZE; i++) {
		if (session->player.stocks[i].count > 0) {
			// print the stock info
			printf("%02d. %s%s%s: %-20s %lu %.2lf %s\n", i+1, ACCENT_TEXT, g_stockCodes[i], CRESET, g_stockNames[i], session->player.stocks[i].count, (double)session->player.stocks[i].count * g_stockValues[i], CURRENCY);
		}
	}

	printf("\n");
	long id = UiGetInteger(INPUT_STOCK_INDEX);
	if (id == EOF || (id < 1 || id > MAX_STOCK_SIZE)) {
		fprintf(stderr, FORMAT_INVALID_STOCK_INDEX, id);
		return false;
	}

	// adjust the index
	id -= 1;

	// verify the index
	if (stockIdxs[id] == EOF) {
		fprintf(stderr, FORMAT_INVALID_STOCK_INDEX, id);
		return false;
	}

	// stock index is valid
	// stock can be sold
	// get the amount of stocks to be sold
	printf("Selected stock: %s%s%s\n", ACCENT_TEXT, g_stockNames[id], CRESET);
	long amount = UiGetInteger(INPUT_AMOUNT);

	if (amount <= 0 || amount > session->player.stocks[id].count) {
		fprintf(stderr, "Invalid amount of stocks.\n");
		return false;
	}

	// checks passed, sell the stocks
	double delta = (double)amount * g_stockValues[id];
	session->player.stocks[id].count -= amount;
	session->player.money += delta;
	GsSetDailyBalance(GsGetDailyBalance() + delta);
	return true;
}

static bool UiViewTrends(const GameSession* session) {
	if (session == nullptr) return false;

	UiClearScreen();
	UiDisplayBanner();

	// display stock information
	printf("Simple trend overview\n\n");

	printf(ACCENT_BOLD);
	printf("%-24s %s %-10s VOLATILITY\n", "STOCK NAME", "CODE", "UNIT VALUE");
	printf(CRESET);
	for (int i = 0; i < MAX_STOCK_SIZE; i++) {
		printf("%s%-24s%s %s %s%10.2lf%s %.3lf\n", ACCENT_TEXT, g_stockNames[i], CRESET, g_stockCodes[i], ACCENT_TEXT, g_stockValues[i], CRESET, g_stockVolatilities[i]);
	}
	return true;
}

static bool UiExecuteActions(GameSession* session) {
	if (session == nullptr) return false;
	GsUpdateStockValues();
	session->day += 1;
	return true;
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
	if (session == nullptr)
		return GAME_ERROR;

	// set the game session state to running
	session->gameState = STATE_RUNNING;

	// THE main game loop
	while (session->gameState == STATE_RUNNING) {

		/*
		 *	1. List player's options
		 *	2. Get player's inputs (can be multiple actions per day) and process them
		 *	3. When all actions are taken, process the day and evaluate the results
		 *		- Update the global state of assets like stocks, money, day counter
		 *	4. Start anew
		 */

		GsSetDailyBalance(0);

		//	1. List player's options
		bool userInputs = true;
		while (userInputs == true) {
			UiClearScreen();
			UiDisplayBanner();

			printf("1. View Dashboard\n");
			printf("2. Buy Stocks\n");
			printf("3. Sell Stocks\n");
			printf("4. View Trends\n");
			printf("5. Execute Actions\n");
			printf("0. Quit\n\n");

			//	2. Get player's inputs
			long option = UiGetInteger(INPUT_GAME_ACTION);
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
						fprintf(stderr, "Unable to display the dashboard.\n");
					}

					// pause even when the method succeeds
					printf("\n");
					UiPauseTerminal();
					break;

				case 2:
					// Buy Stocks option
					if (UiBuyStocks(session) == false) {
						printf("\n");
						UiPauseTerminal();
					}

					break;

				case 3:
					// Sell Stocks option
					if (UiSellStocks(session) == false) {
						printf("\n");
						UiPauseTerminal();
					}

					break;

				case 4:
					// View Trends option
					if (UiViewTrends(session) == false) {
						fprintf(stderr, "Unable to display trends.\n");
					}

					// pause even when the function succeeds
					printf("\n");
					UiPauseTerminal();
					break;

				case 5:
					//	3. Day ended, update the progress
					userInputs = false;
					if (UiExecuteActions(session) == false) {
						// unable to continue - error or player reached a point of no return
						// exit is the valid
						session->gameState = STATE_ENDED;
						return GAME_OK;
					}

					UiClearScreen();
					UiDisplayBanner();
					printf("Day %s%d%s ended.\n", ACCENT_TEXT, session->day - 1, CRESET);
					printf("Daily balance: %s%.2lf%s %s\n\n", ACCENT_TEXT, GsGetDailyBalance(), CRESET, CURRENCY);
					UiPauseTerminal();
					break;

				default:
					// invalid option
					printf(OUTPUT_INVALID_OPTION);
					break;
			}
		}
	}

	return GAME_OK;
}