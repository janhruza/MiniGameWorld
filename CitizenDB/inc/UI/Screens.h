//
// Created by jan on 31/03/2026.
//

#ifndef CITIZENDB_SCREENS_H
#define CITIZENDB_SCREENS_H

#include "../Common.h"
#include "../AppState.h"

STATUS ScrAddPerson(AppState *state);
STATUS ScrRemovePerson(AppState *state);

STATUS ScrAddVehicle(int personId);
STATUS ScrRemoveVehicle(int personId);

#endif //CITIZENDB_SCREENS_H
