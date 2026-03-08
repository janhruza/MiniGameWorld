#include "../inc/UI/Screens.h"
#include "../inc/UI/MenuActions.h"
#include "../inc/UI/AppMenus.h"
#include "../inc/Ansi.h"

#include <stdio.h>

int ScrDisplayText(FILE* stream, const char* msg)
{
    ClearScreen();
    fprintf(stream, msg);
    fprintf(stdout, "\nPress any key to continue... ");

    return GetRawChar();
}

int ScrShowError(const char* msg)
{
    return ScrDisplayText(stdout, msg);
}

int ScrShowMessage(const char* msg)
{
    return ScrDisplayText(stderr, msg);
}

int ScrWelcome(GameSession *session)
{
    ClearScreen();
    const int iWelcome = MenuWelcomeScreen();
    switch (iWelcome) {
    case ID_EXIT:
        return ID_EXIT;

    case ID_NEW_GAME:
    case ID_DEBUG:
        // create the save game file
        if (GsSave(session, sSaveFile) == false) {
            fprintf(stderr, "Unable to create the save game file.\n");
            return ID_ERROR;
        }
        
        while (ScrMainMenu(session) != ID_EXIT);

    case ID_LOAD_GAME:
        if (GsLoad(session, sSaveFile) == false) {
            fprintf(stderr, "Unable to load the save game file.\n");
            return ID_ERROR;
        }

        ScrMainMenu(session);

    case ID_CREDITS:
        CoShowCredits();
        return ID_CREDITS;

    default:
        return EOF;
    }

    return ID_EXIT;
}

int ScrMainMenu(GameSession* session)
{
    int iMainMenu = 0xFF;
    while (iMainMenu > 0)
    {
        iMainMenu = MenuMainScreen(session);
        switch (iMainMenu)
        {
        case ID_EXIT:
            break;

        case ID_CONTINUE_CUP:
            ScrContinueCup(session);
            break;

            // error returned
        case ID_ERROR:
        case EOF:
            fprintf(stderr, "An error has occurred. Error code: 0x%X.\n", iMainMenu);
            return ID_ERROR;
        }
    }
}

int ScrContinueCup(GameSession* session)
{
    int opt = 0xFF;
    while (opt > 0)
    {
        opt = MenuContinueCup(session);
        switch (opt)
        {
            case ID_EXIT:
                break;

            default:
                break;
        }
    }
}