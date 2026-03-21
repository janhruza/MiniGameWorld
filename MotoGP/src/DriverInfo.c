//
// Created by jan on 21/03/2026.
//

#include <memory.h>

#include "../inc/DriverInfo.h"

STATUS DriverInit(DriverInfo *driver) {
    if (driver == NULL) {
        return STATUS_UNINITIALIZED;
    }

    memset(driver, 0, sizeof(DriverInfo));
    return STATUS_OK;
}