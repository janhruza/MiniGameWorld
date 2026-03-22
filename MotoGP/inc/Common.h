//
// Created by jan on 21/03/2026.
//

#ifndef MOTOGP_COMMON_H
#define MOTOGP_COMMON_H

#define AUTHOR              "@jendahruza"
#define PRODUCT_NAME        "MotoGP '26"
#define DRIVER_COUNT        22
#define TEAM_COUNT          11
#define TRACK_COUNT         22
#define MANUFACTURERS_COUNT 5

#define TEXT_LENGTH         33
#define LONG_TEXT_LENGTH    65

#include <limits.h>
#include <stdint.h>

/**
 * @brief Representing various status codes.
 */
typedef enum tagSTATUS : uint32_t {
    STATUS_OK,              // Success code.
    STATUS_ERROR,           // Error code.
    STATUS_UNINITIALIZED,   // Error, object not initialized.
    STATUS_UNKNOWN          = INT_MAX,
} STATUS;

extern const char *GetStatus(const STATUS status);

/**
 * @brief Simple custom boolean implementation.
 */
typedef enum tagBOOL : int {
    FALSE = 0,
    TRUE
} BOOL;

/**
 * @brief Representing various nationalities.
 */
typedef enum tagCountry : uint8_t {
    COUNTRY_OTHER = 0,
    COUNTRY_FRANCE,
    COUNTRY_TURKEY,
    COUNTRY_ITALY,
    COUNTRY_BRAZIL,
    COUNTRY_SPAIN,
    COUNTRY_SOUTH_AFRICA,
    COUNTRY_AUSTRALIA,
    COUNTRY_JAPAN,
    COUNTRY_THAILAND,
    COUNTRY_USA,
    COUNTRY_CATALONIA,
    COUNTRY_HUNGARY,
    COUNTRY_CZECHIA,
    COUNTRY_NETHERLANDS,
    COUNTRY_GERMANY,
    COUNTRY_GREAT_BRITAIN,
    COUNTRY_ARAGON,
    COUNTRY_SAN_MARINO,
    COUNTRY_AUSTRIA,
    COUNTRY_INDONESIA,
    COUNTRY_MALAYSIA,
    COUNTRY_QATAR,
    COUNTRY_PORTUGAL,
    COUNTRY_VALENCIA,
} Country;

/**
 * @brief Displays the program banner.
 * @return Always STATUS_OK.
 */
STATUS CoDrawBanner(void);

#endif //MOTOGP_COMMON_H