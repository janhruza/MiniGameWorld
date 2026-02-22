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

	Stock stocks[MAX_STOCK_SIZE];

} Player;