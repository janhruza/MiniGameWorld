//
// Created by jan on 28/03/2026.
//

#ifndef CITIZENDB_COMMON_H
#define CITIZENDB_COMMON_H

#define AUTHOR              "@jendahruza"
#define PRODUCT             "CitizenDB"
#define TEXT_SIZE           33
#define COUNTRIES_COUNT     100
#define COUNTRY_CODE_LEN    4
#define NAMES_COUNT         100

/**
 * @brief Application status codes.
 */
typedef enum tagSTATUS {
    STATUS_OK,              // OK
    STATUS_ERROR,           // ERROR
    STATUS_UNINITIALIZED,   // Object not initialized
    STATUS_CRITICAL,        // Critical error.
} STATUS;

extern char gCountries[COUNTRIES_COUNT][COUNTRY_CODE_LEN];

void CoDrawBanner(void);

#endif //CITIZENDB_COMMON_H