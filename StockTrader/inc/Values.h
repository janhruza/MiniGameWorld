/*
* Values.h
* Representing various global definitions and other values.
*/

#pragma once

#pragma region Game options

#define INITIAL_MONEY   1000
#define CURRENCY        "USD"

#pragma endregion

#pragma region Limit values
#define MAX_STOCK_SIZE	32
#define MAX_NAME		32
#define STOCK_CODE_SIZE	5
#pragma endregion

#pragma region Input messages

#define INPUT_PLAYER_NAME	    "Player name: "
#define INPUT_GAME_ACTION       "Select action [0-5]: "
#define INPUT_PAUSE		        "Press ENTER to continue... "
#define INPUT_STOCK_INDEX       "Enter stock code index: "
#define INPUT_AMOUNT            "Enter amount: "

#pragma endregion

#pragma region Output messages

#define OUTPUT_INVALID_OPTION       "Invalid option.\n"
#define FORMAT_INVALID_STOCK_INDEX  "Invalid stock index: %lu\n"
#define ERROR_INVALID_STOCK_NUMBER  "Invalid number of stocks.\n"

#pragma endregion
