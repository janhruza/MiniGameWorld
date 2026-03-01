//
// Created by jan on 01/03/2026.
//

#include <stdio.h>
#include "../inc/Common.h"
#include "../inc/Ansi.h"

void CoDrawBanner(void) {
    printf("%sRally Dakar%s\nBy %s@jendahruza%s\n\n", BOLD, RESET, ACCENT_TEXT, RESET);
}