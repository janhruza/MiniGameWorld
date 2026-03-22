//
// Created by jan on 21/03/2026.
//

#include "../inc/Common.h"

#include <stdio.h>

#include "../inc/UI/Ansi.h"

const char* GetStatus(const STATUS status) {
    switch (status) {
        case STATUS_OK:
            return "STATUS_OK";

        case STATUS_ERROR:
            return "STATUS_ERROR";

        case STATUS_UNINITIALIZED:
            return "STATUS_UNINITIALIZED";

        default:
        case STATUS_UNKNOWN:
            return "STATUS_UNKNOWN";
    }
}

STATUS CoDrawBanner(void) {
    printf("%s\n(c) 2026 %s%s%s\n\n", PRODUCT_NAME, ACCENT_TEXT, AUTHOR, RESET);
    return STATUS_OK;
}
