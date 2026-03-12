#include "../inc/UI/Screens.h"
#include "../inc/UI/MenuActions.h"
#include "../inc/UI/AppMenus.h"
#include "../inc/Ansi.h"
#include "../inc/Debug.h"

#include <stdio.h>

int ScrDisplayText(FILE* stream, const char* msg)
{
    ClearScreen();
    fprintf(stream, "%s", msg);
    fprintf(stdout, "\nPress any key to continue... ");

    return GetRawChar();
}

int ScrShowError(const char* msg)
{
    return ScrDisplayText(stderr, msg);
}

int ScrShowMessage(const char* msg)
{
    return ScrDisplayText(stdout, msg);
}

static int ScrDisplayCredits(void) {
    char msg[LONG_TEXT_LENGTH];
    snprintf(msg, LONG_TEXT_LENGTH, "Rally Dakar\n(c) 2026, %s%s%s\n", ACCENT_BOLD, AUTHOR, RESET);
    ScrShowMessage(msg);
    return 0;
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
            ScrDisplayCredits();
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

            case ID_RACE:
                if (ScrStartRace(session) == ID_CUP_ENDED) {
                    return ScrCupEnded(session);
                }
                break;

            case ID_SCOREBOARD:
                ScrShowScoreboard(session);
                break;

            case ID_REPAIR_VEHICLES:
                ScrServiceVehicles(session);
                break;

            default:
                break;
        }
    }

    return opt;
}

int ScrStartRace(GameSession* session) {
    DbgNotImplemented("ID_RACE");
    if (session->StageIndex == MAX_STAGES - 1) {
        return ID_CUP_ENDED;
    }

    session->StageIndex++;
    return EOF;
}

int ScrCupEnded(GameSession *session) {
    DbgNotImplemented("ID_CUP_ENDED");
    session->StageIndex = 0;
    return EOF;
}

int ScrShowScoreboard(const GameSession* session) {
    DbgNotImplemented("ID_SCOREBOARD");
    return EOF;
}

int ScrServiceVehicles(GameSession* session) {
    DbgNotImplemented("ID_REPAIR_VEHICLES");
    return EOF;
}