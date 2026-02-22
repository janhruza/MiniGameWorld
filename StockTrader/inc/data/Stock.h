/*
* Stock.h
* Representing the stock object.
*/

#pragma once
#include "..\Values.h"

/// <summary>
/// Representing a single stock object.
/// </summary>
typedef struct
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
	/// </summary>
	char code[4];

} Stock;