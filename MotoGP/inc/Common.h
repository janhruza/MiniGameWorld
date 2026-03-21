//
// Created by jan on 21/03/2026.
//

#ifndef MOTOGP_COMMON_H
#define MOTOGP_COMMON_H

#define AUTHOR          "@jendahruza"
#define PRODUCT_NAME    "MotoGP '26"
#define DRIVER_COUNT    22

#define TEXT_LENGTH     33

typedef enum : int {
    STATUS_OK,              // Success code.
    STATUS_ERROR,           // Error code.
    STATUS_UNINITIALIZED    // Error, object not initialized.
} STATUS;

/**
 * @brief Displays the program banner.
 * @return Always STATUS_OK.
 */
STATUS CoDrawBanner(void);

#endif //MOTOGP_COMMON_H