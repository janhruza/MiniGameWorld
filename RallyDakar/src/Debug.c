#include <stdio.h>
#include <stdbool.h>

#include "../inc/Ansi.h"

static const char* logPath = "applog.txt";

static bool WriteLog(const char* tag, const char* msg)
{
	FILE* fLog = fopen(logPath, "a");
	if (fLog == NULL)
	{
		return false;
	}

	fprintf(fLog, "%s: %s\n", tag, msg);
	fclose(fLog);
	return true;
}

void DbgNotImplemented(const char* msg)
{
	WriteLog("NotImplemented", msg);
	fprintf(stderr, "%sNotImplemented%s: %s\n", ACCENT_DEBUG, RESET, msg);
	return;
}