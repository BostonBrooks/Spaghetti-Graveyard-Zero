/**
 * @file
 * @brief This header file contains definitions of some wrappers to printf functions.
 * Functions are defined statically and depend on defined macros,
 * So they can be switched on and off on a per-file basis
 *
*/

#ifndef BBPRINTF_H
#define BBPRINTF_H

#include <stdio.h>
#include <stdarg.h>

/**
 * This function calls printf if BBDEBUG is defined in the file this header is included in
 * @author Boston Brooks
 * @param format printf format string
 * @param ... printf args
 * @date 20/2/2024
 */
static void bbDebug(const char* format, ...){

#ifdef BBDEBUG

	printf("DEBUG: ");
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end (args);

#endif

} // BBDEBUG

/**
 * This function calls printf if BBVERBOSE is defined in the file this header is included in
 */
static void bbVerbose(const char* format, ...){

#ifdef BBVERBOSE

	printf("VERBOSE: ");
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end (args);

#endif // BBVERBOSE

}

#endif // BBPRINTF_H
