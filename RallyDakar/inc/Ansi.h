//
// Created by jan on 28/02/2026.
//

#ifndef RALLYDAKAR_ANSI_H
#define RALLYDAKAR_ANSI_H

#define RESET           "\033[0m"
#define ACCENT_TEXT     "\033[38;5;11m"
#define ACCENT_BACK     "\033[48;5;11m\033[38;5;0m"
#define INVERT_VIDEO    "\033[7m"
#define BLINK           "\033[5m"
#define BOLD            "\033[1m"
#define CURSOR_HIDE     "\033[?25l"
#define CURSOR_SHOW      "\033[?25h"

#define ClearScreen()   printf("\033[2J\033[H")

#endif //RALLYDAKAR_ANSI_H