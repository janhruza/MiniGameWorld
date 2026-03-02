//
// Created by jan on 01/03/2026.
//

#include <stdio.h>
#include "../inc/Common.h"
#include "../inc/Ansi.h"

void CoDrawBanner(void) {
    printf("Rally Dakar\n(c) 2026 %s%s%s%s\n\n", BOLD, ACCENT_TEXT, AUTHOR, RESET);
}

void CoShowCredits(void) {
    ClearScreen();
    CoDrawBanner();
}