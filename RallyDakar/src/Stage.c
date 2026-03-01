//
// Created by jan on 01/03/2026.
//

#include <memory.h>
#include "../inc/Stage.h"

bool StageInit(Stage *stage) {
    if (stage == NULL) return false;

    // clear the entire object
    memset(stage, 0, sizeof(Stage));
    return true;
}