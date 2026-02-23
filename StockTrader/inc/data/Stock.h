/*
* Stock.h
* Representing the stock object.
*/

#pragma once
#include "../Values.h"
#include <memory.h>
#include <string.h>

/// <summary>
/// Representing a single stock object.
/// </summary>
typedef struct stock
{
	/// <summary>
	/// Stock name.
	/// </summary>
	char name[MAX_NAME];

	/// <summary>
	/// Value of a single unit.
	/// </summary>
	double value;

	/// <summary>
	/// Representing the value of available units.
	/// This number should increase and decrease at the smae time at different places -
	/// e.g. if a player buys a new stock, it's counter should increase and the generally
	/// available counter should decrease by the amount of bought units.
	/// </summary>
	unsigned long count;

	/// <summary>
	/// Short, 4 letter identification code.
	/// The overall size is 5 to reserve the string terminator character.
	/// </summary>
	char code[STOCK_CODE_SIZE];

} Stock;

/// <summary>
/// Creates a new stock object.
/// </summary>
/// <param name="name">Stock name.</param>
/// <param name="code">Stock code.</param>
/// <param name="unitValue">Stock unit value.</param>
/// <param name="dest">Destination object.</param>
/// <returns>true if the function succeeds, otherwise false.</returns>
inline static bool CreateStock(const char* name, const char* code, double unitValue, Stock *dest)
{
	if (dest == NULL) return false;

	memset(dest, 0, sizeof(Stock));
	dest->value = unitValue;
	strcpy(dest->name, name);
	strcpy(dest->code, code);
	return true;
}

/// <summary>
/// Determines whether the given stock is valid.
/// </summary>
/// <param name="stock">Target stock object.</param>
/// <returns>true if the stock is valid, otherwise false.</returns>
inline static bool StockIsValid(const Stock* stock)
{
	if (stock == NULL) return false;
	if (strlen(stock->name) == 0) return false;
	if (strlen(stock->code) == 0) return false;
	if (stock->value <= 0) return false;

	return true;
}

/// <summary>
/// Counts the valid stocks from the list of stocks.
/// </summary>
/// <param name="stocks">List of stocks.</param>
/// <param name="maxCount">Maximum number of loop cycles. It should be the same as the size of the stocks list.</param>
/// <returns>Number of the valid stocks.</returns>
inline static int StockValidCount(Stock *stocks[], const size_t maxCount)
{
	int count = 0;
	for (int i = 0; i < maxCount; i++)
	{
		if (StockIsValid(stocks[i]) == true)
		{
			count++;
		}
	}

	return count;
}