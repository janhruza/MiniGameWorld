#include "../inc/UI/Screens.h"
#include "../inc/UI/MenuActions.h"
#include "../inc/UI/AppMenus.h"
#include "../inc/Ansi.h"
#include "../inc/Debug.h"

#include <stdio.h>
#include <time.h>

static int ScrPause()
{
    fprintf(stdout, "Press any key to continue... ");
    return GetRawChar();
}

int ScrDisplayText(FILE* stream, const char* msg)
{
    ClearScreen();
    fprintf(stream, "%s\n", msg);
    return ScrPause();
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
    ClearScreen();
    CoDrawBannerEx();
    return ScrPause();
}

int ScrGarage(TeamInfo* team)
{
    // display general info
    printf("--- %sGeneral Information%s ---\n", ACCENT_BOLD, RESET);
    printf("Id:      %s%d%s\n", ACCENT_TEXT, team->Id, RESET);
    printf("Name:    %s%s%s\n", ACCENT_TEXT, team->TeamName, RESET);
    printf("Time:    %s%.2f%s\n", ACCENT_TEXT, team->TimeTotal, RESET);
    printf("Penalty: %s%.2f%s\n", ACCENT_TEXT, team->TimeTotal, RESET);

    printf("\n--- Vehicles ---\n");

    // display vehicles
    for (int vIdx = 0; vIdx < MAX_TEAM_VEHICLES; vIdx++)
    {
        VehicleInfo* ptrVehicle = &team->Vehicles[vIdx];
        // vehicle check
        if (ptrVehicle->bActive == false) continue;

        printf("%sVehicle %02d%s\n", ACCENT_BOLD, vIdx + 1, RESET);
        printf("Engine:      %.2f %%\n", ptrVehicle->Health.Engine);
        printf("Electronics: %.2f %%\n", ptrVehicle->Health.Electronics);
        printf("Suspension:  %.2f %%\n", ptrVehicle->Health.Suspension);
        printf("Tires:       %.2f %%\n", ptrVehicle->Health.Tires);
        printf("Time:        %.2f\n", ptrVehicle->Time);
        printf("Penalty:     %.2f\n\n", ptrVehicle->Penalty);

        printf("Drivers:\n");
        for (int dIdx = 0; dIdx < MAX_CREW_SIZE; dIdx++)
        {
            printf("  - %s\n", team->Vehicles[vIdx].Drivers[dIdx]);
        }
    }

    return ScrPause();
}

int ScrWelcome(GameSession* session)
{
    const int iWelcome = MenuWelcomeScreen();
    switch (iWelcome) {
    case ID_EXIT:
        return ID_EXIT; // true app exit

    case ID_NEW_GAME:
        // load data
        ClearScreen();
        printf("--- %sCreate team%s ---\n", ACCENT_BOLD, RESET);
        if (ScrCreateTeam(&session->Teams[PLAYER_TEAM_INDEX]) == STATUS_ERROR)
        {
            fprintf(stderr, "Unable to create player's team.\n");
            return ID_ERROR;
        }

        // load vehicles
        int vehicleIdx = 0;
        while (vehicleIdx < MAX_TEAM_VEHICLES)
        {
            ClearScreen();
            printf("--- Vehicle %d of %d ---\n", vehicleIdx + 1, MAX_TEAM_VEHICLES);
            VehicleInfo* ptrVehicle = &session->Teams[PLAYER_TEAM_INDEX].Vehicles[vehicleIdx];
            if (ScrCreateVehicle(ptrVehicle) == STATUS_ERROR)
            {
                break;
            }

            vehicleIdx++;
        }

        // game created
        if (GsSave(session, sSaveFile) == false) {
            fprintf(stderr, "Unable to create the save game file.\n");
            return ID_ERROR;
        }

        // start the game
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

int ScrCreateTeam(TeamInfo* team)
{
    if (team == NULL)
    {
        return STATUS_ERROR;
    }

    /*
    * Team has:
    *  - Id (auto assign)
    *  - Name (user assigned)
    */

    strcpy(team->TeamName, "\0");
    team->Id = time(NULL);

    printf("Enter the team's name\n# ");
    fgets(team->TeamName, SHORT_TEXT_LENGTH, stdin);

    if (strlen(team->TeamName) - 1 > 0) // -1: LF
    {
        team->TeamName[strlen(team->TeamName) - 1] = 0; // remove the LF
        return STATUS_OK;
    }

    return STATUS_ERROR;
}

int ScrCreateVehicle(VehicleInfo* vehicle)
{
    if (VehicleInit(vehicle) == false)
    {
        return STATUS_ERROR;
    }

    /*
    * Every vehicle has:
    *  - Up to 5 drivers
    */

    int idx = 0;
    while (idx < MAX_CREW_SIZE)
    {
        // get the drivers name
        char name[SHORT_TEXT_LENGTH] = { 0 };
        printf("Eneter the drivers name (driver %d of %d)\n# ", idx + 1, MAX_CREW_SIZE);
        fgets(name, SHORT_TEXT_LENGTH, stdin);

        if (strlen(name) - 1 > 0)
        {
            // set the driver's name at the current index
            // trim the trailing LF
            name[strlen(name) - 1] = 0;
            strcpy(vehicle->Drivers[idx], name);
            idx++;
        }

        else
        {
            // no more drivers
            return EOF;
        }
    }

    vehicle->bActive = true;
    return STATUS_OK;
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

        case ID_GARAGE:
            ScrGarage(&session->Teams[PLAYER_TEAM_INDEX]);
            break;

        case ID_SAVE_GAME:
            if (GsSave(session, sSaveFile) == false)
            {
                return ID_ERROR;
            }

            ScrShowMessage("Game saved!");
            break;

        case ID_EXIT:
            break;
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
    return ID_NOT_IMPLEMENTED;
}

int ScrShowScoreboard(const GameSession* session) {
    DbgNotImplemented("ID_SCOREBOARD");
    return ID_NOT_IMPLEMENTED;
}

int ScrServiceVehicles(GameSession* session) {
    DbgNotImplemented("ID_REPAIR_VEHICLES");
    return ID_NOT_IMPLEMENTED;
}