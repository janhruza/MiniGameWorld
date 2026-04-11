#include <stdio.h>
#include <stdlib.h>
#include "../inc/Commands.h"
#include "../inc/UI/Ansi.h"
#include "../inc/Common.h"

void ComExit(void)
{
	exit(0);
	return;
}

void ComClear(void)
{
	ClearScreen();
	return;
}

void ComHelp(void)
{
	CoDrawBanner();
	return;
}

void ComAbout(void)
{
	CoDrawBanner();
	return;
}