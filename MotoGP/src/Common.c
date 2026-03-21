//
// Created by jan on 21/03/2026.
//

#include "../inc/Common.h"

#include <stdio.h>

#include "../inc/UI/Ansi.h"

STATUS CoDrawBanner(void) {
    printf("%s\n(c) 2026 %s%s%s\n", PRODUCT_NAME, ACCENT_TEXT, AUTHOR, RESET);
    return STATUS_OK;
}
