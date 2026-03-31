//
// Created by jan on 28/03/2026.
//

#ifndef CITIZENDB_PERSON_H
#define CITIZENDB_PERSON_H

#include <stdlib.h>

#include "Common.h"

/**
 * @brief Representing a static array of first names.
 */
extern char gFirstNames[NAMES_COUNT][TEXT_SIZE];

/**
 * @brief Representing a static array of last names.
 */
extern char gLastNames[NAMES_COUNT][TEXT_SIZE];

/**
 * @brief Representing a simple person record struct.
 */
typedef struct tagPerson {
    /**
     * @brief Representing the person's identifier.
     */
    int Id;

    /**
     * @brief Representing the person's age.
     */
    int Age;

    /**
     * @brief Representing the person's bank identifier.
     */
    int BankId;

    /**
     * @brief Representing the person's name.
     */
    char Firstname[TEXT_SIZE];

    /**
     * @brief Representing the person's last name.
     */
    char Lastname[TEXT_SIZE];

    /**
     * @brief Representing person's country code.
     */
    char CountryCode[4];

    /**
     * @brief Representing persons vehicles (as indexes).
     */
    int Vehicles[MAX_VEHICLES];

} Person;

/**
 * @brief Gets a random name from the global first names array.
 * @return A random first name.
 */
char* RndFirstName(void);

/**
 * @brief Gets a random name from the global last names.
 * @return A random last name.
 */
char* RndLastName(void);

#endif //CITIZENDB_PERSON_H