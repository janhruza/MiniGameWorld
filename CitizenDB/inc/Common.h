//
// Created by jan on 28/03/2026.
//

#ifndef CITIZENDB_COMMON_H
#define CITIZENDB_COMMON_H

#include <stdio.h>

#define AUTHOR              "@jendahruza"
#define PRODUCT             "CitizenDB"
#define TEXT_SIZE           33
#define COUNTRIES_COUNT     100
#define COUNTRY_CODE_LEN    4
#define NAMES_COUNT         100
#define MAX_VEHICLES        10

/**
 * @brief Application status codes.
 */
typedef enum tagSTATUS {
    STATUS_OK,              // Operation success.
    STATUS_ERROR,           // Generic failure.
    STATUS_UNINITIALIZED,   // Object not initialized or missing implementation.
    STATUS_CRITICAL,        // Critical error.
} STATUS;

extern char gCountries[COUNTRIES_COUNT][COUNTRY_CODE_LEN];

void CoDrawBanner(void);
void CoPause(void);

/**
 * @brief Clears the input buffer.
 */
void CoClearBuffer(void);

int CoReadString(char* buf, int n, FILE *stream);

int CoReadInt(int* buf);

void CoSetConsoleTitle(char* text);

/**
 * @brief Prompts user to perform yes/no choice.
 * @param text Confirmation text. Use NULL to use the default text.
 * @return Operation result: 1 - yes, 0 - no.
 */
int CoChoice(char *text);

#endif //CITIZENDB_COMMON_H