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

int ScrWelcome(GameSession* session)
{
    const int iWelcome = MenuWelcomeScreen();
    switch (iWelcome) {
    case ID_EXIT:
        return ID_EXIT; // true app exit

    case ID_NEW_GAME:
        if (GsSave(session, sSaveFile) == false) {
            fprintf(stderr, "Unable to create the save game file.\n");
            return ID_ERROR;
        }
        ScrMainMenu(session);
        break; // back to the welcome screen

    case ID_LOAD_GAME:
        if (GsLoad(session, sSaveFile) == false) {
            fprintf(stderr, "Unable to load the save game file.\n");
            return ID_ERROR;
        }
        ScrMainMenu(session);
        break;

    case ID_CREDITS:
        CoShowCredits();
        break;

    default:
        return ID_ERROR;
    }

    return 0xFF; // > 0 to not get terminated completely
}

int ScrMainMenu(GameSession* session)
{
    int iMainMenu = 0xFF;
    while (iMainMenu != ID_EXIT) // explicit check
    {
        iMainMenu = MenuMainScreen(session);
        switch (iMainMenu)
        {
        case ID_NEW_CUP:
            session->StageIndex = 0;
            ScrContinueCup(session);
            break;
        case ID_CONTINUE_CUP:
            ScrContinueCup(session);
            break;
        case ID_EXIT:
            return 0xFF; // > 0 to not get terminated completely
        }
    }
    return 0xFF;
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
                return ID_EXIT;

            default:
                break;
        }
    }
}