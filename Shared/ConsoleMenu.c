#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

#include "../inc/Ansi.h"
#include "../inc/UI/ConsoleMenu.h"
#include "../inc/Common.h"

bool CmInitMenu(ConsoleMenu *menu) {
    if (menu == NULL) return false;

    memset(menu, 0, sizeof(ConsoleMenu));
    menu->Extra = "\0";

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
        if (menu->Items[i].Id < 0) {
            break;
        }
        num++;
    }
    return num;
}

bool CmDrawMenu(ConsoleMenu *menu) {
    if (menu == NULL) return false;

    CoDrawBanner();

    printf("%s  %-*s%s  %s\n", ACCENT_BOLD, MENU_LEFT_PADDING, "", menu->Header, RESET);

    for (int i = 0; i < MENU_MAX_ITEMS; i++) {
        if (menu->Items[i].Id < 0) break;

        // left pad the item
        printf("%*s", MENU_LEFT_PADDING, "");

        if (i == menu->ActiveIdx) {
            printf(ACCENT_BACK);
            printf(BOLD);
            printf("  %-*s  \n", MENU_ITEM_HEADER_WIDTH, menu->Items[i].Header);
        } else {
            printf("  %-*s  \n", MENU_ITEM_HEADER_WIDTH, menu->Items[i].Header);
        }
        printf(RESET);
    }

    // print help, left pad it as well
    printf("\n%*sUse %sUP%s and %sDOWN%s to navigate,\n%*s%sENTER%s to select or %sQ%s to quit.\n", MENU_LEFT_PADDING, "", ACCENT_BOLD, RESET, ACCENT_BOLD, RESET, MENU_LEFT_PADDING, "", ACCENT_BOLD, RESET, ACCENT_BOLD, RESET);

    if (strlen(menu->Extra) > 0) {
        // display the extra attached info
        printf("\n%*s%s\n", MENU_LEFT_PADDING, "", menu->Extra);
    }

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

                // check if the item is a separator
                // and if so, ignore it
                if (menu->Items[menu->ActiveIdx].Id == MENU_ID_SEPARATOR) break;

                value = menu->Items[menu->ActiveIdx].Id;
                goto exit;

            case 'q': // Escape
            case 'Q': // Escape
                // immediate exit
                // no save, just quit
                printf(CURSOR_SHOW);    // restore the cursor
                exit(0);
                break;

            default:
                break;
        }
    }

    exit:
    printf(CURSOR_SHOW);
    // return the selected key
    return value;
}

bool CmIsSeparator(const MenuItem *item) {
    if (item == NULL) return false;
    return item->Id == MENU_ID_SEPARATOR;
}

bool CmMakeSeparator(MenuItem *item) {
    if (item == NULL) return false;

    item->Id = MENU_ID_SEPARATOR;

    for (int i  = 0; i < MENU_ITEM_HEADER_WIDTH; i++) {
        item->Header[i] = '-';
    }

    return true;
}