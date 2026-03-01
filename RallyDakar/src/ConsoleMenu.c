#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h> // pro NULL

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

#include "../inc/Ansi.h"
#include "../inc/UI/ConsoleMenu.h"

// helper function
static int GetRawChar() {
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

bool CmInitMenu(ConsoleMenu *menu) {
    if (menu == NULL) return false;

    memset(menu, 0, sizeof(ConsoleMenu));

    menu->ActiveIdx = 0;
    snprintf(menu->Header, SHORT_TEXT_LENGTH, "MENU");

    // invalidate all menu items
    for (int i = 0; i < MENU_MAX_ITEMS; i++) {
        menu->Items[i].Id = -1;
    }

    return true;
}

int GetActualMenuSize(const ConsoleMenu *menu) {
    if (menu == NULL) return 0;

    int num = 0;
    for (int i = 0; i < MENU_MAX_ITEMS; i++) {
        if (menu->Items[i].Id < 0 || menu->Items[i].Id >= MENU_MAX_ITEMS) {
            break;
        }
        num++;
    }
    return num;
}

bool CmDrawMenu(ConsoleMenu *menu) {
    if (menu == NULL) return false;

    CoDrawBanner();

    printf("%s  %-*s%s  %s\n", BOLD, MENU_LEFT_PADDING, "", menu->Header, RESET);

    for (int i = 0; i < MENU_MAX_ITEMS; i++) {
        if (menu->Items[i].Id < 0) break;

        // left pad the item
        printf("%*s", MENU_LEFT_PADDING, " ");

        if (i == menu->ActiveIdx) {
            printf(ACCENT_BACK);
            printf("  %-34s  \n", menu->Items[i].Header);
        } else {
            printf("  %-34s  \n", menu->Items[i].Header);
        }
        printf(RESET);
    }

    // print help, left pad it as well
    printf("\n%*sUse %sUP%s and %sDOWN%s to navigate,\n%*s%sENTER%s to select or %sQ%s to exit\n", MENU_LEFT_PADDING, "", ACCENT_TEXT, RESET, ACCENT_TEXT, RESET, MENU_LEFT_PADDING, "", ACCENT_TEXT, RESET, ACCENT_TEXT, RESET);

    return true;
}

int CmSelectMenu(ConsoleMenu *menu) {
    if (menu == NULL) return EOF;

    int menuSize = GetActualMenuSize(menu);
    if (menuSize == 0) return EOF;

    menu->ActiveIdx = 0;

    // hide the cursor
    printf(CURSOR_HIDE);

    int value = EOF;

    while (true) {

        ClearScreen();
        CmDrawMenu(menu);

        const int key = GetRawChar();

        switch (key) {
            case 65: // Linux Up
            case 72: // Windows Up
            case 'w':
                if (menu->ActiveIdx > 0) menu->ActiveIdx--;
                else menu->ActiveIdx = menuSize - 1; // Wrap around
                break;

            case 66: // Linux Down
            case 80: // Windows Down
            case 's':
                if (menu->ActiveIdx < menuSize - 1) menu->ActiveIdx++;
                else menu->ActiveIdx = 0; // Wrap around
                break;

            case 10: // Linux Enter
            case 13: // Windows Enter
                value = menu->Items[menu->ActiveIdx].Id;
                goto exit;

            case 'q': // Escape
            case 'Q': // Escape
                goto exit;

            default:
                break;
        }
    }

    exit:
    printf(CURSOR_SHOW);

    // return the selected key
    return value;
}