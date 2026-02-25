/*
* Player.h
* Representing the player object struct.
*/

#pragma once
#include <math.h>

#include "Stock.h"
#include "../Values.h"

/// <summary>
/// Representing the player object.
/// </summary>
typedef struct
{
	/// <summary>
	/// Player's name.
	/// </summary>
	char name[MAX_NAME];

	/// <summary>
	/// Player's money.
	/// </summary>
	double money;

	/// <summary>
	/// Number of owned stocks.
	/// </summary>
	int stockSize;

	/// <summary>
	/// List of owned stocks.
	/// </summary>
	Stock stocks[MAX_STOCK_SIZE];

} Player;

/// <summary>
/// Sets the player's money.
/// </summary>
/// <param name="player">The target player object.</param>
/// <param name="newValue">New money value.</param>
/// <remarks>
/// Sets <paramref name="player"/>'s money to the absolute value of <paramref name="newValue"/>.
/// </remarks>
static bool PlayerSetMoney(Player *player, double newValue) {
	if (player == nullptr) return false;

	double value = fabs(newValue);
	player->money = newValue;
	return true;
}