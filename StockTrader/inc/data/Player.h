/*
* Player.h
* Representing the player object struct.
*/

#pragma once
#include "Stock.h"
#include "..\Values.h"

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