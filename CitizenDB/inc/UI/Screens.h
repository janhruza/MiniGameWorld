//
// Created by jan on 31/03/2026.
//

#ifndef CITIZENDB_SCREENS_H
#define CITIZENDB_SCREENS_H

#include "../Common.h"
#include "../AppState.h"

/**
* @brief Adds a new person to the current game state's database of persons.
* @param state The active game state.
* @return Operation result.
*/
STATUS ScrAddPerson(AppState *state);

/**
* @brief Removes a person from the current game state's database of persons.
* @param state The active game state.
* @returns Operation result.
*/
STATUS ScrRemovePerson(AppState *state);

/**
* @brief Adds a vehicle to the given person.
* @param state The active game state.
* @param personId Id of the target person.
* @returns Operation result.
*/
STATUS ScrAddVehicle(AppState *state, int personId);

/**
* @brief Removes a vehicle from the given person.
* @param state The active game state.
* @param personId Id of the target person.
* @returns Operation result.
*/
STATUS ScrRemoveVehicle(AppState *state, int personId);

#endif //CITIZENDB_SCREENS_H
