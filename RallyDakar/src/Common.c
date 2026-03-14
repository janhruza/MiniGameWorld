//
// Created by jan on 01/03/2026.
//

#include <stdlib.h>
#include <stdio.h>
#include "../inc/Common.h"
#include "../inc/Ansi.h"
#include "../inc/UI/Screens.h"

#ifndef _WIN32          // linux env
#include <termios.h>
#include <unistd.h>
#endif

// helper function
int GetRawChar() {
#ifdef _WIN32
    int ch = _getch();
    if (ch == 0 || ch == 224) return _getch();
    return ch;
#else
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();

    // linux arrow magic
    if (ch == 27) {
        if (getchar() == 91) { // skip the '['
            ch = getchar(); // read the result
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}

void CoDrawBanner(void) {
    printf("Rally Dakar\n(c) 2026 %s%s%s%s\n\n", BOLD, ACCENT_TEXT, AUTHOR, RESET);
}

void CoShowCredits(void) {
    ClearScreen();
    CoDrawBanner();
}