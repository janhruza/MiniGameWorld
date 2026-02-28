//
// Created by jan on 28/02/2026.
//

#ifndef RALLYDAKAR_TERRAINTYPE_H
#define RALLYDAKAR_TERRAINTYPE_H

/**
 * @brief Representing the available stage terrain types.
 */
typedef enum {
    /**
     * Representing the sandy dunes.
     */
    DUNES   = 1,

    /**
     * Representing the sand environment.
     */
    SAND    = 2,

    /**
     * Representing the dirt environment.
     */
    DIRT    = 4,

    /**
     * Representing the rocky mountains.
     */
    ROCKS   = 8
} TerrainType;

#endif //RALLYDAKAR_TERRAINTYPE_H