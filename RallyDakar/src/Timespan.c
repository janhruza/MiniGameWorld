//
// Created by jan on 20/03/2026.
//

#include "../inc/Common.h"
#include "../inc/Timespan.h"

int TsFromSeconds(const float seconds, Timespan *timespan) {
    if (timespan == NULL) return STATUS_ERROR;

    timespan->Minutes = seconds / 60;
    timespan->Seconds = (int)seconds % 60;
    return STATUS_OK;
}