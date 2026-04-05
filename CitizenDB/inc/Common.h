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

/**
* @brief Representing the array of all country codes.
*/
extern char gCountries[COUNTRIES_COUNT][COUNTRY_CODE_LEN];

/**
* @brief Draws the banner to the screen.
*/
void CoDrawBanner(void);

/**
* @brief Pauses the program execution until a key is pressed.
*/
void CoPause(void);

/**
 * @brief Clears the input buffer.
 */
void CoClearBuffer(void);

/**
* @brief Reads a string from the user and clears the input buffer.
* @param buf Output buffer.
* @param n Maximum length of the string including the null terminator.
* @param stream Target stream to read from.
* @returns The length of the read string, excluding the null terminator.
*/
int CoReadString(char* buf, int n, FILE *stream);

/**
* @brief Reads an integer from the stdin and stores it in the buf.
* @param buf Output buffer.
* @returns Operation result. The read integer is stored in the buf.
*/
int CoReadInt(int* buf);

/**
* @brief Sets the terminal emulator's window title using the ANSI escape sequence.
* @param text New requested window title.
*/
void CoSetConsoleTitle(char* text);

/**
 * @brief Prompts user to perform yes/no choice.
 * @param text Confirmation text. Use NULL to use the default text.
 * @return Operation result: 1 - yes, 0 - no.
 */
int CoChoice(char *text);

#endif //CITIZENDB_COMMON_H