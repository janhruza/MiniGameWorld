//
// Created by jan on 22/03/2026.
//

/*
 * Debug.h
 * Custom debug header file with various useful methods.
 */

#ifndef MOTOGP_DEBUG_H
#define MOTOGP_DEBUG_H
#include <stdio.h>
#include <stdarg.h>

static FILE *debug_fd = NULL;

/**
 * @brief Opens the debug file stream.
 * @return Operation result - 0: Success, EOF: Error.
 */
int debug_open(void) {
    debug_fd = fopen("debug.log", "a");
    return debug_fd == NULL ? EOF : 0;
}

/**
 * @brief Closes the debug file stream.
 * @return Operation result - 0: Success, EOF: Error.
 */
int debug_close(void) {
    if (debug_fd == NULL) {
        return EOF;
    }

    fclose(debug_fd);
    debug_fd = NULL;
    return 0;
}

/**
 * @brief Prints a message to the opened debug file.
 * @param fmt Formatted message.
 * @param ... Optional format arguments.
 * @return Result of the vfprintf method or EOF (-1) if an error has occurred.
 * @details EOF is returned when the debug_fd is NULL. Make sure the debug_fd is open before calling.
 */
int debug_print(const char *fmt, ...) {
    if (debug_fd == NULL) {
        return EOF;
    }

    va_list ap;
    va_start(ap, fmt);
    int result = vfprintf(debug_fd, fmt, ap);
    va_end(ap);
    fflush(debug_fd);
    return result;
}

#endif //MOTOGP_DEBUG_H