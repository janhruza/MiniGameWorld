/*
* Stock.h
* Representing the stock object.
*/

#pragma once
#include "..\Values.h"
#include <stdbool.h>
#include <memory.h>
#include <string.h>

/// <summary>
/// Representing a single stock object.
/// </summary>
typedef struct _stock
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
	/// Short, 4 letter identification code.
	/// The overall size is 5 to reserve the string terminator character.
	/// </summary>
	char code[STOCK_CODE_SIZE];

} Stock;

inline static bool CreateStock(const char* name, const char* code, double unitValue, Stock *dest)
{
	if (dest == NULL) return false;

	memset(dest, 0, sizeof(dest));
	dest->value = unitValue;
	strcpy_s(dest->name, MAX_NAME, name);
	strcpy_s(dest->code, STOCK_CODE_SIZE, code);
	return true;
}

inline static bool StockIsValid(Stock* stock)
{
	if (stock == NULL) return false;
	if (strnlen_s(stock->name, MAX_NAME) == 0) return false;
	if (strnlen_s(stock->code, MAX_NAME) == 0) return false;
	if (stock->value <= 0) return false;

	return true;
}

inline static int StockValidCount(Stock *stocks[], size_t maxCount)
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