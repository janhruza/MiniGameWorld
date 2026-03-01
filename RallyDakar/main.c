//
// Created by jan on 28/02/2026.
//

#include <stdio.h>

#include "inc/Ansi.h"
#include "inc/GameSession.h"
#include "inc/UI/ConsoleMenu.h"
#include "inc/UI/AppMenus.h"

int main(int argc, const char *argv[]) {
    ClearScreen();
    CoDrawBanner();

    GameSession gs;

    // TODO create/load game session

    // run the app loop
    const StatusCode result = GsStartGameLoop(&gs);

    // app exit
    ClearScreen();
    return result;
}
