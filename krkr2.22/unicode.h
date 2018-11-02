/*
This file was generated by the following command:

/home/ben/software/install/bin/cfunctions unicode.c

*/
#ifndef CFH_UNICODE_H
#define CFH_UNICODE_H

#include <stdint.h>

/*   _     _           _ _       
    | |   (_)_ __ ___ (_) |_ ___ 
    | |   | | '_ ` _ \| | __/ __|
    | |___| | | | | | | | |_\__ \
    |_____|_|_| |_| |_|_|\__|___/ */
                             


/* The maximum number of bytes we need to contain any Unicode code
   point as UTF-8 as a C string. This length includes one trailing nul
   byte. */

#define UTF8_MAX_LENGTH 5

/* The maximum possible value of a Unicode code point. See
   http://www.cl.cam.ac.uk/~mgk25/unicode.html#ucs. */

#define UNICODE_MAXIMUM 0x10ffff

/* The maximum possible value which will fit into four bytes of
   UTF-8. This is larger than UNICODE_MAXIMUM. */

#define UNICODE_UTF8_4 0x1fffff

/*   ____      _                                 _                 
    |  _ \ ___| |_ _   _ _ __ _ __   __   ____ _| |_   _  ___  ___ 
    | |_) / _ \ __| | | | '__| '_ \  \ \ / / _` | | | | |/ _ \/ __|
    |  _ <  __/ |_| |_| | |  | | | |  \ V / (_| | | |_| |  __/\__ \
    |_| \_\___|\__|\__,_|_|  |_| |_|   \_/ \__,_|_|\__,_|\___||___/ */
                                                               

/* All of the functions in this library return an "int32_t". Negative
   values are used to indicate errors. */

/* This return value indicates the successful completion of a routine
   which doesn't use the return value to communicate data back to the
   caller. */

#define UNICODE_OK 0

/* This return value means that the leading byte of a UTF-8 sequence
   was not valid. */

#define UTF8_BAD_LEADING_BYTE -1

/* This return value means the caller attempted to turn a code point
   for a surrogate pair into UTF-8. */

#define UNICODE_SURROGATE_PAIR -2

/* This return value means that code points which did not form a
   surrogate pair were tried to be converted into a code point as if
   they were a surrogate pair. */

#define UNICODE_NOT_SURROGATE_PAIR -3

/* This return value means that input which was supposed to be UTF-8
   encoded contained an invalid continuation byte. If the leading byte
   of a UTF-8 sequence is not valid, UTF8_BAD_LEADING_BYTE is returned
   instead of this. */

#define UTF8_BAD_CONTINUATION_BYTE -4

/* This return value indicates a zero byte was found in a string which
   was supposed to contain UTF-8 bytes. It is returned only by the
   functions which are documented as not allowing zero bytes. */

#define UNICODE_EMPTY_INPUT -5

/* This return value indicates that UTF-8 bytes were not in the
   shortest possible form. See
   http://www.cl.cam.ac.uk/~mgk25/unicode.html#utf-8. */

#define UTF8_NON_SHORTEST -6

/* This return value indicates that there was an attempt to convert a
   code point which was greater than UNICODE_MAXIMUM or UNICODE_UTF8_4
   into UTF-8 bytes. */

#define UNICODE_TOO_BIG -7

/* This return value indicates that the Unicode code-point ended with
   either 0xFFFF or 0xFFFE, meaning it cannot be used as a character
   code point. */

#define UNICODE_NOT_CHARACTER -8

/* This return value indicates that the UTF-8 is valid. */

#define UTF8_VALID 1

/* This return value indicates that the UTF-8 is not valid. */

#define UTF8_INVALID 0

int32_t utf8_bytes (uint8_t c);
int32_t utf8_no_checks (const uint8_t* input, const uint8_t** end_ptr);
int32_t utf8_to_ucs2 (const uint8_t* input, const uint8_t** end_ptr);
int32_t ucs2_to_utf8 (int32_t ucs2, uint8_t* utf8);
int32_t unicode_to_surrogates (int32_t unicode, int32_t* hi_ptr, int32_t* lo_ptr);
int32_t surrogates_to_unicode (int32_t hi, int32_t lo);
int32_t surrogate_to_utf8 (int32_t hi, int32_t lo, uint8_t* utf8);
int32_t unicode_chars_to_bytes (const uint8_t* utf8, int32_t n_chars);
int32_t unicode_count_chars_fast (const uint8_t* utf8);
int32_t unicode_count_chars (const uint8_t* utf8);

int32_t valid_utf8 (const uint8_t* input, int32_t input_length);
int32_t trim_to_utf8_start (uint8_t** ptr);
const char* unicode_code_to_error (int32_t code);

#endif /* CFH_UNICODE_H */
