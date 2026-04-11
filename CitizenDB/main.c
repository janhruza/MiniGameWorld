#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string.h>

#include "inc/Common.h"
#include "inc/UI/Ansi.h"
#include "inc/UI/Screens.h"
#include "inc/AppState.h"
#include "inc/Person.h"
#include "inc/Commands.h"

#define RegisterCommand(id, name, method) { commands[id].hash = CoHash(name); commands[id].action = method; }

static AppState* state = NULL;

typedef struct tagCommand
{
    unsigned long hash;
    void (*action)();
} Command;

typedef enum tagCommandId
{
    COM_EXIT = 0,   // exit command id
    COM_CLEAR,      // clear screen command id
    COM_ABOUT,
    COM_HELP,
} CommandId;

Command commands[MAX_COMMANDS];

static STATUS AppInit(void) {
    srand(time(NULL));

    // initialize globals
    state = (AppState*)malloc(sizeof(AppState));
    if (state == NULL)
    {
        fprintf(stderr, "Malloc failed.\n");
        return STATUS_CRITICAL;
    }

    // initialize commands into the commands array
    RegisterCommand(COM_EXIT, "exit", ComExit);
    RegisterCommand(COM_CLEAR, "clear", ComClear);
    RegisterCommand(COM_ABOUT, "about", ComAbout);
    RegisterCommand(COM_HELP, "help", ComHelp);

    ClearScreen();
    return STATUS_OK;
}

static STATUS AppCleanup(void) {
    ClearScreen();
    if (state != NULL)
    {
        free(state);
        state = NULL;
    }

    return STATUS_OK;
}

#ifndef _WIN32

int min(const int a, const int b)
{
    return (a < b) ? a : b;
}

#endif // !_WIN32

/**
* @brief Simple command handler.
* @param command User-typed command.
* @return Operation result.
*/
static STATUS HandleCommand(const char* command)
{
    // command is expected to be normalized
    unsigned long hash = CoHash(command);

    for (int i = 0; i < MAX_COMMANDS; i++)
    {
        if (commands[i].hash == hash)
        {
            commands[i].action();
            return STATUS_OK;
        }
    }

    // command not found
    return STATUS_ERROR;
}

int main(void) {

    if (AppInit() != STATUS_OK) {
        fprintf(stderr, "Initialization failed.\n");
    }

    // TODO main logic goes here
    CoSetConsoleTitle("My Awesome Citizen Database!");
    CoDrawBanner();

    // main app loop
    for(;;)
    {
        // 1. get command
        // 2. process command
        // 3. show output (optional, command processor may do it)

        // get command
        printf("CitizenDB: ");
        char command[TEXT_SIZE];
        CoReadString(command, TEXT_SIZE, stdin);
        CoNormalize(command);

        // process command
        if (HandleCommand(command) == STATUS_ERROR)
        {
            fprintf(stderr, "Command \'%s\' not found.\n", command);
        }
    }

    if (AppCleanup() != STATUS_OK) {
        fprintf(stderr, "Cleanup failed.\n");
    }

    return EXIT_SUCCESS;
}
