//
// Created by jan on 31/03/2026.
//

#ifndef CITIZENDB_SCREENS_H
#define CITIZENDB_SCREENS_H

#include "../Common.h"

STATUS ScrAddPerson(void);
STATUS ScrRemovePerson(void);

STATUS ScrAddVehicle(int personId);
STATUS ScrRemoveVehicle(int personId);

#endif //CITIZENDB_SCREENS_H
