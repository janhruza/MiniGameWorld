//
// Created by jan on 22/03/2026.
//

#ifndef MOTOGP_TRACKINFO_H
#define MOTOGP_TRACKINFO_H

#include "Common.h"

/**
 * @brief Representing a track information.
 */
typedef struct tagTrackInfo {
    int Id;
    Country Country;
    char Name[LONG_TEXT_LENGTH];
    char Circuit[LONG_TEXT_LENGTH];
} TrackInfo;

#endif //MOTOGP_TRACKINFO_H