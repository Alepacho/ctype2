/* ctype2 - v0.1 - a small header-only extension of ctype.h

LICENSE: see end of file. (TL;DR it's MIT)

USAGE: To use this library, 
do this in *one* C or C++ file:
    #define CTYPE2_IMPLEMENTATION
    #include "ctype2.h"


To make the implementation private to the 
file that generates the implementation,
    #define CTYPE2_STATIC

Credits:
    Written by Alepacho (2023)
*/
// #ifndef CTYPE2_H
#define CTYPE2_H

#include <ctype.h>
#include <string.h>

#ifndef __cplusplus
#include <stdbool.h>
#else
extern "C" {
#endif // __cplusplus

#ifndef CT2DEF
#ifdef CTYPE2_STATIC
#define CT2DEF static
#else
#define CT2DEF extern
#endif // CTYPE2_STATIC
#endif // CT2DEF

CT2DEF int isinteger(char* str);
CT2DEF int isdouble(char* str);
CT2DEF int isbool(char* str);
CT2DEF int isdigitE0(char ch);
CT2DEF int isidentifier(char* str);
CT2DEF int ishex(char* str);

// #define CTYPE2_IMPLEMENTATION
#ifdef CTYPE2_IMPLEMENTATION

// str[11] : 0 | (+-)? [1-9]* {10}
CT2DEF int isinteger(char* str) {
    char* ch = str; int i = 0;
    if (*ch == '+' || *ch == '-') ch++;
    if (!isdigit(*ch)) return 0;
    if (*ch == '0') {
        if (strnlen(ch, 10) == 1) return 1;
        while (*ch++ == '0') return 0;
    }
    while (*ch != '\0') {
        if (!isdigit(*ch)) return 0;
        ch++; i++;
        if (i > 10) return 0;
    }
    return 1;
}

// str[23] : 
CT2DEF int isdouble(char* str) {
    return 0;
}

// lower(true | false)
CT2DEF int isbool(char* str) {
    char buf[5+1]; strncpy(buf, str, 5); buf[5] = '\0';
    char* ch = buf;
    while (*ch != '\0') { *ch = tolower(*ch); ch++; }
    if (strncmp(buf, "true" , 4) == 0) return 1;
    if (strncmp(buf, "false", 5) == 0) return 1;
    return 0;
}

// same as isdigit (0..9) except no zero
CT2DEF int isdigitE0(char ch) {
    return (ch >= '1' && ch <= '9');
}

// [_a-zA-Z][_a-zA-Z0-9]* {INT_MAX}
CT2DEF int isidentifier(char* str) {
    char* ch = str;
    if (*ch != '_' && !isalpha(*ch)) return 0;
    ch++;
    while (*ch != '\0') {
        if (*ch != '_' && !isalnum(*ch)) return 0;
        ch++;
    }
    return 1;
}

CT2DEF int ishex(char* str) {
    return 0;
}

#endif // CTYPE2_IMPLEMENTATION

#ifdef __cplusplus
} // extern "C"
#endif
// #endif // CTYPE2_H

/*
MIT License 

Copyright (c) 2023 Alepacho

Permission is hereby granted, free of charge, to any person obtaining a copy of 
this software and associated documentation files (the "Software"), to deal in 
the Software without restriction, including without limitation the rights to 
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all 
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER 
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN 
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
