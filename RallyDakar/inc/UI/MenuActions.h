#ifndef RALLYDAKAR_MENUACTIONS_H
#define RALLYDAKAR_MENUACTIONS_H

/**
 * @brief Representing the valid menu action IDs.
 */
typedef enum {
    ID_EXIT = 0,        // Universal exit or cancel action code.
    ID_ERROR,           // Generic error code.
    ID_NOT_IMPLEMENTED, // Feature not implemented (used for debug purposes).

    // GENERAL
    ID_DEBUG,           // Debug option used to bypass some functionality for testing purposes (only one ID_DEBUG is assumed while testing).
    ID_NEW_GAME,        // Start a new game.
    ID_LOAD_GAME,       // Load a saved game.
    ID_SAVE_GAME,       // Save game.
    ID_CREDITS,         // Display credits.

    // MAIN MENU SCREEN
    ID_NEW_CUP,         // Start a new cup (season).
    ID_CONTINUE_CUP,    // Continue the active cup (if any).
    ID_ADJUST_VEHICLES, // Adjust player's team vehicles.
    ID_GARAGE,

    // CONTINUE CUP SCREEN
    ID_RACE,
    ID_CUP_ENDED,
    ID_SCOREBOARD,
    ID_REPAIR_VEHICLES

} MenuActions;

#endif